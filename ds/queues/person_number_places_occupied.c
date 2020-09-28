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


int delete(Queue *q, int *m){ // the space complexity will keep increasing but time complexity will be constant.
    if(q->front == -1){
        printf("Queue is empty\n");
        return 1;
    }

    else if(q->front == q->rear){ // if only one element is present in the queue.
        *m = q->data[q->front]; // front comes out.
        q->front = q->rear = -1; // reseting queue.
    }

    else{ //  if more than one element is present in the queue.
        *m = q->data[q->front]; // front comes out.
        q->front++;    
    }

    return 0;

}


int delete2(Queue *q, int *m){ // space complexity will be constant as after deleting shifts all elements to left side, so time complexity will be linear to the filled size of the queue.
    if(q->front == -1){
        printf("Queue is empty\n");
        return 1;
    }

    else if(q->front == q->rear){ // when queue has only one element.
        *m = q->data[q->front]; // returns the front element.
        q->front = q->rear = -1; // reseting the queue.
    }

    else{
        *m = q->data[q->front]; // returns the front element.
        // q->front++;
        for(int i = q->front + 1; i <= q->rear; i++){ // shifting all elements to left, front stays static and it never moves.
            q->data[i - 1] = q->data[i]; // shifting.
        }
        q->rear--; // rear shifts one place to the left.
    }

    return 0;

}

// program to say insert 2 then 2 should be inserted two times, say 5 then 5 should be inserted 5 times etc.

void person_number_places_queue_insert(Queue *q, int k){
    int err;
    for(int i = 0; i < k; i++){
        err = insert(q, k);
        if(err == 1){
            printf("Cannot insert anymore elements, queue is full.\n");
            break;
        }
    }
}

// program to say delete 2 then 2 should be deleted two times, say 5 then 5 should be deleted 5 times etc.

void person_number_places_queue_front_delete(Queue *q){
    int err, m;
    int k = q->data[q->front];
    for(int i = 0; i < k; i++){
        err = delete(q, &m);
        if(err == 1){
            printf("Cannot delete anymore elements, queue is empty.\n");
            break;
        }
    }

}

void display(Queue *q){
    for(int i = q->front; i <= q->rear; i++){
        printf("%d\t", q->data[i]);
    }
    printf("\n");
}

int main(){
    
    Queue q1;
    q1.front = q1.rear = -1; // setting up the queue.

    // int err = insert(&q1, 5);
    int deleted_element;
    // int err1 = delete2(&q1, &deleted_element);
    // int err1 = delete(&q1, &deleted_element);
    person_number_places_queue_insert(&q1, 5);
    person_number_places_queue_insert(&q1, 6);
    person_number_places_queue_insert(&q1, 4);
    person_number_places_queue_front_delete(&q1);
    person_number_places_queue_front_delete(&q1);
    display(&q1);
    


    // printf("deleted element: %d\n", deleted_element);
}

