#include<stdio.h>
#include<stdlib.h>






struct node *find_max_recurr(struct node *root){
	if(root == NULL){
		return root;
	}

	else if(root->right != NULL){
		return find_max_recurr(root->right);
	}

	else{
		return root;
	}
}


main(){

	struct node *root = NULL;

	//insertion done.
	
	struct node *temp = find_max(root);

}
