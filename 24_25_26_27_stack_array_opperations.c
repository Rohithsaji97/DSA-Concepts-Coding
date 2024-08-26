#include <stdlib.h>
#include <stdio.h>

struct stack {
    int size;
    int *arr;
    int top;
};

int isEmpty(struct stack *ptr) {
    if (ptr->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int isFull(struct stack *ptr) {
    if (ptr->top == ptr->size - 1) {
        return 1;
    } else {
        return 0;
    }
}

int pop(struct stack *ptr){
    if (isEmpty(ptr)){
        printf("\nstack underflow\n");
        return -1;
    }
    else{
        int value = ptr -> arr[ptr -> top];
        ptr -> top = ptr -> top - 1;
        return value;
    }
}

void push(struct stack *ptr, int value){
    if (isFull(ptr)){
        printf("stack overflow\n");
    }
    else{
        ptr -> top = ptr -> top + 1;
        ptr -> arr[ptr -> top] = value;
    }
}

int peek(struct stack *ptr, int i){
    if(ptr -> top - i + 1 < 0){
        printf("invalid position \n");
        return -1;
    }
    else{
        return ptr -> arr[ptr -> top - i + 1];
    }
}

int main() {
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));

    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));


    push(s,5);
    push(s,90);
    push(s,900);
    push(s,9000);
    push(s,90300);
    push(s,902400);


    for(int i = 1; i <= s -> top + 1; i++){
        printf("%d\n", peek(s, i));
    }
    return 0;
}