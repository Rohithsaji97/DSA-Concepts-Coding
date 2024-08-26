#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void Traversal(struct Node *head){
    struct Node * ptr = head;
    do{
        printf("Element is : %d\n", ptr -> data);
        ptr = ptr -> next;
    }while(ptr != head);
}

struct Node *insertBeg(struct Node *head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    ptr -> next = head;
    ptr -> data = data;
    do{
        p = p -> next;
    }while (p -> next != head);
    p -> next = ptr;
    return ptr;
}

int main(){

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *forth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    forth = (struct Node *)malloc(sizeof(struct Node));

    head -> data = 7;
    head -> next = second;
    
    second -> data = 15;
    second -> next = third;
    
    third -> data = 29;
    third -> next = forth;
    
    forth -> data = 36;
    forth -> next = head;

    Traversal(head);
    head = insertBeg(head, 3);
    Traversal(head);
    return 0;
}