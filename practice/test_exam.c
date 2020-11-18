
#include<stdio.h>
#include<stdlib.h>

struct node{
    char student_name[20];
    char branch[10];
    int roll_no;
    float cgpa;
    struct node *next;
    struct node *prev;
};

void create_ll(struct node **head, int n){
    for(int i = 0; i < n; i++){
        struct node *curr = (struct node*)malloc(sizeof(struct node));
        printf("Enter student name: \n");
        scanf("%[^\n]%*c", &curr->student_name);
        printf("Enter branch: \n");
        scanf("%[^\n]%*c", &curr->branch);
        printf("Enter roll no: \n");
        scanf(" %d", &curr->roll_no);
        printf("Enter cgpa: \n");
        scanf(" %f", &curr->cgpa);
        curr->next = NULL;
        struct node *ptr;
        if(*head == NULL){
            *head = curr;
            ptr = curr;
        }

        else{
            curr->prev = ptr;
            ptr->next = curr;
            ptr = curr;
        }
    }
}


void insert(struct node **head, int pos, char *student_name, char *branch, int roll_no, float cgpa){
    struct node *curr, *ptr;
    curr->student_name = student_name;
    for
    curr->branch = branch;
    curr->roll_no = roll_no;
    curr->cgpa = cgpa;
    curr->next = curr->prev = NULL;
    
    if(*head == NULL){
        *head = curr;
    }
    else if(pos == 0){
        curr->next = *head;
        (*head)->prev = curr;
        *head = curr;
    }
    else{
        ptr = *head;
        while(pos > 1 && ptr->next != NULL){
            ptr = ptr->next;
            pos--;
        }
        if(ptr->next == NULL){
            curr->prev = ptr;
            curr->next = ptr->next;
            ptr->next = curr;
        }
        else{
            curr->prev = ptr;
            curr->next = ptr->next;
            ptr->next->prev = curr; // NULL->prev cannot be executed that's why if and else statement codes cannot be combined.
            ptr->next = curr;
        }
    }
}

void display_student_list(struct node *head){
    if(head == NULL){
        return;
    }
    struct node *curr;
    for(curr = head; curr != NULL; curr = curr->next){
        printf("%s\n", curr->student_name);
        printf("%d\n\n", curr->roll_no);
    }
    printf("\n");
}


void bubbleSort(struct node *head) 
{ 
    int swapped, i; 
    struct node *ptr1 = NULL; 
    struct node *lptr = NULL; 
   
    //Checking for empty list
    if (head == NULL) 
        return; 
   
    do
    { 
        swapped = 0; 
        ptr1 = head; 
   
        while (ptr1->next != lptr) 
        { 
            if (ptr1->roll_no > ptr1->next->roll_no) 
            {  
                swap(ptr1->roll_no, ptr1->next->roll_no); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 

void reverse_display(struct node *head){
    if(head == NULL){
        return;
    }
    struct node *curr;
    curr = head;
    while(curr->next){
        curr = curr->next;
    }

    for(struct node *tail = curr; tail != NULL; tail = tail->prev){
        printf("%d ", tail->data);
    }
    printf("\n");
}



void delete_student_records_with_cgpa(struct node **head){
    if(head == NULL){
        return;
    }
    struct node *curr;
    int pos = 0;
    for(curr = head; curr != NULL; curr = curr->next){
        if(curr->cgpa == 6.0){
            delete_node(head, pos);
        }
        pos++;
    }
    printf("\n");
}

void delete_node(struct node **head, int pos){
    struct node *prv, *ptr;

    if(*head == NULL){
        printf("List is empty\n");
    }
    else if(pos == 0){
        ptr = *head;
        if(ptr->next != NULL){
            *head = ptr->next;
            (*head)->prev = NULL;
            free(ptr);
        }
        else{
            // *head = NULL;
            *head = (*head)->next;
            free(ptr);
        }
    }
    else{
        ptr = *head;
        int i = 0;
        while(i < pos && ptr != NULL){
            prv = ptr;
            ptr = ptr->next;
            i++;
        }
        if(ptr == NULL){
            printf("Not available in the list\n");
        }
        else{
            if(ptr->next == NULL){
                prv->next = NULL;
                free(ptr);
            }
            else{
                prv->next = ptr->next;
                ptr->next->prev = prv;
                free(ptr);
            }
        }
    }
}

void create_two_lists(struct node **cse_list, struct node **it_list, struct node **head){
    if(*head == NULL){
        return;
    }
    struct node **curr;
    int it_list_len = 0;
    int cse_list_len = 0;
    for(*curr = *head; *curr != NULL; *curr = (*curr)->next){
        if((*curr)->branch[0] == 'I' && (*curr)->branch[0] == 'T'){
            insert(it_list, it_list_len);
            it_list_len++;
        }
        else if((*curr)->branch[0] == 'C' && (*curr)->branch[1] == 'S' && (*curr)->branch[0] == 'E'){
            insert(cse_list, cse_list_len);
            cse_list_len++;
        }
    }

}

int main(){

    struct node *head = NULL;
    struct node *cse_list = NULL;
    struct node *it_list = NULL;

    int n;
    printf("Size of the linked list: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    create_ll(&head, n);

    // to sort the element
    bubbleSort(head);

    // delete all student records having 6.0 cgpa
    delete_student_records_with_cgpa(&head);

    //create two different lists for cse and it.
    create_two_lists(&cse_list, &it_list, &head);

}
