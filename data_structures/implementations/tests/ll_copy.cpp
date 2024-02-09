#include <iostream>

using namespace std;

template <class T>
class Node {
public:
    T payload;
    Node<T> *next;

    Node(T data) {
        payload = data;
        next = nullptr;
    }
};

template <class T>
class List {
private:
    Node<T> *_first;
    Node<T> *_last;
    int _size;

public:
    List() {
        this->_first = nullptr;
        this->_last = nullptr;
        this->_size = 0;
    }

    ~List() {
        Node<T> *p = first();
        while (p != last()) {
            Node<T> *a = p;
            next(p);
            delete a;
        }
        _size = 0;
    }

    Node<T> *first() {
        return this->_first;
    }

    Node<T> *last() {
        return this->_last;
    }

    void next(Node<T> *&p) {
        if (p != nullptr) {
            p = p->next;
        }
    }

    T *get_payload(Node<T> *p) {
        if (p == nullptr) {
            return nullptr;
        }
        return &(p->payload);
    }

    int size() {
        return _size;
    }

    bool isEmpty() {
        return (_size == 0);
    }

    void insert(T x, Node<T> *p, bool before) {
        Node<T>* newNode = new Node<T>(x);

        if (isEmpty()) {
            _first = _last = newNode;
            _size++;
            return;
        }

        if (before) {
            newNode->next = p;

            if (p != this->_first) {
                Node<T> *i = this->_first;
                while (i->next != p) {
                    next(i);
                }
                i->next = newNode;
            }

            if (p == this->_first) {
                newNode->next = this->_first;
                _first = newNode;
            }
        } else {
            newNode->next = p->next;
            p->next = newNode;

            if (p == this->_last) {
                _last = newNode;
                if(_last == newNode){
                    cout << "Last is the newNode" << endl;
                }
            }
        }
        _size++;
    }

    void deleteNode(Node<T> *i) {
        if (i == nullptr)
            return;
        _size--;

        if (i == first()) {
            _first = i->next;
        } 

        Node<T> *p = first();
        while (p->next != i) {
            next(p);
        } 

        p->next = i->next;

        if (i == last()) {
            _last = p;
        }

        delete i;
    }
};

int main() {

    List<int> l;
    cout << "List size: " << l.size() << endl;
    cout << "First node: " << l.first() << endl;
    cout << "Last node: " << l.last() << endl;



    l.insert(3, l.first(), true);

    Node<int> *p = l.first();
    Node<int> *p_2 = l.last();



    return 0;
}
