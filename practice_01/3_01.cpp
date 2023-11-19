/*
Write a recursive function that calculates the result of the combinatorics of 2 integers
*/

#include <iostream>

using namespace std;

int fact(int n){
    if (n == 0) return 1;
    return n * fact(n-1);
}

int comb(int a, int b){
    if( a < b) return -1;
    if(a == b || b == 0) return 1;
    if(b == 1) return a;

    int fact_a = fact(a);
    int fact_b = fact(b);
    int fact_ab = fact(a-b);

    return fact_a / (fact_b * fact_ab); 
}

int main(){
    // cout << "Factorial of 3: " << fact(3);
    cout << "Combinatorics of (7 | 3): " << comb(7, 3);

    return 0;
}