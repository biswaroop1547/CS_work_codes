#include<stdio.h>
#include<stdlib.h>

#include "../headers/queue/queue_arr.h"

#define MAX 4

typedef struct node{
    int data[MAX];
    int front;
    int rear;
    struct node *next, *prev;

} Queue_Node;

typedef struct {
    Queue_Node *head;

} NQueue;


int enqueue_snake_queue(Queue_Node **head_queue, int k){
    
}

void enqueue_wrapper(NQueue *snake_queue, int k){
    // int err = enqueue_snake_queue(&(snake_queue->head), k);
    Queue_Node *curr_node = snake_queue->head;
    

}

void display_snake_queue(NQueue *snake_queue){
    Queue_Node *curr;
    for(curr = snake_queue->head; curr != NULL; curr = curr->next){
        for(int i = curr->front; i <= curr->rear; i++){
            printf("%d\t", curr->data[i]);
        }
        printf("\n");
    }
}

int main(){
    NQueue snake_queue;
    snake_queue.head = NULL;
    Queue_Node *ptr = snake_queue.head;
    enqueue_wrapper(&snake_queue, 10);
    enqueue_wrapper(&snake_queue, 14);
    enqueue_wrapper(&snake_queue, 76);
    enqueue_wrapper(&snake_queue, 89);
    enqueue_wrapper(&snake_queue, 79);
    enqueue_wrapper(&snake_queue, 2);
    enqueue_wrapper(&snake_queue, 99);
    enqueue_wrapper(&snake_queue, 123);
    // enqueue_snake_queue(&snake_queue.head, 10);
    // enqueue_snake_queue(&snake_queue.head, 14);
    // enqueue_snake_queue(&snake_queue.head, 76);
    // enqueue_snake_queue(&snake_queue.head, 89);
    // enqueue_snake_queue(&snake_queue.head, 79);
    // enqueue_snake_queue(&snake_queue.head, 2);

    // display_snake_queue(&snake_queue);
    printf("%d\n",ptr->data[0]);
    
}