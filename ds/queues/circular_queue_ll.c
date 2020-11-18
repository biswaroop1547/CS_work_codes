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
    struct node *curr = (struct node *)malloc(sizeof(struct node)); // take a curr node
    if(curr == NULL){ // if memory cannot be allocated for curr node then the memory is full 
        printf("Memory is full!\n");
        return 1;
    }
    curr->data = k; // otherwise set its data to the value passed
    curr->next = NULL; // and set its next pointer to null.

    if(q->rear == NULL){ // if no node is present.
      q->rear = curr;   // make curr the rear of the node
      q->rear->next = curr;  // and set the next pointer of the rear of the queue to the curr
    }

    else{ // otherwise if one or more than one nodes is present.
        curr->next = q->rear->next; // then set the next pointer of the curr to the pointer that the next pointer of the rear of the queue is pointing to.
        q->rear->next = curr; // then set the next pointer of the rear of the queue to curr node.
        q->rear = curr; // finally set the rear of the queue to curr.
    }

    return 0;
}


int dequeue(C_QUEUE *q, int *m){
    if(q->rear == NULL){ // if no node is present and the rear of the queue points to null
        printf("Queue is empty\n");
        return 1;
    }

    if(q->rear->next == q->rear){ // if only one node is present, just free the node that the rear of the queue is pointing to.
        *m = q->rear->data;
        free(q->rear);
        q->rear = NULL;
    }

    else{ // if more than one node is present, make a new pointer which points to the next pointer of rear of the queue. Then point the next pointer of the rear of the queue to the next of next pointer of the rear of the queue. Then free the ptr i.e the node which we had initialised 2 steps before.
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
    printf("after enqueueing 4 times :\n");
    display(&q);

    int dequeued_element;
    dequeue(&q, &dequeued_element);
    dequeue(&q, &dequeued_element);

    printf("after dequeueing 2 times :\n");
    display(&q);
}