/*

Write a recursive funciton to calculate the GCD (greatest common divider) from two given integers applying the recurring properties

*/

#include <iostream>

using namespace std;

int mini(int a, int b){
    if(a < b) return a;
    return b;
}

int maxi(int a, int b){
    if(a > b) return a;
    return b;
}

int gfd(int n1, int n2){
    int max = maxi(n1, n2);
    int min = mini(n1, n2);

    int res = max % min;

    if(res == 0) return min;

    return gfd(min, res);
}   // using euclidean algorithm to find the GCF

int main(){

    cout << "Insert number 1 for the GFD of two numbers: ";
    int N_1;
    cin >> N_1;

    cout << "Insert numebr 2 for the GFD of two numbers: ";
    int N_2;
    cin >> N_2; 

    cout << "The greatest common factor of " << N_1 << " and " << N_2 << " is " << gfd(N_1, N_2);

    return 0;
}