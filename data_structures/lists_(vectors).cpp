/*
    The following is an implementation of Dynamic arrays with various methods. We'll make use of pointers and dynamic memory allocation
*/

#include <iostream>
using namespace std;

class List {
    int* elements;
    int capacity = 10;
    int size;
    void resize(int capac);

    public:

        // Declaring constructor and destroyer: 

        List(int cap = 5){
            this->capacity = cap;
            this->elements = new int[capacity]; 
            this->size = 0;
        } // constructor, can be used for default capacity or sending a capacity by argument

        ~List(){
            delete[]this->elements;
        }; // destructor

//-------------------------------------//

        bool insert(int e, int pos);
        bool deleter(int pos);
        void push_start(int e);
        void push_end(int e);
        int* get_pos(int pos); // function that returns the memory address of this element in that position

        int get_capacity(){
            return this->capacity; 
        }
};

/*
To-be implemented:
    - resize
    - insert
    - deleter
    - push_start
    - push_end
    - get_pos

*/ 




int main(){

    List l(10);

    cout << "capacity: " << l.get_capacity();

    return 0;
}