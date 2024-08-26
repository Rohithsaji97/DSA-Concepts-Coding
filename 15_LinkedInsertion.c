#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void Traversal(struct Node *ptr){
    while (ptr != NULL){
        printf("Element is: %d\n", ptr -> data);
        ptr = ptr -> next; 
    }
}

struct Node *insertBeg(struct Node *head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr -> next = head;
    ptr -> data = data;
    return ptr;
}

struct Node *insertBetNode(struct Node *head, struct Node *prevNode, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr -> data = data;

    ptr -> next = prevNode -> next;
    prevNode -> next = ptr;

    return head;
}

struct Node *insertBetween(struct Node *head, int data, int index){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr -> data = data;
    int i = 0;
    struct Node *p = head;

    while (i != index - 1){
        p = p -> next;
        i++;
    }

    ptr -> next = p -> next;
    p -> next = ptr;
    return head;
}

struct Node *insertEnd(struct Node *head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr -> data = data;
    struct Node *p = head;

    while (p -> next != NULL){
        p = p -> next;
    }

    p -> next = ptr;
    ptr -> next = NULL;
    return head;
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
    forth -> next = NULL;

    Traversal(head);
    //head = insertBeg(head, 3);
    //head = insertBetween(head, 9, 1);
    //head = insertEnd(head, 49);
    head = insertBetNode(head, second, 23);
    Traversal(head);
    return 0;
}