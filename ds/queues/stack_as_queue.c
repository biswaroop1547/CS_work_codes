#include<stdio.h>
#include<stdlib.h>

#define MAX 1000
typedef struct {
    int data[MAX]; // which will hold the elements.
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


int delete1(Queue *q, int *m){ // the space complexity will keep increasing but time complexity will be constant.
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


void reverse(Queue *q){ // to reverse a queue, by dequeing and pushing the elements to a stack and then popping them back at queue at last one by one.
    if(q->front == -1){
        printf("Queue is empty\n");
        return;
    }

    int start = q->front; // start index of the queue.
    int end = q->rear - 1; // end index of the queue.
    int front_popped_element, err;
    int stack[MAX]; // stack taken just to work for this program.
    for(int i = start; i <= end; i++){
        err = delete2(q, &front_popped_element); //dequeing each element from the queue.
        stack[i] = front_popped_element; // pushing each dequed elelemt to the stack.
    }

    for(int i = end; i >= start; i--){
        front_popped_element = stack[i]; // popping each element from the stack.
        err = insert(q, front_popped_element); //enqueing each element to the queue.
    }
}

void display(Queue *q){
    if(q->rear == -1){
        printf("Queue is empty\n");
        return;
    }
    for(int i = q->front; i <= q->rear; i++){ // to display all the numbers between front and rear.
        printf("%d\t", q->data[i]);
    }
    printf("\n");
}


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

    printf("After pushing 4 times :\n");
    display(&q[c]);

    int popped_element;

    pop(q, &popped_element, &c);
    pop(q, &popped_element, &c);
    pop(q, &popped_element, &c);

    printf("After popping 3 times :\n");
    display(&q[c]);


    
}