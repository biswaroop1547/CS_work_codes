#include<stdio.h>
#include<stdlib.h>

#define MAX 100


typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;


int insert(Queue *q, int k){
    if(q->rear == MAX - 1){
        printf("Queue is full\n");
        return 1;
    }

    if(q->front == -1){
        q->rear = q->front = 0;
        q->data[q->rear] = k;
    }

    else{
        q->rear++;
        q->data[q->rear] = k;
    }

    return 0;


}


int delete(Queue *q, int *m){ // the space complexity will keep increasing but time complexity will be constant.
    if(q->front == -1){
        printf("Queue is empty\n");
        return 1;
    }

    else if(q->front == q->rear){
        *m = q->data[q->front];
        q->front = q->rear = -1;
    }

    else{
        *m = q->data[q->front];
        q->front++;    
    }

    return 0;

}


int delete2(Queue *q, int *m){ // space complexity will be constant as after deleting shifts all elements to left side, so time complexity will be linear to the filled size of the queue.
    if(q->front == -1){
        printf("Queue is empty\n");
        return 1;
    }

    else if(q->front == q->rear){
        *m = q->data[q->front];
        q->front = q->rear = -1;
    }

    else{
        *m = q->data[q->front];
        // q->front++;
        for(int i = q->front + 1; i <= q->rear; i++){
            q->data[i - 1] = q->data[i];
        }
        q->rear--;
    }

    return 0;

}

int main(){
    
    Queue q1;
    q1.front = q1.rear = -1;

    int err = insert(&q1, 5);
    int deleted_element;
    // int err1 = delete(&q1, &deleted_element);
    int err1 = delete2(&q1, &deleted_element);

    printf("deleted element: %d\n", deleted_element);
}

