/*
Write a recursive algorithm that can print a sequence of numbers in ascending order 
*/

#include <iostream>

using namespace std;

void number(int n){
    if(n > 0){
        number(n -1);
        cout << n << endl;
    } 
}

int main(){
    number(5);

    return 0;
}