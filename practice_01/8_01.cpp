/*
Write a recursive function to calculate: (1 + 1/2 + 1/3 + ... 1/n)

Asume that recieves as parameter the value of n
*/

#include <iostream>

using namespace std;

int fact(int n){
    if(n == 1) return 1;
    return n * fact(n-1);
}

int sums(int den, int n){
    if(n == 1) return den;
    return den / n + sums(den, n - 1);
}

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
}

int main(){
    cout << "Insert N number: ";
    int n = 0;
    cin >> n;
    cout << endl;
    while(n < 1){
        cout << "N must be a valid number" << endl << "Insert N: ";
        cin >> n;
    }
    cout << endl;

    int den = fact(n);
    int num = sums(den, n);

    cout << num / gfd(num, den) << " / " << den / gfd(num, den);

    return 0;
}