/*
Knowing that 0 is even, that is:

IsEven(0) = true

IsOdd(0) = false

And the parity of any other positive integer is the opposite of the parity of the previous integer, develop the mutually recursive logical functions, IsEven and IsOdd, which complement each other when determining the parity of a positive integer.
*/

#include <iostream>

using namespace std;

bool isEven(int n);

bool isOdd(int m); 
// signing the functions to avoid any declaration errors

bool isOdd(int m){
    if(m == 0) return false;
    return isEven(m - 1);
}   // recursive function that calls isEven

bool isEven(int n){
    if(n == 0) return true;
    return isOdd(n-1);
}    // recursive function that calls isOdd

int main(){

    cout << "Insert a positive integer " << endl;
    int a = 0;
    cin >> a;
    cout << endl;

    while(a < 0)
        {
        cout << "Must be a positive integer " << endl;
        cin >> a;
        cout << endl;
        };

    cout << a << " is";
    if(isOdd(a)){
        cout << " odd" << endl;
    } else {
        cout << " even" << endl;
    }

    return 0;
}