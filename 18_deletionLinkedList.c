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

struct Node * delBeg(struct Node * head){
    struct Node *ptr = head;
    head = head -> next;
    free(ptr);
    return head;
}

struct Node * delBetween(struct Node *head, int index){
    struct Node *p = head;
    int i = 0;
    while (i != index - 1){
        p = p -> next;
    }
    struct Node *q = p -> next;
    p -> next = q -> next;
    free(q);
    return head;
}

struct Node * delEnd(struct Node *head){
    struct Node *p = head;
    struct Node *q = head;
    p = p -> next;
    while (p -> next != NULL){
        p = p -> next;
        q = q -> next;
    }
    q -> next = NULL;
    free(p);
    return head;
}

struct Node * delNode(struct Node *head, struct Node *delNode){
    struct Node *p = head;
    while (p -> next != delNode){
        p = p -> next;
    }
    p -> next = delNode -> next;
    free(delNode);
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
    //head = delBeg(head);
    //head = delBetween(head, 1);
    //head = delEnd(head);
    head = delNode(head, third);
    Traversal(head);
    return 0;
}