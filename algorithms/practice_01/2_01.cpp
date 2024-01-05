/*
Write a recursive algorithm that prints the "n" number of the fibonacci sequence
*/

#include <iostream>

using namespace std;

int fib(int n){
    if(n < 0){
        return -1; // flag for fibonacci for negative numbers
    }
    if(n < 2){
        return n;
    }
    return fib(n-1) + fib(n-2);

}

int main(){
    cout << fib(8);

    return 0;
}