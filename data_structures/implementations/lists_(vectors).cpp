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
    // bool filler();

    public:

        // Declaring constructor and destroyer: 

        List(int cap = 5){
            this->capacity = cap;
            this->elements = new int[capacity]; 
            this->size = 0;
            // this->filler();
        } // constructor, can be used for default capacity or sending a capacity by argument

        ~List(){
            delete[]this->elements;
        }; // destructor

//-------------------------------------//

        int array(int pos);
        bool insert(int e, int pos);
        bool deleter(int pos);
        bool push_start(int e);
        bool push_end(int e);
        int* get_pos(int pos); // function that returns the memory address of this element in that position
        int pop();
        int shift();

        int get_capacity(){
            return this->capacity; 
        }
        int get_size(){return this->size;} // returns how many elements we have in the array
};

/*
To-be implemented:
    - resize (done)
    - insert (done)
    - deleter (done)
    - push_start (done)
    - get_pos (done)

*/ 

int List::array(int pos){
    return this->elements[pos];
} //returns the element like a traditional array

// bool List::filler(){
//     int i = 0;
//     while(i < capacity){
//         this->elements[i] = -1;
//         i++;
//     }

//     return true;
// }// fills with 0's every position in the list
/*
    There's no need of filler(). The creation of a dynamic array initializes all the positions in 0 by default.
*/


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
        resize(this->capacity + this->step);
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
    while(i <= this->size){
        this->elements[i - 1] = this->elements[i];
        i++;
    } //sweeping elements backwards one position to delete the desired element

    this->elements[i] = -1;        
    this->size--; //reducing the size before contraction of the vector

    if(this->elements[size] == -1){
        resize(i+1);
    }   //contracting the vector after deletion with available elements + 1
    
    return true; 
} //deleting elements in a desired position

int* List::get_pos(int pos){
    if(pos < 0 || pos >= this->size){
        return NULL;
    }
    return &this->elements[pos];
}   // if the position of that element is not in the array return NULL

bool List::push_start(int e){
    return insert(e , 0); 
}   //inserts the element at the start of the list

bool List::push_end(int e){
    return insert(e, this->size);
} //inserts the element at the end of the list
   
int List::pop(){
    int v = this->elements[0];
    deleter(0);
    return v;
} //deletes the element at the start of the list

int List::shift(){
    int v = this->elements[this->size - 1];
    deleter(this->size - 1);
    return v;
} //deletes the element at the end of the list


// Further testing must be executed

int main(){

    List l(10);

    cout << "capacity: " << l.get_capacity() << endl; 
    cout << "size: " << l.get_size() << endl;

    cout << "at position 0 we have " << l.array(0) << endl;
    cout << "at position 1 we have " << l.array(1) << endl;
    cout << "at position 2 we have " << l.array(2) << endl;
    cout << "at position 3 we have " << l.array(3) << endl;
    cout << "at position 4 we have " << l.array(4) << endl;



    l.push_start(3);
    cout << "at position 0, we have " << l.array(0) << endl;
    cout << "at position 1 we have " << l.array(1) << endl; 

    l.push_start(2);
    cout << "at position 0, we have " << l.array(0) << endl;
    l.push_end(5);
    cout << "at position 2, we have " << l.array(2) << endl;
    l.push_end(6);
    cout << "at position 3, we have " << l.array(3) << endl;

    cout << "size: " << l.get_size() << endl;

    l.insert(1, 2);
    cout << "at position 2, we have " << l.array(2) << endl;
    cout << "at position 3, we have " << l.array(3) << endl;
    cout << "at posiiton 4, we have " << l.array(4) << endl;


    l.deleter(3);
    cout << "at position 3, we have " << l.array(3) << endl;
    cout << "at posiiton 4, we have " << l.array(4) << endl;

    int v = l.pop();
    cout << "the first element was " << v << endl;
    cout << "Now the first element is: " << l.array(0) << endl;
    l.push_start(v);

    int v_2 = l.shift();
    cout << "The last element was " << v_2 << endl;
    cout << "Now the last element is: " << l.array(l.get_size() - 1) << endl;
    l.push_end(v_2); 

    int* p = l.get_pos(0);
    cout << "What's the direction of the first element? " << p << endl;
    *p = 10;
    cout << "We did: *p = 10, now let's check that position: " << l.array(0) << endl;

    return 0;
}