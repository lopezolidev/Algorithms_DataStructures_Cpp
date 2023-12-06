/*
Obtain all the numbers of m digits (m <= 9), all of them different from 0 and different between them, in such a way that number formed by the first n digits, whatever it is (n <= m) be a multiple of n. I.e: for m = 4 are valid numbers, among others, the following: 1236, 1 is multipleo of 1, 12 of 2, 123 of 3 and 1236 of 4. 9872, it's multiple of 1, 98 of 2, 987 of 3 and 9872 of 4.
*/

#include <iostream>


using namespace std;


int digits(int n){
    int c = 0;

    while((n/=10) != 0){
        c++;
    } 

    return c + 1;
}

void possibleNumbers(int n, int m, int j){
    if(digits(n) == m) cout <<"n: " << n << endl;
    int i = j;

    while((digits(n) <= m)){
        if((n % i) == 0){
            n *= 10;
            possibleNumbers(n, m, i + 1);
            n /= 10;
        }
        n += 1;
    }

}   // Divisible function is missing. WORK IN PROGRESS

int main(){

    // cout << 65 % 2;

    int m = 4;

    cout << "possible numbers of m = " << m << endl;
    possibleNumbers(1, 4, 1);

    return 0;
}