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

void display_nth_node_from_end(struct node *head, int pos_from_end){
    struct node *curr;
    int n = 0;
    
    for(curr = head; curr != NULL; curr = curr->next){
        n++;
    }

    int index = n - pos_from_end;

    if(index >= 0){
        n = 0;
        struct node *for_index = head;
        for(int i = 0; i < index; i++){
            for_index = for_index->next;
        }
        printf("%d\n", for_index->data);
    }
    else{
        printf("node on the position entered is not present.");
    }

}

int main(){
    struct node *curr;
    struct node *head = NULL;
    struct node *tail = NULL;

    int n, to_display_from_end;
    printf("Size of the linked list: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    create_ll(&head, &tail, &curr, n); 

    printf("The data stored in the linked list is:\n");
    display(head);

    printf("Enter the node to display from end: ");
    scanf("%d", &to_display_from_end);
    printf("The data stored in %dth node from end:\n", to_display_from_end);
    display_nth_node_from_end(head, to_display_from_end);
    
}