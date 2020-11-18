#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct{
    struct node *top;
} STACK;

typedef struct {
    STACK normal_stack, min_stack;
} EFFI_STACK;


int is_empty(STACK S){
    return S.top == NULL;
}

int get_top(STACK S){
    return S.top->data;
}

int push(STACK *S, int num){
    struct node *curr = (struct node *)malloc(sizeof(struct node));
    if(curr == NULL){
        printf("stack-overflow\n");
        return 1;
    }

    curr->data = num;
    curr->next = NULL;
    if(S->top == NULL){
        S->top = curr;
    }

    else{
        curr->next = S->top;
        S->top = curr;
    }

    return 0;

}

int pop(STACK *S, struct node **k){
    if(S->top == NULL){
        printf("stack-underflow\n");
        return 1;
    }

    *k = S->top;
    S->top = S->top->next;
    return 0;

}


void effi_push(EFFI_STACK *S, int num){
    
    if(is_empty(S->min_stack) && is_empty(S->normal_stack)){
        push(&S->normal_stack, num);
        push(&S->min_stack, num);
    }

    else{
        if(get_top(S->min_stack) >= num){
            push(&S->min_stack, num);
        }
        push(&S->normal_stack, num);
    }


}

void effi_pop(EFFI_STACK *S, struct node **k){
    if(get_top(S->normal_stack) == get_top(S->min_stack)){
        pop(&S->min_stack, k);
    }
    pop(&S->normal_stack, k);
}

int get_min(EFFI_STACK *S){
    return get_top(S->min_stack);
}


void display(EFFI_STACK S){
    while(S.normal_stack.top != NULL){
        struct node *popped_element;
        effi_pop(&S, &popped_element);

        printf("%d\t", popped_element->data);
    }
    printf("\n");
}



int main(){

    EFFI_STACK S1;

    S1.normal_stack.top = NULL;
    S1.min_stack.top = NULL;

    effi_push(&S1, 30);
    effi_push(&S1, 20);
    effi_push(&S1, 43);
    effi_push(&S1, 40);
    effi_push(&S1, 60);
    effi_push(&S1, 10);

    printf("After pushing 6 times :\n");
    display(S1);

    struct node *popped_element;

    effi_pop(&S1, &popped_element);
    effi_pop(&S1, &popped_element);

    printf("After popping 2 times :\n");
    display(S1);

    int min_element = get_min(&S1);
    printf("current min element in the stack - %d\n", min_element);

}