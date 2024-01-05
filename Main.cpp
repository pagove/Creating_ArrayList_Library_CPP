#include <iostream>
#include "ArrayList.cpp"

using namespace std;

void clearTerminal();
void pause();
void howToUse();
int menu();

void add(ArrayList<int> &v);
void printAr(ArrayList<int> &v);

int main() {

	int option = -1;
	ArrayList<int> v;
	
	while(option != 0){
		option = menu();
		switch(option){
			case 0:
				exit(0);
			break;
			case 1:
				add(v);
			break;
			case 14:
				printAr();
			break;
			case 15:
				howToUse();
			break;
			case 16:
				clearTerminal();
			break;
		}
		if(option != 16){
			pause();
		}
	}
	
    return 0;
}

void clearTerminal(){
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

void pause(){
	char c;
	cout << " Press 'C' to continue" << endl;
	cin >> c;
}

int menu(){
	int option = -1;
	while(option < 0 || option > 16){
		cout << "=============================================" << endl;
		cout << "                  MENU " << endl;
		cout << "=============================================" << endl;
		cout << " 0.-  Exit. " << endl;
		cout << " 1.-  Add number to vector. " << endl;
		cout << " 2.-  Add another array to main array. " << endl;
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
		cout << "============================================" << endl;
		
		cin >> option;
		
		if(option < 0 || option > 16){
			clearTerminal();
		}
	}
	
	return option;
}

void howToUse(){ 
	cout << "1.-   Add number to the main array. Add(T value). " << endl;
	cout << "2.-   Add another array to the main array. Add(ArrayList<T> ar). " << endl;
	cout << "3.-   Set a number in the indicated position. set(int index, T value). " << endl;
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

void add(ArrayList<int> &v){
	int val;
	cout << "Insert a numeric value" << endl;
	cin >> val;
	v.add(val);
}

void printAr(ArrayList<int> &v){
	cout << "[" << v.print() << "]" << endl;	
}