#include<stdio.h>
#include<stdlib.h>
#include "../headers/queue/queue_ll.h"

/* Program where there will be a male queue and a female queue, while enqueing it should enqueue according to the input provided which will say male or female queue.
  While dequeing it should do it alternately by saving which queue to deque next somewhere. */

void enqueue_to_male_female_queue(Queue *male_q, Queue *female_q, int k, int flag){
    int err;
    if(flag == 0){ // flag is 0 means saying to enqueue to a male queue.
        err = insert(male_q, k);
    }
    else{ // else enqueue to a female queue.
        err = insert(female_q, k);
    }
}

void dequeue_from_male_female_queue(Queue *male_q, Queue *female_q, int *deleted_state){
    int err, deleted_num;
    if(*deleted_state == 0){ // 0 means need to dequeue the male queue.
        err = delete1(male_q, &deleted_num);
        if(err == 1){ // err is 1 when the male queue here is empty so dequeing the female queue now.
            err = delete1(female_q, &deleted_num);
            
        }
        *deleted_state = 1; // for alternate dequeing, changing it to dequeue from the female queue next.
    }
    else{ // state = 1 means we need to dequeue from the female queue.
        err = delete1(female_q, &deleted_num); 
        if(err == 1){ // err is 1 when the female queue here is empty so dequeing the male queue now.
            err = delete1(male_q, &deleted_num);
        }
        *deleted_state = 0; // for alternate dequeing, changing it to dequeue from the male queue next.
    }
}

int main(){

    Queue male_queue, female_queue; // declaring the two queues.
    male_queue.front = male_queue.rear = NULL;
    female_queue.front = female_queue.rear = NULL;

    int flag = 0; // 0 for male and 1 for female, used at enqueuing time to select which queue.
    int deleted_state = 0; // (same rule as above) for the state which can save so which queue to dequeue next.

    enqueue_to_male_female_queue(&male_queue, &female_queue, 10, 0);
    enqueue_to_male_female_queue(&male_queue, &female_queue, 20, 1);
    enqueue_to_male_female_queue(&male_queue, &female_queue, 30, 0);
    enqueue_to_male_female_queue(&male_queue, &female_queue, 40, 1);
    enqueue_to_male_female_queue(&male_queue, &female_queue, 50, 1);
    enqueue_to_male_female_queue(&male_queue, &female_queue, 60, 1);

    dequeue_from_male_female_queue(&male_queue, &female_queue, &deleted_state);
    dequeue_from_male_female_queue(&male_queue, &female_queue, &deleted_state);
    dequeue_from_male_female_queue(&male_queue, &female_queue, &deleted_state);
    dequeue_from_male_female_queue(&male_queue, &female_queue, &deleted_state);

    display(&male_queue);
    display(&female_queue);


}

