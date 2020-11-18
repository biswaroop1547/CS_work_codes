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


int main(){

	struct node *root = NULL;

	root = insert(root, 42);
	root = insert(root, 23);
	root = insert(root, 12);
	root = insert(root, 19);
	root = insert(root, 58);
	root = insert(root, 2);

	inorder(root);

}
