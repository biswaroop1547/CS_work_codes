#include<stdio.h>
#include<stdlib.h>
#define MAX 100

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


void order_insert(STACK *S, int v){
    STACK S2;
    S2.top = -1;
    
    int popped_element;

    while(1){
        
        if(S->top == -1){ // if the stack is empty
            push(S, v);
            break;
        }

        pop(S, &popped_element);
        if(popped_element >= v){
            push(S, popped_element);
            push(S, v);
            break;
        }

        else{
            push(&S2, popped_element);
        }
    }

    while(S2.top != -1){
        pop(&S2, &popped_element);
        push(S, popped_element);
    }
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



void sort_stack(STACK *S){
    STACK temp;
    temp.top = -1;

    if(S->top == -1){ // if the stack is empty
        return;
    }

    int highest_element = S->data[S->top];
    int deleted_element;
    int num = 0;
    
    while(S->top != -1){
        pop(S, &deleted_element);
        if(deleted_element >= highest_element){
            highest_element = deleted_element;
        }
        push(&temp, deleted_element);
        num++;
    }

    while(num){
        int occurance = 0;
        for(int i = 0; i < num; i++){
            pop(&temp, &deleted_element);
            if(deleted_element != highest_element || occurance != 0){
                push(S, deleted_element);
            }
            else{
                occurance++;
            }
        }

        push(&temp, highest_element);

        if(S->top != -1){
            highest_element = S->data[S->top];
        }
        while(S->top != -1){
            pop(S, &deleted_element);
            if(deleted_element >= highest_element){
                highest_element = deleted_element;
            }
            push(&temp, deleted_element);
        }
        num--;
    }

    while(temp.top != -1){
        pop(&temp, &deleted_element);
        push(S, deleted_element);
    }
}

int main(){
    STACK S1;
    S1.top = -1;

    int arr[] = {10, 9, 8, 2, 1, 5, 4, 10, 78, 88, 9, 10};
    for(int i = 0; i < 12; i++){
        push(&S1, arr[i]);
    }

    printf("Before sorting the stack : ");
    display(&S1);

    sort_stack(&S1);

    printf("After sorting the stack : ");
    display(&S1);

}