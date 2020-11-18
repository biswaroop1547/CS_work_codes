struct node *del(struct node *root, int k){
	
	if(root == NULL){ // when there is no root or the element is not present.
		return root;
	}

	else if(root->data < k){ // element lies in the right subtree.
		root->right = del(root->right, k);
		return root;
	}
	
	else if(root->data > k){ // element lies in the left subtree.
		root->left = del(root->left, k);
		return root;
	}

	else{ // when root data and k are equal

		if(root->right != NULL && root->left != NULL){ // when root has two child.
			struct node *temp = find_max(root->left);
			root->data = temp->data;
			root->left = del(root->left, temp);
			return root;
		}

		else if(root->right == NULL){ // when root has only left child.
			struct node *temp = root->left;
		}

		else{ // when root has only right child.
			struct node *temp = root->right;
		}

		free(root);
		return temp;
	}



}
