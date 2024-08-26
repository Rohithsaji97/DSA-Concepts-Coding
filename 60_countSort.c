#include<stdio.h>
#include<stdlib.h>


void printArray(int A[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

int findMax(int A[], int n){
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if(A[i] > max){
            max = A[i];
        }
    }
    return max;
}

void countSort(int A[], int n){
    int max = findMax(A, n);

    int *count = (int*)malloc((max + 1) * sizeof(int));

    for (int i = 0; i < max + 1; i++)
    {
        count[i]  = 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        count[A[i]] += 1;
    }

    int i = 0, j = 0;
    while(i <= max){
        if (count[i] > 0){
            A[j] = i;
            count[i] -= 1;
            j++;
        } else {
            i++;
        }
    }
}

int main(){
    int n = 8;
    int A[] = {6,4,8,3,8,3,2,1};

    printArray(A, 8);
    countSort(A, n);
    printArray(A, 8);
}