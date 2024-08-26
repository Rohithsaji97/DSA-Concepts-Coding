//tooooooo goooooood

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

int precedence(char ch){
    if(ch == '*' || ch=='/')
        return 3;
    else if(ch == '+' || ch=='-')
        return 2; 
    else
        return 0;
}

int isOperator(char ch){
    if(ch=='+' || ch=='-' ||ch=='*' || ch=='/') 
        return 1;
    else
        return 0;
}

int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}

char *infixToPostfix(char *infix){
    struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
    sp -> size = 100;
    sp -> top = -1;
    sp -> arr = (char *)malloc(sp ->size * sizeof(char));
    char * postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0;
    int j = 0;
    while (infix[i] != '\0'){
        if (!isOperator(infix[i])){
            postfix[j] = infix[i];
            i++; j++;
        }
        else{
            if(precedence(infix[i]) > precedence(stackTop(sp))){
                push(sp, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp)){
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main() {
    char * infix = "a+b+c*w";
    char *postfix = infixToPostfix(infix);
    printf(postfix);
}