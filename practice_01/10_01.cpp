/*
Given an array of N integers, design recursive algorithms that calculate:

● Greatest element of the array     [DONE]
● The sum of the elements of the array   [DONE]
● The median of all the elements of the array   [DONE] ← using mergesort
● Verify if the array is sorted     [DONE]

*/

#include <iostream>

using namespace std;

int findGreatest(int array[], int size, int element){
    if(size == 0) return element;
    if(element <= array[size-1]){
        element = array[size-1];
    }
    return findGreatest(array, size - 1, element);
}

int sum(int array[], int size, int s){
    if(size == 0) return s;
    return s + sum(array, size - 1, array[size - 1]);
}

void showArr(int A[], int size){
    int i = 0 ;
    cout << "[ " ;
    while(i < size){
        cout << A[i] << " " ;
        i++ ;
    }
    cout << "]" ;
}

void copiar(int A[], int B[], int arrSize, int pos_in){
    int i = 0;
    while(i < arrSize){
        B[i] = A[pos_in + i];
        i++;
    }
}

void merge(int A[], int izq[], int der[], int sizeIzq, int sizeDer, int in){
    int i = 0, j = 0, k = in;
    while(i < sizeIzq && j < sizeDer){
        if(izq[i] < der[j]){
            A[k] = izq[i];
            i++;
            k++;
        } else if(izq[i] > der[j]){
            A[k] = der[j];
            j++;
            k++;
        } else if(izq[i] == der[j]){
            A[k] = izq[i];
            i++;
            j++;
            k++;
        }
    }

    while(i < sizeIzq){
        A[k] = izq[i];
        i++;
        k++;
    }

    while(j < sizeDer){
        A[k] = der[j];
        j++;
        k++;
    }
}

void mergeSort(int A[], int in, int fin){
    if(in < fin){
        int m = (in + fin) / 2;

        mergeSort(A, in, m);
        mergeSort(A, m+1, fin); 

//          ↓
        int sizeIzq = m - in + 1 ;
        int sizeDer = fin - m;
//          ↑

        int *izq = new int[sizeIzq];
        int *der = new int[sizeDer];

        copiar(A, izq, sizeIzq, in);
        copiar(A, der, sizeDer, m+1);

        merge(A, izq, der, sizeIzq, sizeDer, in);

        delete izq;
        delete der; 
    }
}

int findMedian(int array[], int size){
    return array[size/2];
}

bool isSorted(int array[], int size){
    if(size - 2 == 0){
        if(array[size - 1] < array[size - 2]) return false;
        return true;
    }
    return isSorted(array, size - 1);
}

int main(){
    int array[] = {42, 17, 63, 91, 5, 78, 32, 10, 55, 23, 46, 58, 82, 37, 12, 69, 28, 99, 3, 60, 14, 72, 51, 8, 95, 64, 21, 76, 39, 97};

    int n = sizeof(array) / 4;

    cout << "Greatest element of the array: " << findGreatest(array, n, array[0]) << endl;

    cout << "Sum of the elements of the array: " << sum(array, n - 1, array[n-1]) << endl;

    //showArr(array, n);

    mergeSort(array, 0, n-1); // using mergesort to sort the array and find the median

    // showArr(array, n);

    cout << "Median of the elements of the array: " << findMedian(array, n) << endl;

    cout << "The array is ";
    if(!isSorted(array, n)){
        cout << "not ";
    }
    cout << "sorted";

    
    return 0;
}