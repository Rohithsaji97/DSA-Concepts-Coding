#include <stdlib.h>
#include <stdio.h>

struct stack {
    int size;
    char *arr;
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

char pop(struct stack *ptr){
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

void push(struct stack *ptr, char value){
    if (isFull(ptr)){
        printf("stack overflow\n");
    }
    else{
        ptr -> top = ptr -> top + 1;
        ptr -> arr[ptr -> top] = value;
    }
}


int countParanthesis(char *a){

    struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
    sp -> size = 80;
    sp -> top = -1;
    sp -> arr = (char*)malloc(sp ->size * sizeof(char));
// String Comparison Error: The comparison a[i] != "\0" should be a[i] != '\0' because "\0" is a string literal and '\0' is a character literal.
    for (int i = 0; a[i] != '\0';i++){
        if (a[i] == '('){
            push(sp, '(');
        }
        else if (a[i] == ')'){
            if (isEmpty(sp)){
                return 0;
            }
            pop(sp);
        }
    }
    if (isEmpty(sp)){
        return 1;
    }
    return 0;
}

int main() {


    char *val = "((())  )";

    if (countParanthesis(val)){
        printf("Equal Equal\n");
    }
    else{
        printf("Not Equal");
    }
}