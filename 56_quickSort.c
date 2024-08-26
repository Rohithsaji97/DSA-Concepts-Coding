#include<stdio.h>
#include<stdlib.h>


void printArray(int A[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int A[], int low, int high){
    int temp;
    int pivot = A[low];
    int i = low + 1;
    int j = high;

    do
    {
        while (A[i] <= pivot){
            i++;
        }

        while (A[j] > pivot){
            j--;
        }

        if (i < j){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }

    } while (i < j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    
    return j;
}

void quickSort(int A[], int low, int high){
    int partitionIndex;

    if (low < high){
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1);      //left side
        quickSort(A, partitionIndex + 1, high);     //right side
    }
}

int main(){
    int n = 8;
    int A[] = {6,4,8,3,8,3,2,1};

    printArray(A, 8);
    quickSort(A, 0, n - 1);
    printArray(A, 8);
}