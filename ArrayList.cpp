#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
    Node<T> *previous;
    Node<T> *next;
    T value;
    // Constructor
    Node() : previous(nullptr), next(nullptr) {};

    T print()
    {
        return value;
    }

private:
};

template <typename T>
class ArrayList
{
public:
    ArrayList() : _size(0), head(nullptr), tail(nullptr) {};

    /*ADD METHODS*/
    void add(T val)
    {
        Node<T> *newNode = new Node<T>();
        newNode->value = val;
        if (_size == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
        _size++;
    }

    void addAll(ArrayList<T> ar)
    {
        Node<T> *current = ar.head;
        while (current)
        {
            add(current->value);
            current = current->next;
        }
    }

    void set(int index, T val)
    {
        if (index < _size && index >= 0)
        {
            int med = _size / 2;
            Node<T> *current;
            if (index <= med)
            {
                current = head;
                for (int i = 0; i < index; i++)
                {
                    cout << current->value << endl;
                    current = current->next;
                }
            }
            else
            {
                current = tail;
                for (int i = _size - 1; i > index; i--)
                {
                    cout << current->value << endl;
                    current = current->previous;
                }
            }
            current->value = val;
        }
    }

    /* REMOVE METHODS*/

    void remove(T val)
    {
        Node<T> *current = head;
        bool found = false;
        int pos = -1;
        while (current && !found)
        {
            pos++;
            if (current->value == val)
            {
                found = true;
            }
            else
            {
                current = current->next;
            }
        }
        if (found)
        {
            if (pos == 0)
            {
                head = current->next;
                head->previous = nullptr;
            }
            else if (pos == (_size - 1))
            {
                tail = current->previous;
                tail->next = nullptr;
            }
            else
            {
                current->previous->next = current->next;
                current->next->previous = current->previous;
            }
            delete current;
        }
        _size--;
    }

    void removeAll(T val)
    {
        Node<T> *current = head;
        int pos = -1;
        while (current)
        {
            pos++;
            if (current->value == val)
            {
                Node<T> *nextNode = current;
                if (pos == 0)
                {
                    head = current->next;
                }
                else if (pos == _size - 1)
                {
                    tail = current->previous;
                }
                delete current;
                current = nextNode;
                _size--;
            }
        }
    }

    void removeAt(int index)
    {
        int cont = 0;
        Node<T> *current = head;
        if (index == 0)
        {
            head = current->next;
            head->previous = nullptr;
            delete current;
        }
        else if (index == (_size - 1))
        {
            current = tail;
            tail = current->previous;
            tail->next = nullptr;
            delete current;
        }
        else
        {
            while (current->next)
            {
                if (cont == index)
                {
                    current->previous->next = current->next;
                    current->next->previous = current->previous;
                    delete (current);
                    break;
                }
                current = current->next;
                cont++;
            }
        }
        _size--;
    }

    void clear()
    {
        Node<T> *current = head;
        while (current)
        {
            Node<T> *nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = tail = nullptr;
        _size = 0;
    }

    /* ACCES METHODS*/
    T getAt(int pos)
    {
        int med = _size / 2;
        Node<T> *current;
        if (pos <= med)
        {
            current = head;
            for (int i = 0; i < pos; i++)
            {
                current = current->next;
            }
            return current->value;
        }
        else
        {
            current = tail;
            for (int i = _size - 1; i > pos; i--)
            {
                current = current->previous;
            }
            return current->value;
        }
        return false;
    }

    int indexOf(T val)
    {
        int index = -1;
        Node<T> *current = head;
        bool found = false;
        while (current && !found)
        {
            index++;
            if (current->value == val)
            {
                found = true;
            }
            current = current->next;
        }
        if (found)
        {
            return index;
        }
        else
        {
            return -1;
        }
    }

    bool contains(T val)
    {
        Node<T> *current = head;
        bool found = false;
        while (current && !found)
        {
            if (current->value == val)
            {
                found = true;
            }
            current = current->next;
        }

        return found;
    }

    int size()
    {
        return _size;
    }
    bool isEmpty()
    {
        return _size == 0;
    }

    string toString()
    {
        string ret = "";
        Node<T> *current = head;
        while (current)
        {
            if (current->next != nullptr)
            {
                ret += to_string(current->print()) + "-";
            }
            else
            {
                ret += to_string(current->print());
            }
            current = current->next;
        }
        return ret;
    }

    ArrayList<T> subList(int fromIndex, int toIndex)
    {
        int cont = -1;
        ArrayList<T> rest;
        Node<T> *current = head;
        while (current->next && cont < toIndex)
        {
            cont++;
            if (cont >= fromIndex && cont <= toIndex)
            {
                rest.add(current->value);
            }
            current = current->next;
        }
        return rest;
    }

private:
    int _size;
    Node<T> *head;
    Node<T> *tail;
};
