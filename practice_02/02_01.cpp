/*
Generate all the possible permutations of an array of characters of size N. Now generate all the permutations of the same array, making sure the sum is an even number
*/

#include <iostream>

using namespace std;

void print(char t[], int N){
    int i = 0;
    cout << "[ "; 
    while(i < N){
        cout << t[i] << " ";
        i++;
    }
    cout << "] " << endl;
}

void swap(char& a, char& b){ //reference parameters are the ones that change the elements in the actual array
    char c;
    c = a;
    a = b;
    b = c;
}

void permutar(char t[], int i, int N){
    if(i >= N){
        print(t, N);
    }  
    else{
        int j = i;
        while(j < N){
            swap(t[i], t[j]);
            permutar(t, i + 1, N);
            swap(t[i], t[j]);
            j++;
        }
    }
}

int main(){
    char arr[3] = {'A', 'B', 'C'};
    cout << "Array: "; print(arr, 3);
    permutar(arr, 0, 3);

    return 0;
}