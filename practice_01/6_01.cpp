/*

Write a recursive algorithm that finds the sum of the first N natural numbers

*/

#include <iostream>

using namespace std;

int sum(int N){
    if(N == 1) return 1;
    if(N < 1) return 0;
    return N + sum(N - 1);
}

int main(){
    int N = 0;

    cout << "insert number you want the sum of first N naturals: " << endl;
    cin >> N;

    cout << "Sum of " << N << " is " << sum(N);

    return 0;
}