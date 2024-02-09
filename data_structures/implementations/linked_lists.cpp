/*
    Linked lists resemble dynamic arrays, but they're different in the sense that elements aren't positions in an array, instead they're known as nodes, and each node has a value (payload) and a reference to the next node (a pointer).

    Also this data structure will make use of template based programming
*/

#include <iostream>

using namespace std;

template <class T> 
class Node{
    public:
    T payload;
    Node <T> *next; // the pointer to the next node. We'll store the memory address here
    
    Node(T data) {
        payload = data;
        next = nullptr;
    }
}; // defining Node as template, where the data type we use to instantiate it will be of type T

// template <class T> 
// Node<T> *position; //we create a data type of 'Node' but with the caveat that this variable will be a pointer to a Node object

template <class T> 
class List{
    private:
        Node<T>* _first;
        Node<T>* _last;
        int _size;
    // this parameters are private and two are the type of Node

    public:
        List(){
            this->_first = nullptr;
            this->_last = nullptr;
            this->_size = 0;
        } // creating the list with a null pointer for first and last pointers. It's an empty list

    ~List(){
        Node<T>* p = first();
        while(p != last()){
            Node<T>* a = p;
            next(p);
            delete a;
        }
        _size = 0;
    } //the destructor method will erase each node from the list iterating through each of them.

    Node<T>* first(){
        return this->_first;
    }   //returns a pointer to the first node on the list
    
    Node<T>* last(){
        return this->_last;
    }   //returns a pointer to the last node on the list. ALWAYS is set to NULL

    void next(Node<T>* &p) {
        if (p != nullptr) {
            p = p->next;
        } else {
            p = nullptr; // Establecer p en nullptr si ya está al final de la lista
        }
    }   //moving 'p' to the next node on the list

    T* get_payload(Node<T>* p){
        if(p == nullptr){
            return nullptr;
        }
        return &(p->payload);
    }   //returns the value of the node we're on

    int size(){
        return _size;
    }

    bool isEmpty(){
        return _size == 0;
    }

    void insert(T x, Node<T>* p, bool before = true){
        Node<T>* newNode = new Node<T>(x); // creating a new pointed node 
        _size++;    // increasing its size
        
        if(isEmpty()){  
            this->_first = newNode;
            this->_last = newNode;
            return;
        } // if the list is empty, first and last point to the same node
        
        if(before){ //when we want to insert before a specific node
            newNode->next = p;  // the next node of the newNode will be the pointer we send
           
            if(p != first()){ //when the sent pointer isn't the first
                Node<T>* i = first();   // taking the first node as a temporal node    
                while(i->next != p){    
                    next(i);    
                } // moving the temporal node accross the list
                i->next = newNode;  //now the previous node to the newNode points to it
            }
            
            if(p == first()){   
                newNode->next = first();
                this->_first = newNode;
            }   //the case when we want to insert before the first node
            return;
        } else {
            //if before == false
            newNode->next = p->next;    // the next node of newNode will be the next node of pointer p
            p->next = newNode;  // now the next of pointer p will be our newNode
        
            if(p == last()){
                this->_last = newNode;
            }
            return;
        }
         // pointing to the last new Node when pointer p is last
    }

    void deleteNode(Node<T>* i){
        if(i == nullptr) return;
        _size--;

        if(i == first()){
            _first = i->next;
        } // when the node to delete is the first one
        
        Node<T>* p = first();
        while(p->next != i){
            next(p);
        } //moving the pointer accross the list until it's next pointer matches i

        p->next = i->next; //moving the pointer of p to the same as the next of i

        if(i == last()){
            _last = p;
        } //when i is the same as last

        delete i;
    }
};

/*
    Methods to be implemented:
        - insert
        - delete
        - size
*/

int main(){


    List<int> l;
    cout << "l.size " << l.size() << endl;
    cout << "l.first() " << l.first() << endl;
    cout << "l.last() " << l.last() << endl;

    l.insert(3, l.first(), true);

    Node<int> *p = l.first();
    Node<int> *p_2 = l.last();
    cout << "p->payload " << p->payload << endl;
    cout << "p->next " << p->next << endl;
    cout << "p_2->payload " << p_2->payload << endl;
    cout << "p_2->next " << p_2->next << endl;

    return 0;
}