/*
    The following is an implementation of Dynamic arrays with various methods. We'll make use of pointers and dynamic memory allocation
*/

#include <iostream>
using namespace std;

class List {
    int* elements;
    int capacity = 10;
    const int step = this->capacity / 2;
    int size;
    void resize(int capac);
    bool filler();

    public:

        // Declaring constructor and destroyer: 

        List(int cap = 5){
            this->capacity = cap;
            this->elements = new int[capacity]; 
            this->size = 0;
            this->filler();
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
        int get_length(){return this->size;} // returns how many elements we have in the array
};

/*
To-be implemented:
    - resize (done)
    - insert (done)
    - deleter (done)
    - push_start
    - push_end
    - get_pos (done)

*/ 

bool List::filler(){
    int i = 0;
    while(i < capacity){
        this->elements[i] = 0;
        i++;
    }

    return true;
}// fills with 0's every position in the list

void List::resize(int capacity){
    int *a = new int[capacity];  // creating a new array with new size
    int i = 0;  
    while(i < this->size){
        a[i] = this->elements[i];
        i++;
    }   // copying elements into the new array

    delete[] this->elements; //freeing up memory allocated to the old array
    this->elements = a;     //assigning the new array into the variable that held the old array
    this->capacity = capacity;  //argument capacity will be the new capacity in the array
}

bool List::insert(int e, int pos){
    if(pos < 0 || pos > this->size){
        return false;
    }   //if the position to insert the element is greater or less than the dimensions of the array
    
    if(this->size + 1 > this->capacity){
        resize(this->capacity + 1);
    } //resizing the array when the insertion of the element exceeds the dimensions of the array

    int i = size - 1;
    while(i >= pos){
        this->elements[i+1] = this->elements[i];
        i--;
    }   //sweeping elements forward one position to insert them in the desired position

    this->elements[pos] = e;    // inserting element
    this->size++;   //  increasing size of the array (number of elements)
    return true;
} //inserting elements in a desired position

bool List::deleter(int pos){
    if(pos < 0 || pos > this->size){
        return false;
    } //if the position to delete the element is greater or less than the dimensions of the array

    int i = pos + 1;
    while(i < size){
        this->elements[i - 1] = this->elements[i];
        i++;
    } //sweeping elements backwards one position to delete the desired element

    this->elements[size] = NULL;        // Why error????
    this->size--;
    return true; 
} //deleting elements in a desired position

int* List::get_pos(int pos){
    if(pos >= this->size){
        return NULL;
    }
    return &this->elements[pos];
}   // if the position of that element is not in the array return NULL

void List::push_start(int e){
    if(this->size + 1 > this->capacity){
        this->resize(this->capacity + this->step);
    }
    
    int i = size - 1; //iterator in last position
    while(i >= 0){
        this->elements[i+1] = this->elements[i];
        i--;
    }   //sweeping elements forward one position to insert them in the desired position

    this->elements[0] = e; //element now in the first position
    this->size++;
}   //the element is at the start of the list

void List::push_end(int e){
    if(this->size + 1 > this->capacity){
        this->resize(this->capacity + this->step); //enlarging the array
    }
    this->elements[this->size] = e; //inserting the element at the end of the array
    size++; //increasing the size (number of elements) in the list
}


int main(){

    List l(10);

    cout << "capacity: " << l.get_capacity() << endl; 


    return 0;
}