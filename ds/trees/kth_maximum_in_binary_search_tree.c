#include<stdio.h>
#include<stdlib.h>


struct node {
	int data;
	struct node *left, *right;
};


struct node *insert(struct node *root, int k){
	
	if(root == NULL){
		struct node *curr = (struct node *)malloc(sizeof(struct node));
		curr->left = curr->right = NULL;
		curr->data = k;
		return curr;
	}

	else if(root->data < k){
		
		root->right = insert(root->right, k);
		return root;
	}

	else if(root->data > k){ 

		root->left = insert(root->left, k);
		return root;
	}
	
	// if there are no duplicates.
}


void inorder(struct node *root){ // if inorder prints in sorted order then insertion is right.
	if(root == NULL){
		return;
	}

	inorder(root->left);
	printf("%d\t", root->data);
	inorder(root->right);

}



void kth_max_element(struct node *root, int k, int *kth_element){
	
    static int element = 1;

    if(root == NULL){
		return;
	}

	kth_max_element(root->right, k, kth_element);
    if(element == k){
        *kth_element = root->data;
    }
    element++;
	kth_max_element(root->left, k, kth_element);
}


int main(){

	struct node *root = NULL;

	root = insert(root, 42);
	root = insert(root, 23);
	root = insert(root, 12);
	root = insert(root, 19);
	root = insert(root, 58);
	root = insert(root, 2);
    root = insert(root, 69);

    printf("Inorder : ");
    inorder(root);
    printf("\n");
    
    int k;
    printf("Enter the value of kth maximum element to find : ");
    scanf("%d", &k);

	int kth_max;
    kth_max_element(root, k, &kth_max);

    printf("\nThe kth maximum element is : %d\n", kth_max);

    return 0;

}
