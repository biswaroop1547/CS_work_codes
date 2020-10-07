#include<stdio.h>
#include<stdlib.h>

#include "../headers/queue/queue_arr.h"
#define MAX 100


int push(Queue *q, int k, int active_queue){
    int err = insert(&q[active_queue], k);
    return err;
}


int pop(Queue *q, int *m, int *active_queue){
    int deleted_element;

    while(1){
        int p = delete2(&q[*active_queue], &deleted_element);
        if(q[*active_queue].rear == -1){ // if queue is empty.
            break;
        }

        else{
            insert(&q[(*active_element + 1) % 2], n);
        }
    }

    if(p == 1){ // if both the queue is empty and called pop.
        return p;
    }
    else{
        *m = *deleted_element; // last element of the queue.
        *active_element = (*active_element + 1) % 2; // to change the active queue.
        return p;
    }

}

int main(){
    int c = 0 // active queue track.
    Queue q[2];
    q[0].front = q[1].front = q[0].rear = q[1].rear = -1;
}