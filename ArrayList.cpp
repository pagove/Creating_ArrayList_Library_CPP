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

        void add(T val){
            Node<T>* newNode = new Node<T>();
            newNode->value = val;
            if(_size == 0){
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            _size++;
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

        int size(){
            return _size;
        }

        T getAt(int pos){
            Node<T>* current = head;
            for(int i = 0; i <= _size; i++){
                cout << "ENTRA" << endl;
                if(i == pos){
                    return current->value;
                } else {
                    current = current->next;
                }
            }
            return false;
        }



    private:
        int _size;
        Node<T>* head;
        Node<T>* tail;
};

int main() {

   ArrayList<int> v;
   for(int i = 10; i < 20; i++){
       v.add(i);
    }


   cout << "Tam " << v.size() << endl;
   cout << "getAt() " << v.getAt(-1) << endl;
   cout << "Imprimiendo " << v.print() << endl;

    return 0;
}
