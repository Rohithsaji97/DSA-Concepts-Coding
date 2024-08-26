#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void Traversal(struct Node *ptr){
    while (ptr != NULL){
        printf("Element is: %d\n", ptr -> data);
        ptr = ptr -> next; 
    }
}

int isEmpty(struct Node * top){
    if (top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct Node * top){
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    if (ptr == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

struct Node *push (struct Node * top, int data){
    if (!isFull(top)){
        struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr -> data = data;
        ptr -> next = top;
        top = ptr;
        return top;
    }
    else{
        printf("Stack overflow");
    }
}

struct Node * pop (struct Node *top){
    if(isEmpty(top)){
        printf("Stack underflow");
    }
    else{
        struct Node *ptr = top;
        int value = top -> data;
        top = top -> next;
        printf("the popped value is %d \n", value);
        free(ptr);
        return top;
    }
}

int peek(struct Node *top, int index){
    int i = 0;
    struct Node * ptr = top;
    while (ptr -> next != NULL){
        ptr = ptr -> next;
        i = i + 1;
        if (i == index){
            return ptr -> data;
        }
    }
    return -1;
}

int main(){
    struct Node *top = NULL;

    top = push(top, 5000);
    top = push(top, 500);
    top = push(top, 50);
    top = push(top, 5);
    // Traversal(top);
    int qwerty = peek(top, 6);
    printf("The value is %d", qwerty);
    // Traversal(top);

    return 0; 
}