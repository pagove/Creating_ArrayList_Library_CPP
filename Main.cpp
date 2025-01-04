#include <iostream>
#include "ArrayList.cpp"

using namespace std;

void clearTerminal();
void pause();
void howToUse();
int menu();
void optionsMenu(int &showArray, int &clearTerm);
int saveDisplayArray();
int clearTerm();

void add(ArrayList<int> &v);
void addAll(ArrayList<int> &v);
void printAr(ArrayList<int> &v);
void setValue(ArrayList<int> &v);
void removeFirst(ArrayList<int> &v);
void remove(ArrayList<int> &v);
void removeAt(ArrayList<int> &v);
void clear(ArrayList<int> &v);
void getAt(ArrayList<int> &v);
void contains(ArrayList<int> &v);
void size(ArrayList<int> &v);

int main()
{

	int option = -1;
	int showArray = 0;
	int clearTerm = 0;
	ArrayList<int> v;

	while (option != 0)
	{
		option = menu();

		switch (option)
		{
		case 0:
			exit(0);
			break;
		case 1:
			add(v);
			break;
		case 2:
			addAll(v);
			break;
		case 3:
			setValue(v);
			break;
		case 4:
			removeFirst(v);
			break;
		case 5:
			remove(v);
			break;
		case 6:
			removeAt(v);
			break;
		case 7:
			clear(v);
			break;
		case 8:
			getAt(v);
			break;
		case 9:
			contains(v);
			break;
		case 10:
			size(v);
			break;
		case 11:
			break;
		case 14:
			printAr(v);
			break;
		case 15:
			howToUse();
			break;
		case 16:
			clearTerminal();
			break;
		case 17:
			optionsMenu(showArray, clearTerm);
			break;
		}

		if (option != 16)
		{
			if (showArray == 1 && option != 14 && option != 17)
			{
				printAr(v);
			}
			pause();
			if (clearTerm == 1)
			{
				clearTerminal();
			}
		}
	}

	return 0;
}

void clearTerminal()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void pause()
{
	char c;
	cout << " Press 'C' to continue" << endl;
	cin >> c;
}

int menu()
{
	int option = -1;
	while (option < 0 || option > 17)
	{
		cout << "=============================================" << endl;
		cout << "                  MENU " << endl;
		cout << "=============================================" << endl;
		cout << " 0.-  Exit. " << endl;
		cout << " 1.-  Add number to vector. " << endl;
		cout << " 2.-  Add another array to C array. " << endl;
		cout << " 3.-  Set value. " << endl;
		cout << " 4.-  Remove first value. " << endl;
		cout << " 5.-  Remove all occurrences. " << endl;
		cout << " 6.-  Remove at. " << endl;
		cout << " 7.-  Clear. " << endl;
		cout << " 8.-  getAt. " << endl;
		cout << " 9.-  contains. " << endl;
		cout << " 10.- Size. " << endl;
		cout << " 11.- isEmpty.	" << endl;
		cout << " 12.- subList " << endl;
		cout << " 13.- indexOf " << endl;
		cout << " 14.- print " << endl;
		cout << " 15.- How to use " << endl;
		cout << " 16.- Clear screen" << endl;
		cout << " 17.- Option" << endl;
		cout << "============================================" << endl;

		cin >> option;

		if (option < 0 || option > 17)
		{
			clearTerminal();
		}
	}

	return option;
}

void optionsMenu(int &showArray, int &clearScreen)
{
	clearTerminal();
	int option = -1;
	cout << option << endl;
	while (option < 0 || option > 2)
	{
		cout << "=============================================" << endl;
		cout << "             OPTIONS MENU " << endl;
		cout << "=============================================" << endl;
		cout << " 0.-  Return to main menu. " << endl;
		cout << " 1.-  Show array after each action. " << endl;
		cout << " 2.-  Clear terminal after each action" << endl;
		cout << "============================================" << endl;

		cin >> option;

		switch (option)
		{
		case 1:
			showArray = saveDisplayArray();
			break;
		case 2:
			clearScreen = clearTerm();
			break;
		default:
			break;
		}
	}
}

int saveDisplayArray()
{
	int val = 0;
	cout << "Insert 1 to see the main array after each action " << endl;
	cin >> val;
	return val;
}

int clearTerm()
{
	int val = 0;
	cout << "Insert 1 to clear the screen after each action " << endl;
	cin >> val;
	return val;
}

void howToUse()
{
	cout << "1.-   Add number to the main array. Add(T value). " << endl;
	cout << "2.-   Add another array to the main array. Add(ArrayList<T> ar). " << endl;
	cout << "3.-   Set a number in the indicated position, like edit value. set(int index, T value). " << endl;
	cout << "4.-   Remove the first occurrence. remove(T value). " << endl;
	cout << "5.-   Remove all occurrences. removeAll(T value). " << endl;
	cout << "6.-   Remove value. removeAt(int index). " << endl;
	cout << "7.-   Remove all values. clear(). " << endl;
	cout << "8.-   Print the value in the position. getAt(int pos). " << endl;
	cout << "9.-   true array contains that value. contains(T val)." << endl;
	cout << "10.- Print the length of the array. size()." << endl;
	cout << "11.- True is there isn't any value in the array. isEmpty()." << endl;
	cout << "12.- The array contained between two indexes. subList(int pos1, int pos2)." << endl;
	cout << "13.- Returns the first index of the value. indexOf(T val). " << endl;
	cout << "14.- Prints the array into screen. print()." << endl;
}

void add(ArrayList<int> &v)
{
	int val;
	cout << "Insert a numeric value" << endl;
	cin >> val;
	v.add(val);
}

void addAll(ArrayList<int> &v)
{
	string continuar = "S";
	ArrayList<int> _v;
	int aux;
	cout << "Creating an auxiliar array" << endl;
	while (continuar == "S")
	{
		cout << "Write a number: " << endl;
		cin >> aux;
		_v.add(aux);
		cout << "Continue (S) or not (N) " << endl;
		cin >> continuar;
	}

	v.addAll(_v);
}

void setValue(ArrayList<int> &v)
{
	int index, number;
	bool ok = true;
	cout << "Write the index of the array" << endl;
	cin >> index;
	if (index < 0)
	{
		cout << "Index could not be negative" << endl;
		ok = false;
	}
	if (index > (v.size() - 1))
	{
		cout << "Index out of size. The size is " << v.size() << endl;
		ok = false;
	}

	if (ok)
	{
		cout << "Insert a number to write in the position " << index << endl;
		cin >> number;
		v.set(index, number);
	}
}

void removeFirst(ArrayList<int> &v)
{
	if (v.size() > 0)
	{
		cout << "Removing first value..." << endl;
		v.removeAt(0);
	}
	else
	{
		cout << "You are trying to remove elements in an empty array " << endl;
	}
}

void remove(ArrayList<int> &v)
{
	int val;
	if (v.size() > 0)
	{
		cout << "Insert the value that you want to remove" << endl;
		cin >> val;
		v.remove(val);
	}
	else
	{
		cout << "You are trying to remove elements in an empty array " << endl;
	}
}

void removeAt(ArrayList<int> &v)
{
	int index;
	bool ok = true;
	cout << "Write the index of the array" << endl;
	cin >> index;
	if (index < 0)
	{
		cout << "Index could not be negative" << endl;
		ok = false;
	}
	if (index > (v.size() - 1))
	{
		cout << "Index out of size. The size is " << v.size() << endl;
		ok = false;
	}

	if (ok)
	{
		v.removeAt(index);
	}
}

void clear(ArrayList<int> &v)
{
	v.clear();
}

void getAt(ArrayList<int> &v)
{
	int index;
	bool ok = true;
	cout << "Write the index of the array" << endl;
	cin >> index;
	if (index < 0)
	{
		cout << "Index could not be negative" << endl;
		ok = false;
	}
	if (index > (v.size() - 1))
	{
		cout << "Index out of size. The size is " << v.size() << endl;
		ok = false;
	}

	if (ok)
	{
		cout << "The value is " << v.getAt(index) << endl;
	}
}

void contains(ArrayList<int> &v)
{
	int searched;
	cout << "Write the number that you want to search " << endl;
	cin >> searched;
	if (v.contains(searched))
	{
		cout << "The number " << searched << " is in the array " << endl;
	}
	else
	{
		cout << "The number " << searched << " isn't in the array " << endl;
	}
}

void size(ArrayList<int> &v)
{
	cout << v.size() << endl;
}

void printAr(ArrayList<int> &v)
{
	cout << "[" << v.toString() << "]" << endl;
}
