#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX]; // which will hold thelemts.
    int front; // the pointers to keep track of the queue.
    int rear;
} Queue;


int insert(Queue *q, int k){
    if(q->rear == MAX - 1){
        printf("Queue is full\n");
        return 1;
    }

    if(q->front == -1){ // when the queue is empty.
        q->rear = q->front = 0; // starting the queue at zeroth index.
        q->data[q->rear] = k; // insertion.
    }

    else{ // when the queue is not empty.
        q->rear++;
        q->data[q->rear] = k; // insertion.
    }

    return 0;


}

