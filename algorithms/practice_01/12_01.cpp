/*
Write a recursive function that reverses the digits of an integer, employing operations over integers
I.e: 653 to 356
*/

#include <iostream>

using namespace std;

int mult(int n, int& m){
    m*= 10;
    if((n / m) > 0) mult(n, m);
    return m; 
}   // this function finds out the power of the number we wish to flip

int reverser(int n, int m){
    if((n / 10) == 0) return n;

    return (n%10)*(m/10) + reverser(n/10, m/10);
}   // this function obtains the number reversed, always multiplying the moduled number by a power of 10 divided by 10

int main(){
    int n = 0;

    cout << "Please insert a number: ";
    cin >> n;
    cout << endl;

    int m = 1;

    mult(n, m);

    cout << "n % 10 " << (n % 10) * m / 10  << endl; 

    cout << "reversed number: " << reverser(n, m);


    return 0;
}