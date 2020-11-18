#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};


void create(struct node **h, int n, int *arr_val)
{
    struct node *curr, *ptr;
    for(int i=0; i<n; i++){
        curr = (struct node *)malloc(sizeof(struct node));
        curr->data = arr_val[i];
        curr->next = NULL;
        if(*h == NULL)
        {
            *h = curr;
            ptr = curr; 
        }
        else
        {
            ptr->next = curr;
            ptr = curr;
        }
    }
}




void intersection_wrapper(struct node *head1, struct node *head2, int *intersection_node_num, int *dist_from_longer_branch, int *dist_from_shorter_branch){
    

    if(head1 == NULL || head2 == NULL){
        return;
    }

    *intersection_node_num = 1;
    

    int L1 = 0, L2 = 0;
    struct node *curr, *curr2;
    
    for(curr = head1; curr != NULL; curr = curr->next){
        L1++;
    }

    for(curr = head2; curr != NULL; curr = curr->next){
        L2++;
    }

    int longer_branch, diff;

    if(L1 >= L2){
        diff = L1 - L2;
        curr = head1;
        curr2 = head2;
        if(L1 == L2){
            printf("head1 and head2 branches are equal in sizes.\n");
        }
        else{
            printf("longer branch : head1\n");
            printf("shorter branch : head2\n");
        }
    }
    else{
        diff = L2 - L1;
        curr = head2;
        curr2 = head1;
        printf("longer branch : head2\n");
        printf("shorter branch : head1\n");
    }

    for(int i = 0; i < diff; i++){
            curr = curr->next;
        }

    while(curr != curr2){
        curr = curr->next;
        curr2 = curr2->next;
        (*intersection_node_num)++;
    }

    *dist_from_shorter_branch = *intersection_node_num;
    *dist_from_longer_branch = *intersection_node_num + diff;

}

int find_ll_intersection(struct node *head1, struct node *head2){

    int a = -1;
    int b = -1;
    int c = -1;

    intersection_wrapper(head1, head2, &a, &b, &c);
    // printf("hi\n");
    printf("intersection_node_num : %d\n", a);
    printf("dist_from_longer_branch : %d\n", b);
    printf("dist_from_shorter_branch : %d\n", c);

    return 0;

}

int main(){

    int n1 = 5;
    int arr1[] = {1, 2, 3, 4, 5};

    int n2 = 5;
    int arr2[] = {6, 7, 8, 9, 10};

    struct node *head1 = NULL;
    struct node *head2 = NULL;

    create(&head1, n1, arr1);
    create(&head2, n2, arr2);

    struct node *tail2 = head2;

    for(tail2 = head2; tail2 != NULL; tail2 = tail2->next){
        if(tail2->next == NULL){
            tail2->next = head1->next->next;
            break;
        }
    }

    find_ll_intersection(head1, head2);

    return 0;
}