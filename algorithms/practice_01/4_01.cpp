/*
Given a positive integer or null (in decimal base), write a recursive algorithm that returns another positive integer which value is the representation in binary (base 2) of the given value. Repeat the same process for base 16.
*/

#include <iostream>

using namespace std;

int tobin(int n){
    if(n < 2) return n ;
    return tobin(n/2)*10 + n%2 ;

    //building the number from bottom to tops + the mod by 2
}

int main(){
    cout << "binary of 17: " << tobin(17);

    return 0;
}