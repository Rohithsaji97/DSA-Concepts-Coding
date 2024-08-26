#include<stdlib.h>
#include<stdio.h>

// declared globally
struct node *f = NULL;
struct node *r = NULL;

struct node{
    int data;
    struct node * next;
};

void Traversal(struct node *ptr){
    while (ptr != NULL){
        printf("Element is: %d\n", ptr -> data);
        ptr = ptr -> next; 
    }
}

void enqueue(int value){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL){
        printf("Queue is full\n");
    }
    else{
        ptr -> data = value;
        ptr -> next = NULL;
        if(f == NULL){
            f = r = ptr;
        }
        else{
            r -> next = ptr;
            r = ptr;
        }
    }
}

int dequeue(){
    if (f == NULL){
        printf("Queue is Empty\n");
        return -1;
    }
    else{
       struct node *ptr = f;
       f = f -> next;
       int val = ptr -> data;
       free(ptr);
       return val;
    }
}


int main(){

    dequeue();
    enqueue(20);
    enqueue(25);
    enqueue(30);

    Traversal(f);

    printf("The dequeued element is %d\n", dequeue());
    printf("The dequeued element is %d\n", dequeue());
    printf("The dequeued element is %d\n", dequeue());
    printf("The dequeued element is %d\n", dequeue());


    return 0;
}