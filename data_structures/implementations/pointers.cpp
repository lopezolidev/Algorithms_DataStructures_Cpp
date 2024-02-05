/*
    What are pointers and how do we manipulate them?
*/

#include <iostream>

using namespace std;

int main(){

    int a = 10;

    int *p = &a;

    cout << "a: " << a << endl;

    cout << "*p: " << *p << endl; //the value that stores the memory address stored in the pointer

    cout << "&a: " << &a << endl; // the memory address of a

    cout << "p: " << p << endl; // the memory address inside p


    cout << "Is *p == a? ";
    if(*p == a){
        cout << "True" << endl;
    }

    cout << "Is p == &a? ";
    if(p == &a){
        cout << "True " << endl;
    }else {
        cout << "False " << endl;
    }

    cout << "What is &p? " << "&p: " << &p << endl; // memory direction of p

    cout << "Can we do *p = 4? " << endl;
    *p = 4;     //modifying the variable

    cout << "*p: " << *p << endl;
    cout << "a: " << a << endl;

    cout << "Can we do p = 3 ?" << endl;
//    p = 3; error: invalid conversion from ‘int’ to ‘int*’ [-fpermissive]
    // No, we're not allowed to modify that memory address


    return 0;
}