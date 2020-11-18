// insert(10){
//     push(s0, k);
// }

// delete2(){
//     if(s0 and s1 empty){
//         not possible
//     }

//     if(s1 is not empty){
//         pop(s1)
//     }
//     else{
//         while(s0 is not empty){
//             pop(s0, n)
//             push(s1, n)
//         }
//         pop(s1, n)
//     }
// }

// // write case for if s1 is filled up and s0 is completely empty

#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

typedef struct {
    int data[MAX];
    int top;
} STACK;


int push(STACK *S, int v){
    if(S->top == MAX - 1){
        printf("stack-overflow\n");
        return 1;
    }

    S->top++;
    S->data[S->top] = v;
    return 0;

}

int pop(STACK *S, int *k){
    if(S->top == -1){
        printf("stack-underflow\n");
        return 1;
    }

    *k = S->data[S->top];
    S->top--;
    return 0;
}

// max capacity of queue is 5 since it is made up of two stacks (one for insertion s[0] and one for deletion s[1]) of capacity 5 each
typedef struct {
    STACK s[2];
} QUEUE;

int is_stack_empty(STACK s) {
    return s.top == -1;
}

int enqueue(QUEUE* q, int val) {
    if (push(&q->s[0], val) != 0) {
        printf("QUEUE is full\n");
        return 1;
    }
    return 0;
}
int dequeue(QUEUE* q, int* del) {
    if (is_stack_empty(q->s[0]) && is_stack_empty(q->s[1])) {
        printf("QUEUE is empty\n");
        return 1;
    } else if (!is_stack_empty(q->s[1])) {
        pop(&q->s[1], del);
    } else {
        while (!is_stack_empty(q->s[0])) {
            pop(&q->s[0], del);
            push(&q->s[1], *del);
        }
        pop(&q->s[1], del);
    }
    return 0;
}


void display(STACK *S){
    STACK temp;
    temp.top = -1;
    while(S->top != -1){
        int popped_element;
        pop(S, &popped_element);
        printf("%d ", popped_element);
        push(&temp, popped_element);
    }
    printf("\n");

    while(temp.top != -1){
        int popped_element;
        pop(&temp, &popped_element);
        push(S, popped_element);
    }
}


int main() {
    QUEUE q;
    q.s[0].top = q.s[1].top = -1;
    int del;
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 6);

    printf("After enqueueing 6 times :\n");
    display(&q.s[0]);

    dequeue(&q, &del);
    dequeue(&q, &del);
    dequeue(&q, &del);

    printf("After dequeueing 3 times :\n");
    display(&q.s[1]);
}