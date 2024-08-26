#include <stdio.h>
#include<stdlib.h>

struct myArray
{
    int tot_size;
    int used_size;
    int *ptr;
};

void getVal(struct myArray *a){
    for (int i = 0; i < a->used_size; i++){
        printf("%d \n", (a->ptr)[i]);
    }
}

void setVal(struct myArray *a){
    int n;
    for (int i = 0; i < a->used_size; i++){
        printf("Enter element %d: ", i);
        scanf(" %d", &n);
        (a->ptr)[i] = n;
    }
}

void createArray(struct myArray *a, int tsize, int usize){
    //(*a).tot_size = tsize;
    //(*a).used_size = usize;
    //(*a).ptr = (int*)malloc(tsize * sizeof(int));

    a->tot_size = tsize;
    a->used_size = usize;
    a->ptr = (int*)malloc(tsize * sizeof(int));
}

int main(){
    struct myArray marks;
    createArray(&marks,10,6);
    setVal(&marks);
    getVal(&marks);

    return 0;
}