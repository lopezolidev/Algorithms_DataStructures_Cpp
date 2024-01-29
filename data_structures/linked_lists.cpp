/*
    Linked lists resemble dynamic arrays, but they're different in the sense that elements aren't positions in an array, instead they're known as nodes, and each node has a value (payload) and a reference to the next node (a pointer).

    Also this data structure will make use of template based programming
*/

#include <iostream>

using namespace std;

template <class T> 

class Node{
    T payload;
    Node <T> *next; // the pointer to the next node. We'll store the memory address here
}; // defining Node as template, where the data type we use to instantiate it will be of type T

template <class T> 
Node<T> *position; //we create a data type of 'Node' but with the caveat that this variable will be a pointer to a Node object

template <class T> 
class List{
    private:
        position _first;
        position _last;
        int _size;
    // this parameters are private and two are the type of Node

    public:
        List(){
            _first = NULL;
            _last = NULL;
            _size = 0;
        } // creating the list with a null pointer for first and last pointers. It's an empty list

    ~List(){
        position p = first();
        while(p != last()){
            position a = p;
            next(p);
            delete a;
        }
        _size = 0;
    } //the destructor method will erase each node from the list iterating through each of them.

    position first(){
        return _first;
    }   //returns a pointer to the first node on the list
    
    position last(){
        return _last;
    }   //returns a pointer to the last node on the list. ALWAYS is set to NULL

    void next(position &p){
        if(p != NULL){
            p = p->next;
        } 
    }//moving 'p' to the next node on the list

    *T get_payload(position p){
        if(p == last()){
            return last();
        }
        return &p->payload;
    }   //returns the value of the node we're on

    int size(){
        return _size;
    }
};

/*
    Methods to be implemented:
        - insert
        - delete
        - size
*/

int main(){

    return 0;
}