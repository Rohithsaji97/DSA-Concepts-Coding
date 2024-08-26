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

int insert(int array[], int n, int element, int index, int tot_size){
    //inertion @ given index
    if (index > tot_size){
        return -1;
    }
    else{
        for (int i = n - 1;i >= index;i--){
            array[i+1] = array[i];
        }
        array[index] = element;
        return 1;
    }
}

int main(){
    int a[100] = {4,6,15,32,56,63};
    int element = 47, index = 4;
    display(a, 6);
    int q = insert(a, 6, element, index, 100);
    if (q == 1){
        display(a, 7);
    }
    else{
        printf("Insertion not successfull!!!");
    }
    return 0;
}