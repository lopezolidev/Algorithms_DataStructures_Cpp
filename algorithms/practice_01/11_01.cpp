/*
Elaborate a recursive algorithm that given a sorted integers array in ascending order and without repeated elements, do a binary search of an element E if this exists
*/

#include <iostream>

using namespace std;

bool binarySearch(int array[], int n, int first, int last){
    if(first >= last) return false;     // if the first and last indexes cross each other means the element is not in the array
    if(array[(last+first)/2] == n || array[first] == n || array[last] == n) return true;    // true if the element at the half, start or last index is the element 
    
    // both cases where the element is greater or less than the half

    if(array[(last+first)/2] > n){
        return binarySearch(array, n, first, ((last+first)/2) - 1);
    }
    else{
        return binarySearch(array, n, ((last+first)/2) + 1, last);
    }
}

int main(){
    int array[] = {1, 3, 8, 10, 12, 20, 21, 26, 28, 32} ;

    int first = 0 ;

    int last = (sizeof(array) / 4) - 1 ;

    cout << "Insert a number: ";
    int n = 0;
    cin >> n;   

    cout << "The number is ";

    if(!binarySearch(array, n, first, last)) cout << "not ";

    cout << "in the array" << endl;

    return 0;
}