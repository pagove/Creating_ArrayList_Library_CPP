#include <iostream>
using namespace std;

// Definición de la clase con plantilla
template <typename T>
class Node {
    public:
        T* previous;
        T* next;
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

        ArrayList(): size(0), head(nullptr){};

        bool add(T val){
            Node<T>* newNode = new Node<T>();
            newNode->value = val;
            if(size == 0){
                head = newNode;
            }
            size++;
            return true;
        }

        string print() {
            string ret = "";
            ret += to_string(head->print());
            return ret;
        }



    private:
        int size;
        Node<T>* head;
};

int main() {

   ArrayList<int> v;
   v.add(2);
   cout << "Imprimiendo " << v.print() << endl;

    return 0;
}
