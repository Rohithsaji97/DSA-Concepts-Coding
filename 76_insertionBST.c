#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node * createNode(int data){
    struct Node *n = (struct Node *)malloc (sizeof(struct Node));
    n -> data = data;
    n -> left = NULL;
    n -> right = NULL;
    return n;
}

void insertion(struct Node * root, int data){
    struct Node * prev = NULL;
    struct Node * ptr =createNode(data);
    while (root != NULL){
        prev = root;
        if (root -> data > data){
            root = root -> left;
        }
        else if (root -> data < data){
            root = root -> right;
        }
        else{
            printf("Element already present\n");
            return;
        }
    }
    if (data > prev -> data){
        prev -> right = ptr;
    }else {
        prev -> left = ptr;
    }
    
}

void inOrder(struct Node *root){
    if (root != NULL){
        inOrder(root -> left);
        printf("%d ",root -> data);
        inOrder(root -> right);
    }
}

int main(){
    struct Node* p = createNode(5);
    struct Node* p1 = createNode(3);
    struct Node* p2 = createNode(6);
    struct Node* p3 = createNode(1);
    struct Node* p4 = createNode(4);

    p -> left = p1;
    p -> right = p2;
    p1 -> left = p3;
    p1 -> right = p4;

    inOrder(p);
    printf("\n");
    insertion(p,4);
    inOrder(p);
}