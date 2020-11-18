#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void create_ll(struct node **head, struct node **tail, struct node **curr, int n){
    for(int i = 0; i < n; i++){
        *curr = (struct node*)malloc(sizeof(struct node));
        scanf(" %d", &(*curr)->data);
        (*curr)->next = NULL;

        if(*head == NULL){
            *head = *curr;
            *tail = *curr;
        }

        else{
            (*tail)->next = *curr;
            *tail = *curr;
        }
    }
}

void display(struct node *head){
    struct node *curr;
    for(curr = head; curr != NULL; curr = curr->next){
        printf("%d ", curr->data);
    }
    printf("\n");
}


void reverse(struct node **head){
    struct node *curr;

    struct node *prev = NULL; 
    struct node *current = *head; 
    struct node *next = NULL; 
    while (current != NULL) { 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } 
    *head = prev; 
}



void insert(struct node **head, int data, int pos){
    struct node *curr, *ptr;
    curr = (struct node *)malloc(sizeof(struct node));
    curr->data = data;
    curr->next = NULL;

    if(*head == NULL){
        *head = curr;
    }

    else if(pos == 0){
        curr->next = *head;
        *head = curr;
    }

    else{
        ptr = *head;
        while(pos > 1 && ptr->next != NULL){
            ptr = ptr->next;
            pos--;
        }

        curr->next = ptr->next;
        ptr->next = curr;
    }
}

void delete(struct node **head, int pos){
    struct node *ptr, *prev;
    if(*head == NULL){
        printf("List is empty\n");
    }
    else if(pos == 0){
        ptr = *head;
        *head = ptr->next;
        free(ptr);
    }
    else{
        ptr = *head;
        int i = 0;
        while(i < pos && ptr != NULL){
            prev = ptr;
            ptr = ptr->next;
            i++;
        }

        if(ptr == NULL){
            printf("Not available in the list\n");
        }
        else{
            prev->next = ptr->next;
            free(ptr);
        }
    }
}

int main(){
    struct node *curr;
    struct node *head = NULL;
    struct node *tail = NULL;

    int n;
    printf("Size of the linked list: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    create_ll(&head, &tail, &curr, n); 

    printf("The data stored in the linked list is:\n");
    display(head);

    reverse(&head);

    printf("The data stored in the linked list after reversing:\n");
    display(head);
}