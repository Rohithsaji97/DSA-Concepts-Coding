#include<stdio.h>
#include<stdlib.h>

struct circularQueue{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct circularQueue *q){
    if ((q -> r + 1) % q -> size == q -> f){
        return 1;
    }
    return 0;
}

int isEmpty(struct circularQueue *q){
    if (q -> r == q -> f){
        return 1;
    }
    return 0;
}

void enqueue(struct circularQueue *q, int value){
    if (isFull(q)){
        printf("Stack Overflow\n");
    }
    else{
        q -> r = (q -> r + 1) % q -> size;
        q -> arr[q -> r] = value;
    }
}

int dequeue(struct circularQueue *q){
    if (isEmpty(q)){
        printf("Stack Underflow\n");
        return -1;
    }
    else{
        q -> f = (q -> f + 1) % q -> size;
        int val = q -> arr[q -> f];
        return val;
    }
}

int main(){

    struct circularQueue *q = (struct circularQueue *)malloc(sizeof(struct circularQueue));
    q -> size = 3;
    q -> f = 0;
    q -> r = 0;
    q -> arr = (int *)malloc(q -> size * (sizeof(int)));

    enqueue(q,10);
    enqueue(q,12);
    enqueue(q,20);
    printf("The value is %d\n",dequeue(q));
    printf("The value is %d\n",dequeue(q));
    printf("The value is %d\n",dequeue(q));
    return 0;
}
