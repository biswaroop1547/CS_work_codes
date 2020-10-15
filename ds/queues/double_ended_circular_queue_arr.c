#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int front;
    int rear;

} DC_QUEUE;


int enqueue(DC_QUEUE *q, int k, int side){
    if(q->front == (q->rear + 1) % MAX){ // queue is full when f = r + 1.
        printf("Queue is full\n");
        return 1;
    }

    if(q->rear == -1){ // if the queue is empty.
        q->front = q->rear = 0;
        q->data[q->rear] = k;
        return 0;
    }

    if(side == 0){ // insert from the front.
        q->front = (q->front + MAX - 1) % MAX; // the front moves with this function as we insert element from front.
        q->data[q->front] = k;
    }
    else{ // insert from the rear.
        q->rear = (q->rear + 1) % MAX; // the rear moves with this function as we insert element from rear.
        q->data[q->rear] = k;
    }

    return 0;

}


int dequeue(DC_QUEUE *q, int *m, int side){
    if(q->front == -1){ // queue is empty.
        printf("Queue is empty.\n");
        return 1;
    }

    if(q->front == q->rear){ // only one element present in the queue.
        *m = q->data[q->front];
        q->front = q->rear = -1;
        return 0;
    }

    if(side == 0){ // to delete from the front side of the queue.
        *m = q->data[q->front];
        q->front = (q->front + 1) % MAX; // function for front to move when deleted from the front.
    }
    else{ // to delete from the rear side of the queue
        *m = q->data[q->rear];
        q->rear = (q->rear + MAX - 1) % MAX; // function for rear to move when deleted from the back.
    }
}


void display(DC_QUEUE *q){
    printf("%d, %d\n", q->front, q->rear);
    for(int i = q->front; i <= q->rear; i++){ // to display all the numbers between front and rear.
        printf("%d\t", q->data[i]);
    }
    printf("\n");
}

int main(){
    DC_QUEUE q;
    q.front = q.rear = -1;

    int err = enqueue(&q, 10, 1); // last element decides where to enqueue, front or rear.
    err = enqueue(&q, 64, 1);
    err = enqueue(&q, 43, 1);
    err = enqueue(&q, 12, 0);
    err = enqueue(&q, 53, 1);
    display(&q);
    
    int dequeued_element;
    
    err = dequeue(&q, &dequeued_element, 1);
    printf("dequeued element - %d\n", dequeued_element);

    err = dequeue(&q, &dequeued_element, 0);
    printf("dequeued element - %d\n", dequeued_element);

}