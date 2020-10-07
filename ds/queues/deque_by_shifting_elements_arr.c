#include<stdio.h>
#include<stdlib.h>

#define MAX 100


typedef struct {
    int data[MAX]; // which will hold thelemts.
    int front; // the pointers to keep track of the queue.
    int rear;
} Deque;


int insert(Deque *q, int k, int pos){
    if(q->front == 0 && q->rear == MAX - 1){ // queue is full.
        printf("Queue is full\n");
        return 1;
    }

    if(q->front == -1){ // when the queue is empty.
        q->rear = q->front = 0; // starting the queue at zeroth index.
        q->data[q->rear] = k; // insertion.
        return 0;
    }

    if(pos == 1){ // to insert at the rear end.
        
        if(q->rear == MAX - 1){
            for(int i = q->front; i <= q->rear; i++){
                q->data[i - 1] = q->data[i];
            }
            q->front--; // front goes one step back.
            q->data[q->rear] = k; // insertion.
        }

        else{ // when the queue is not empty.
            q->rear++;
            q->data[q->rear] = k; // insertion.
        }
    }

    else{ // to insert at the front end.
        if(q->front == 0){
            for(int i = q->rear; i >= q->front; i--){
                q->data[i + 1] = q->data[i];
            }
            q->rear++; // rear increments as all elements gets shifted to the right side.
            q->data[q->front] = k; // insertion.
        }

        else{ 
            q->front--; // to insert at the front when space is available.
            q->data[q->front] = k; // insertion.
        }
    }

    return 0;


}



int delete2(Deque *q, int *m, int pos){ // space complexity will be constant as after deleting shifts all elements to left side, so time complexity will be linear to the filled size of the queue.
    if(q->front == -1){
        printf("Queue is empty\n");
        return 1;
    }

    else if(q->front == q->rear){ // when queue has only one element.
        *m = q->data[q->front]; // returns the front element.
        q->front = q->rear = -1; // reseting the queue.
        return 0;
    }

    if(pos == 0){ // to delete from the front end.
            *m = q->data[q->front]; // returns the front element.
            // q->front++;
            for(int i = q->front + 1; i <= q->rear; i++){ // shifting all elements to left, front stays static and it never moves.
                q->data[i - 1] = q->data[i]; // shifting.
            }
            q->rear--; // rear shifts one place to the left.
    }

    else{ // to delete from the rear end.
        *m = q->data[q->rear]; // returns the rear element.
        q->rear--;
    }
    return 0;

}

void display(Deque *q){
    for(int i = q->front; i <= q->rear; i++){ // to display all the numbers between front and rear.
        printf("%d\t", q->data[i]);
    }
    printf("\n");
}


int main(){
    
    Deque q1;
    q1.front = q1.rear = -1; // setting up the queue.

    int err = insert(&q1, 1, 0);
    err = insert(&q1, 2, 0);
    err = insert(&q1, 3, 0);
    err = insert(&q1, 69, 1);
    int deleted_element;
    int err1 = delete2(&q1, &deleted_element, 0);
    err1 = delete2(&q1, &deleted_element, 0);
    err1 = delete2(&q1, &deleted_element, 1);

    // printf("deleted element: %d\n", deleted_element);
    // reverse(&q1);
    display(&q1);
}

