#include<stdio.h>
#include<stdlib.h>

#include "../headers/queue/queue_arr.h"


int is_empty(Queue *q){ // if the queue is empty then return 1 else return 0.
    if(q->rear == -1){
        return 1;
    }
    return 0;
}

int push(Queue *q, int k, int active_queue){
    int err = insert(&q[active_queue], k);
    return err;
}


int pop(Queue *q, int *m, int *active_queue){
    int deleted_element;

    int p = is_empty(&q[*active_queue]);
    
    if(p == 1){ // if both the queue is empty and called pop.
        return p;
    }
    
    while(1){
        p = delete2(&q[*active_queue], &deleted_element);
        if(q[*active_queue].rear == -1){ // if queue is empty.
            break;
        }
        else{
            insert(&q[(*active_queue + 1) % 2], deleted_element); // keep inserting to the other queue.
        }
    }
    
    *m = deleted_element; // last element of the queue.
    *active_queue = (*active_queue + 1) % 2; // to change the active queue.
    return p;
    

}

int main(){
    int c = 0; // active queue track.
    Queue q[2];
    q[0].front = q[1].front = q[0].rear = q[1].rear = -1;

    push(q, 10, c);
    push(q, 20, c);
    push(q, 30, c);
    push(q, 40, c);

    int popped_element;

    pop(q, &popped_element, &c);
    printf("%d\n", popped_element);

    pop(q, &popped_element, &c);
    printf("%d\n", popped_element);

    pop(q, &popped_element, &c);
    printf("%d\n", popped_element);
    
}