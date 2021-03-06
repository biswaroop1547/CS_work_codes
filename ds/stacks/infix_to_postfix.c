#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct { 
    char data[MAX];
    int top;
} STACK; 

void push(STACK* s, int val) {
    s->top++;
    s->data[s->top] = val;
}

void pop(STACK* s, int* del) {
    *del = s->data[s->top];
    s->top--;
}

int is_operator(char ch) {
    char OPERATORS[] = "+-*/^()\0";
    for (int i = 0; OPERATORS[i] != '\0'; ++i) {
        if (ch == OPERATORS[i]) {
            return 1;
        }
    }
    return 0;
}

int is_opening_brace(char op) {
    return op == '(';
}

int is_closing_brace(char op) {
    return op == ')';
}

int priority_val(char op) { 
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

int is_low_to_high_priority(char op1, char op2) { // it is a function which checks given two input operators and returns true if the operator 1 has higher priority than the operator 2. Or returns 0 if it doesn't
    if (priority_val(op1) < priority_val(op2)) {
        return 1;
    }
    return 0;
}

void infix_to_postfix(char* infix, char* postfix) {
    int i, j;
    i = j = 0;
    STACK s;  // initialize a stack 
    s.top = -1;
    int del;
    while (infix[i] != '\0') {  // run a loop while the input doesn't reach end
        if (is_operator(infix[i])) { // inside the loop check if element is an operator otherwise just append the element to the output.
            if (is_opening_brace(infix[i])) { // if it is an operator then check if it has an opening brace, then push that element to the stack.
                push(&s, infix[i]);
            } else if (is_closing_brace(infix[i])) { // or check if it has a closing brace, then pop the stack and run a loop till a closing brace is found, while keep inserting the popped element to the output by popping the stack.
                pop(&s, &del);
                while (!is_opening_brace(del)) {
                    postfix[j++] = del;
                    pop(&s, &del);
                }
            } else { // otherwise check if the stack is empty, then just push the element to the stack.
                if (s.top == -1) {
                    push(&s, infix[i]);
                } else { // if the stack is not empty then pop an element from the stack then check if the element popped is an opening brace or if it is an operator which has a low priority compared to the current element.
                    pop(&s, &del);
                    if (is_opening_brace(del) || is_low_to_high_priority(del, infix[i])) { // if yes then push the popped element and the current element to the stack respectively.
                        push(&s, del);       // pushing back removed operator since stack will remain same
                        push(&s, infix[i]);  // pushing current operator in the stack
                    } else { // otherwise append the popped element to the output.
                        postfix[j++] = del;  // pushing deleted operator to our final answer
                        --i;                 // checking if the now previous operator complies with the current operator
                    }
                }
            }
        } else {
            postfix[j++] = infix[i];  // pushing operands to our final answer
        }
        ++i;
    }
    while (s.top != -1) { // lastly while stack isnt empty, keep popping the elements from it and append it to the output.
        pop(&s, &del);
        postfix[j++] = del;
    }
}

int main(){
    char infix[100], postfix[100];
    scanf("%[^\n]%*c", infix);
    infix_to_postfix(&infix, &postfix);
    printf("%s", postfix);
    return 0;
}