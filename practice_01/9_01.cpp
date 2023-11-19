/*

Write a recursive function to calculate the power of a given number elevated to a positive integer, from:

x^0 = x
x^n = (x*x)n/2 if n > 0 and its even
x^n = x*(x^(n-1)) if n > 0 and its odd
*/

#include <iostream>

using namespace std;

int pow(int base, int power){
    if(power == 1) return base;     // the instructions are wrong, this is the base case
    if(power % 2 == 0){
        return pow(base*base, power/2);
    }
     else {
        return base * pow(base, power - 1);
    }
}

int main(){
    cout << "Insert base number: ";
    int b = 0;
    cin >> b;
    cout << endl;
    cout << "Insert power 'n': ";
    int x = 0;
    cin >> x;
    cout << endl;

    while(b == 0 || x < 0){
        if(b == 0){
            cout << "The base must be a valid number" << endl << "Insert base: ";
            cin >> b;
        }
        else {
           cout << "The power must be a valid number" << endl << "Insert power 'n': ";
           cin >> x; 
        }
    }

    cout << pow(b, x);

    cout << endl;

    return 0;
}