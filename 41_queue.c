#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue *q){
    if (q -> r == q -> size - 1){
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *q){
    if (q -> r == q -> f){
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int value){
    if (isFull(q)){
        printf("Stack Overflow\n");
    }
    else{
        q -> r = q -> r + 1;
        q -> arr[q -> r] = value;
    }
}

int dequeue(struct queue *q){
    if (isEmpty(q)){
        printf("Stack Underflow\n");
        return -1;
    }
    else{
        q -> f = q -> f + 1;
        int val = q -> arr[q -> f];
        return val;
    }
}

int main(){

    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q -> size = 2;
    q -> f = -1;
    q -> r = -1;
    q -> arr = (int *)malloc(q -> size * (sizeof(int)));

    enqueue(q,10);
    enqueue(q,12);
    enqueue(q,20);
    printf("The value is %d\n",dequeue(q));
    printf("The value is %d\n",dequeue(q));
    printf("The value is %d\n",dequeue(q));
    return 0;
}
