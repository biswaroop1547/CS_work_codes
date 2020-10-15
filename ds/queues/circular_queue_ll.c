#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct {
    // struct node *front; // front is not needed.
    struct node *rear; // can be done just with rear.
} C_QUEUE;


int enqueue(C_QUEUE *q, int k){
    struct node *curr = (struct node *)malloc(sizeof(struct node));
    if(curr == NULL){
        printf("Memory is full!\n");
        return 1;
    }
    curr->data = k;
    curr->next = NULL;

    if(q->rear == NULL){ // if no node is present.
      q->rear = curr;
      q->rear->next = curr;  
    }

    else{ // if one or more than one nodes is present.
        curr->next = q->rear->next;
        q->rear->next = curr;
        q->rear = curr;
    }

    return 0;
}


int dequeue(C_QUEUE *q, int *m){
    if(q->rear == NULL){ // if no node is present.
        printf("Queue is empty\n");
        return 1;
    }

    if(q->rear->next == q->rear){ // if only one node is present.
        *m = q->rear->data;
        free(q->rear);
        q->rear = NULL;
    }

    else{ // if more than one node is present.
        *m = q->rear->data;
        struct node *ptr = q->rear->next;
        q->rear->next = q->rear->next->next;
        free(ptr);
    }

    return 0;
}

void display(C_QUEUE *q){
    if(q->rear == NULL){
        return;
    }

    struct node *ptr = q->rear->next;
    for(ptr = q->rear->next; ptr->next != q->rear->next; ptr = ptr->next){ // to display the circular queue.
        printf("%d\t", ptr->data);
    }
    printf("%d\n", ptr->data);
}


int main(){

    C_QUEUE q = {NULL};
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    printf("after enqueueing :\n");
    display(&q);

    int dequeued_element;
    dequeue(&q, &dequeued_element);
    dequeue(&q, &dequeued_element);

    printf("after dequeueing :\n");
    display(&q);
}