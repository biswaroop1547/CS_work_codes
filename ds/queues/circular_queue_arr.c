#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int front, rear;

} C_QUEUE;

int enqueue(C_QUEUE *q, int k){
    if(q->front == (q->rear + 1) % MAX){
        printf("Queue is full\n");
        return 1;
    }
    if(q->rear == -1){
        q->front = q->rear = 0;
        q->data[q->rear] = k;
    }

    else{
        q->rear = (q->rear + 1) % MAX;
        q->data[q->rear] = k;
    }

    return 0;
}

int dequeue(C_QUEUE *q, int *m){
    if(q->rear == -1){
        printf("Queue is empty, cannot dequeue\n");
        return 1;
    }

    if(q->front == q->rear){ // only one element is present.
        *m = q->data[q->front];
        q->front = q->rear = -1; // setting the queue empty.
    }

    else{
        *m = q->data[q->front];
        q->front = (q->front + 1) % MAX;
    }
    
    return 0;
}


int main(){
    C_QUEUE q;
    q.front = q.rear = -1;

}