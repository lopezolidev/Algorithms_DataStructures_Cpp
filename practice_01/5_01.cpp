/*
Elaborate a recursive function which given an array of characters that form a word, return true if this is palindrome. I.e: noon, civic, racecar, level, mom
*/

#include <iostream>

using namespace std;

bool checkPal(char *A, int i, int f){
    if( i >= f) return true;
    if(A[i] == A[f]) return checkPal(A, i + 1, f - 1);  // recursive call
    return false;
}

int main(){
    char A[7] = {'a', 'r', 'e', 'p', 'e', 'r', 'a'};
    // cout << A;

    cout << "La palabra " << A;
    if(!checkPal(A, 0, 6)) cout << " no";
    cout << " es capicúa";

    return 0;
}