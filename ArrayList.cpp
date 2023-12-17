#include <iostream>
using namespace std;

// Definición de la clase con plantilla
template <typename T>
class Node {
    public:
        Node<T>* previous;
        Node<T>* next;
        T value;
        //Constructor
        Node(): previous(nullptr), next(nullptr){};

        T print() {
            return value;
        }

    private:

};

template <typename T>
class ArrayList{
    public:

        ArrayList(): _size(0), head(nullptr), tail(nullptr){};

        /*ADD METHODS*/
        void add(T val){
            Node<T>* newNode = new Node<T>();
            newNode->value = val;
            if(_size == 0){
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->previous = tail;
                tail = newNode;
            }
            _size++;
        }

        void addAll(ArrayList<T> ar){
            Node<T>* current = ar.head;
            while(current){
                add(current->value);
                current = current->next;
            }
        }

        void set(int index, T val){
            if(index < _size && index >= 0){
                int med = _size / 2;
                Node<T>* current;
                if(index <= med){
                    current = head;
                    for(int i = 0; i < index; i++){
                        cout << current->value << endl;
                        current = current->next;
                    }
                } else {
                    current = tail;
                    for(int i = _size -1; i > index; i--){
                        cout << current->value << endl;
                        current = current->previous;
                    }
                }
                current->value = val;
            }
        }


        /* REMOVE METHODS*/

        void remove(T val){
            Node<T>* current = head;
            bool found = false;
            int pos = -1;
            while(current && !found ){
                pos++;
                if(current->value == val){
                    found=true;
                } else {
                    current = current->next;
                }
            }
            if(found){
                if(pos == 0){
                    head = current->next;
                    head->previous = nullptr;
                } else if(pos == (_size -1)){
                    tail = current->previous;
                    tail->next = nullptr;
                } else {
                    current->previous->next = current->next;
                    current->next->previous = current->previous;
                }
                delete current;
            }
        }

        void removeAll(T val){}

        void removeAt(int index){

        }

        void clear(){
            Node<T>* current = head;
            while(current){
                current = current->next;
                delete current->previous;
            }
        }

        /* ACCES METHODS*/
        T getAt(int pos){
            int med = _size / 2;
            Node<T>* current;
            if(pos <= med){
                 current = head;
                for(int i = 0; i < pos; i++){
                    current = current->next;
                }
                return current->value;
            } else {
                current = tail;
                for(int i = _size -1; i > pos; i--){
                    current = current->previous;
                }
                return current->value;
            }
            return false;
        }

        int indexOf(T val){
            int index = -1;
            Node<T>* current = head;
            bool found = false;
            while(current && !found){
                index++;
                if(current->value == val){
                    found = true;
                }
                current = current->next;
            }
            if(found){
                return index;
            } else {
                return -1;
            }
        }

        bool contains(T val){
            Node<T>* current  = head;
            bool found = false;
            while(current && !found){
                if(current->value == val) {
                    found = true;
                }
                current = current->next;
            }

            return found;
        }

        int size(){
            return _size;
        }
        bool isEmpty(){
            return _size == 0;
        }

        string print() {
            string ret = "";
            Node<T>* current = head;
            while(current){
                if(current->next != nullptr){
                    ret += to_string(current->print()) + "-";
                } else {
                    ret += to_string(current->print());
                }
                current = current->next;
            }
            return ret;
        }

        ArrayList<T> subList(int fromIndex, int toIndex){

        }


    private:
        int _size;
        Node<T>* head;
        Node<T>* tail;
};

int main() {

   ArrayList<int> v;
   for(int i = 10; i < 15; i++){
       v.add(i);
    }
    cout << "Imprimiendo " << v.print() << endl;
    cout << v.contains(17) << endl;
    cout << v.indexOf(15) << endl;
    cout << "Imprimiendo " << v.print() << endl;

    /*
    cout << "Imprimiendo " << v.print() << endl;
    cout << "GetAt 0 " << v.getAt(0) << endl;
    cout << "GetAt 1 " << v.getAt(1) << endl;
    cout << "GetAt 2 " << v.getAt(2) << endl;
    cout << "GetAt 3 " << v.getAt(3) << endl;
    cout << "GetAt 4 " << v.getAt(4) << endl;

   cout << "Tam " << v.size() << endl;
   cout << "getAt() " << v.getAt(2) << endl;
   cout << "Imprimiendo " << v.print() << endl;
*/
    return 0;
}
