#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int front, rear;

} C_QUEUE;

int enqueue(C_QUEUE *q, int k){
    if(q->front == (q->rear + 1) % MAX){ // if the queue is full so f == r + 1.
        printf("Queue is full\n");
        return 1;
    }
    if(q->rear == -1){ // if the queue is empty.
        q->front = q->rear = 0;
        q->data[q->rear] = k;
    }

    else{ // if the queue is not empty.
        q->rear = (q->rear + 1) % MAX; // to set the circular rear 
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
        q->front = (q->front + 1) % MAX; // for the circular front.
    }
    
    return 0;
}


void display(C_QUEUE *q){
    for(int i = q->front; i <= q->rear; i++){ // to display all the numbers between front and rear.
        printf("%d\t", q->data[i]);
    }
    printf("\n");
}

int main(){
    C_QUEUE q;
    q.front = q.rear = -1;

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    printf("after enqueueing 4 times:\n");
    display(&q);

    int dequeued_element;
    dequeue(&q, &dequeued_element);
    dequeue(&q, &dequeued_element);
    dequeue(&q, &dequeued_element);

    printf("after dequeueing 3 times:\n");
    display(&q);

}