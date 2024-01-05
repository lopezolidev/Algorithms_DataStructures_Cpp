/*
MergeSort Algorithm:

1- Divide: Divide the unsorted array into two halves. This can be done by finding the middle index of the array.

2- Conquer: Recursively sort the two halves of the array until they become single elements or empty arrays.

3- Merge: Merge the two sorted halves back together into a single sorted array. This can be done by comparing the elements from each half and inserting them into a new array in the correct order.
*/
#include <iostream>

using namespace std;

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

void showArr(int A[], int size){
    int i = 0 ;
    cout << "[ " ;
    while(i < size){
        cout << A[i] << " " ;
        i++ ;
    }
    cout << "]" ;
}

int main(){
    int Arr[] = { 8, 4, 2, 7, 1, 6, 3, 5 } ;
    int arrSize = sizeof(Arr)/4 ;


    showArr(Arr, arrSize);

    mergeSort(Arr, 0, arrSize);

    showArr(Arr, arrSize);

    return 0;
}