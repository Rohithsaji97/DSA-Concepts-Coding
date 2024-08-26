#include<stdlib.h>
#include<conio.h>
#include<stdio.h>

void display(int array[], int n){
    //traversal
    for (int i = 0;i < n;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}

void delete(int array[], int n, int index){
    for (int i = index; i < n; i++){
        array[i] = array[i+1];
    }
}

int main(){
    int a[100] = {4,6,15,32,56,63};
    int index = 5;
    display(a, 6);
    delete(a, 6, index);
    display(a,5);
    return 0;
}