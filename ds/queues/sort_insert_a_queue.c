#include<stdio.h>
#include<stdlib.h>
#include "../headers/queue/queue_arr.h"

// (Ascending order insert).
void sorted_insert(Queue *q, int k){
    Queue temp_q;
    temp_q.front = temp_q.rear = -1;
    if(q->rear == -1){ // if queue is empty.
        insert(q, k); // just normally insert.
    }

    else{ // if the queue has more than one element.
        int start = q->front, end = q->rear; // set the limits to iterate from.
        int dequeued_element;
        int flag = 1; // so that after the position to insert the element into is found and inserted in the middle, it can be changed to 0. Or if it is the biggest element then it will be inserted at last for that flag will remain unchanged.
        for(int i = start; i <= end; i++){ // iterating over the real queue and dequeueing it to sort it.
            delete2(q, &dequeued_element);
            if(dequeued_element > k && flag){ // if an element is found in the queue which is greater than the element to insert and flag = 1 means it is somewhere in the middle.
            // by changing the comparison from > to < we can make a queue which will store element in the descending order.
                insert(&temp_q, k); // insert it to temp queue.
                flag = 0; // change flag as it will be inserted in the middle and not at last.
            }
            insert(&temp_q, dequeued_element); // after that insert the dequeued element to the temp queue.
        }
        if(flag){ // if the element to insert will be at the end of the queue (i.e biggest).
            insert(&temp_q, k);
        }

        // for inserting back to real queue from the temp queue.
        start = temp_q.front, end = temp_q.rear; // iterating limits will be of temp queue and not of real queue as now the sizes will be different and we are putting the elements back.
        for(int i = start; i <= end; i++){
            delete2(&temp_q, &dequeued_element);
            insert(q, dequeued_element);
        }

    }
    
}


int main(){
    Queue q;
    q.front = q.rear = -1;
    sorted_insert(&q, 234);
    sorted_insert(&q, 532);
    sorted_insert(&q, 12);
    sorted_insert(&q, 99);
    sorted_insert(&q, -5); 

    display(&q);

    // should display : -5 12 99 234 532 
}