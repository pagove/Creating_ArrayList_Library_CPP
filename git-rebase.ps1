param (
    [string]$RepoPath
)

if (-not $RepoPath) {
	$RepoPath = $PSScriptRoot
    Write-Host "No se proporcionó una ruta de repositorio. Usando el directorio actual: $RepoPath" -ForegroundColor Cyan
}

if (-not (Test-Path $RepoPath)) {
    Write-Host "Error: La ruta especificada no existe: $RepoPath" -ForegroundColor Red
    exit 1
}

# Verificar si Git está en el PATH
if (-not (Get-Command git -ErrorAction SilentlyContinue)) {
    Write-Host "Error: Git no está disponible en el entorno de este script." -ForegroundColor Red
    exit 1
}


Set-Location -Path $RepoPath
Write-Host "Navegando al directorio: $RepoPath" -ForegroundColor Green

function Run-GitCommand {
    param (
        [string]$Command
    )
    Write-Host "Ejecutando: git $Command" -ForegroundColor Yellow
    $Result = & git $Command 2>&1
	Write-Host $LASTEXITCODE -ForegroundColor DarkRed
    if ($LASTEXITCODE -ne 0) {
        Write-Host "Error ejecutando: git $Command" -ForegroundColor Red
        Write-Host $Result
        exit $LASTEXITCODE
    }
    Write-Host $Result -ForegroundColor Green
    return $Result
}

Write-Host "Verificando cambios en el repositorio remoto..." -ForegroundColor Cyan
Run-GitCommand "fetch"

# Obtener los hashes de las ramas local, remota y su base común
$Local = Run-GitCommand "rev-parse HEAD"
$Remote = Run-GitCommand "rev-parse '@{u}'"
$Base = Run-GitCommand "merge-base HEAD '@{u}'"

# Comparar los hashes para determinar el estado del repositorio
if ($Local -eq $Remote) {
    Write-Host "La rama local ya está actualizada con la rama remota. No se requiere rebase." -ForegroundColor Green
    exit 0
} elseif ($Local -eq $Base) {
    Write-Host "La rama local está desactualizada. Se procederá con el rebase." -ForegroundColor Cyan
} elseif ($Remote -eq $Base) {
    Write-Host "Tienes cambios locales que aún no se han enviado. Considera hacer un push antes." -ForegroundColor Yellow
    exit 1
} else {
    Write-Host "Conflictos detectados entre la rama local y remota. El rebase puede requerir intervención." -ForegroundColor Red
}

# Crear un stash si hay cambios locales
$StashOutput = Run-GitCommand "stash push -m 'RebaseProcess'"
$HasStash = $StashOutput -notlike "*No local changes to save*"

if ($HasStash) {
    $CreatedStash = Run-GitCommand "stash list" | Select-String -Pattern "RebaseProcess" | ForEach-Object { $_.Line.Split(" ")[0] }
    Write-Host "Se creó un stash temporal: $CreatedStash" -ForegroundColor Cyan
} else {
    Write-Host "No hay cambios locales que guardar. Continuando sin stash." -ForegroundColor Green
}

# Realizar el rebase
$RemoteBranch = Run-GitCommand "rev-parse --abbrev-ref --symbolic-full-name @{u}"
if (-not $RemoteBranch) {
    Write-Host "Error: No se encontró un seguimiento remoto para la rama actual." -ForegroundColor Red
    exit 1
}

Write-Host "Rebasing la rama actual sobre $RemoteBranch..." -ForegroundColor Cyan
Run-GitCommand "rebase $RemoteBranch"

# Reaplicar y eliminar el stash si se creó uno
if ($HasStash) {
    if ($CreatedStash) {
        Write-Host "Reaplicando el stash creado: $CreatedStash" -ForegroundColor Cyan
        Run-GitCommand "stash apply $CreatedStash"

        Write-Host "Eliminando el stash temporal: $CreatedStash" -ForegroundColor Cyan
        Run-GitCommand "stash drop $CreatedStash"
    } else {
        Write-Host "Error: No se encontró el stash creado por este proceso." -ForegroundColor Red
    }
}

# Mostrar los últimos 5 commits
Write-Host "Mostrando los últimos 5 commits..." -ForegroundColor Cyan
Run-GitCommand "log --graph --oneline --all -n5"

Write-Host "Rebase completado correctamente." -ForegroundColor Green
