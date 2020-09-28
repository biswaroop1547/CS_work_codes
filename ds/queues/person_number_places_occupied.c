#include<stdio.h>
#include<stdlib.h>
#include "../headers/queue/queue_arr.h"


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
        err = delete2(q, &m);
        if(err == 1){
            printf("Cannot delete anymore elements, queue is empty.\n");
            break;
        }
    }

}

int main(){
    
    Queue q1;
    q1.front = q1.rear = -1; // setting up the queue.

    person_number_places_queue_insert(&q1, 5);
    person_number_places_queue_insert(&q1, 6);
    person_number_places_queue_insert(&q1, 4);
    person_number_places_queue_front_delete(&q1);
    person_number_places_queue_front_delete(&q1);
    display(&q1);
    
}

