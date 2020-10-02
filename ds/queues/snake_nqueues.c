#include<stdio.h>
#include<stdlib.h>


#define MAX 4

typedef struct node{
    int data[MAX];
    int front;
    int rear;
    struct node *next, *prev;

} Queue_Node;  // a doubly ended node which stores a queue in it.

typedef struct {
    Queue_Node *head;

} NQueue; // ADT for a linked list of queue nodes.


int enqueue(Queue_Node *q, int k){
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


int dequeue(Queue_Node *q, int *m){
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


int enqueue_snake_queue_wrapper(Queue_Node **head_queue, int k){
    Queue_Node *curr;
    if(*head_queue == NULL){
        Queue_Node *init_node = (Queue_Node *) malloc(sizeof(Queue_Node));
        init_node->front = init_node->rear = -1;
        *head_queue = init_node;
        init_node->next = NULL;
        (*head_queue)->next = (*head_queue)->prev = NULL;
    }

    for(curr = *head_queue; curr->next != NULL; curr = curr->next){
        if(curr->rear != MAX - 1){
            break;
        }
    }

    if(curr->rear != MAX - 1){ // current queue node not filled.
        enqueue(curr, k); // just insert element to that queue node.
    }

    else{ // when the queue node is full and it is the last node.
        Queue_Node *new_node = (Queue_Node *) malloc(sizeof(Queue_Node));
        new_node->front = new_node->rear = -1;
        new_node->next = NULL;
        new_node->prev = curr;
        curr->next = new_node;
        enqueue(new_node, k);
    }
}

void enqueue_snake_queue(NQueue *snake_queue, int k){
    int err = enqueue_snake_queue_wrapper(&(snake_queue->head), k); 

}


int dequeue_snake_queue_wrapper(Queue_Node **head_queue, int *m){
    if(*head_queue == NULL){
        printf("Queue is empty\n");
        return 1;
    }

    dequeue(*head_queue, m);

    Queue_Node *curr_node = *head_queue, *temp = *head_queue;
    int flag = 0;
    for(curr_node = *head_queue; curr_node->next != NULL && curr_node->rear != MAX - 1; curr_node = curr_node->next){
        temp = curr_node;
        dequeue(curr_node->next, m); // take out element from the next queue node.
        enqueue(curr_node, *m); // insert dequeued element to the previous queue node.
        flag = 1;
    }

    if(curr_node->front == -1 && flag){
        free(curr_node);
        temp->next = NULL;
        curr_node = NULL;
    }
}


void dequeue_snake_queue(NQueue *snake_queue){
    int m;
    int err = dequeue_snake_queue_wrapper(&(snake_queue->head), &m);
}


void display_snake_queue(NQueue *snake_queue){
    if(snake_queue->head->front == -1){
        return;
    }

    Queue_Node *curr;
    int alt = 0;
    for(curr = snake_queue->head; curr != NULL; curr = curr->next){
        if(alt % 2 == 0){
            for(int i = curr->front; i <= curr->rear; i++){
                printf("%d\t", curr->data[i]);
            }
            printf("\n");
        }
        else{
            for(int i = curr->rear; i >= curr->front; i--){ // to reverse the display for the queue so that the whole structure can look like a snake queue.
                printf("%d\t", curr->data[i]);
            }
            printf("\n");
        }

        alt++;
    }
}

int main(){
    NQueue snake_queue;
    snake_queue.head = NULL;

    enqueue_snake_queue(&snake_queue, 10);
    enqueue_snake_queue(&snake_queue, 14);
    enqueue_snake_queue(&snake_queue, 76);
    enqueue_snake_queue(&snake_queue, 89);
    enqueue_snake_queue(&snake_queue, 79);
    enqueue_snake_queue(&snake_queue, 2);
    enqueue_snake_queue(&snake_queue, 99);
    enqueue_snake_queue(&snake_queue, 123);
    enqueue_snake_queue(&snake_queue, 225);

    printf("After enqueue operations:\n");
    display_snake_queue(&snake_queue);

    dequeue_snake_queue(&snake_queue);
    dequeue_snake_queue(&snake_queue);

    printf("After dequeuing two times:\n");
    display_snake_queue(&snake_queue);
    
}