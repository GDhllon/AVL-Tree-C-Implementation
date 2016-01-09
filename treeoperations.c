/*Name: Gary Dhillon 
 * Date: Monday, November 24, 2014 
 * Assignment 4*/

#include "a4.h"

TreeNode * newNode(char * key){/*New node*/
	
	TreeNode * node = malloc(sizeof(TreeNode));
	node->key = malloc(sizeof(char)*10);
	strcpy(node->key, key);
	node->frequency = 1;
	node->height = 0;
	node->balance = 0;
	node->left = NULL;
	node->right = NULL;
	
	return(node);
}
	

TreeNode * insert(char * key, TreeNode * root){

	int comp;
	
	if(root == NULL){
		
		root = newNode(key);
		
	}
	else{
		
		comp = strcmp(key, root->key);
		
		if(comp>0){
			root->right= insert(key, root->right);
		}
		else if(comp<0){
			root->left= insert(key, root->left);
		}		
	}
		
	root->height = max(height(root->left), height(root->right)) + 1;/*get height and balance of node*/
	root->balance = balance(root);
	
	if(root->balance==-2){/*Perform rotations if needed*/
		if(root->right->balance==1){
			root = doubleLeft(root);
		}
		else{
			root = leftRotation(root);
		}
	}
	else if(root->balance==2){
		if(root->left->balance==-1){
			root = doubleRight(root);
		}
		else{
			root = rightRotation(root);
		}
	}
					
	return(root);
}

TreeNode * find(char * key, TreeNode * root){/*If node does not exist return null*/

	int comp;
	
	if(root == NULL){
		return NULL;
	}
	
	else{
		
		comp = strcmp(key, root->key);
		
		if(comp == 0){
			return(root);
		}
		else if(comp>0){
			root= find(key, root->right);
		}
		else if(comp<0){
			root= find(key, root->left);
		}
		
	}
	
	return(root);
}
			
TreeNode * removeNode(char * key, TreeNode * root){/*Remove Node and return what is in its place, NULL or different node*/
	
	int comp;
	TreeNode*temp;
	
	comp = strcmp(key, root->key);
		
	if(comp == 0){
		if(root->left!=NULL && root->right!=NULL){
			if(root->frequency==1){
				temp = root->left;
				while(temp->right!=NULL){
					temp = temp->right;
				}
				root->frequency = temp->frequency;
				temp->frequency = 1;
				root = removeNode(temp->key, root);
				strcpy(root->key, temp->key);
			}
			else{
				root->frequency = root->frequency - 1;
			}
		}
		else if (root->right == NULL && root->left == NULL){
			if(root->frequency == 1){
				root = NULL;
			}
			else{
				root->frequency = root->frequency - 1;
			}
		}
		else if(root->left != NULL){
			if(root->frequency == 1){
				root->frequency = root->frequency - 1;
				temp = root;
				root = root->left;
				temp = NULL;
			}
			else{
				root->frequency = root->frequency - 1;
			}
		}
		else if(root->right != NULL){
			if(root->frequency == 1){
				root->frequency = root->frequency - 1;
				temp = root;
				root = root->right;
				temp = NULL;
			}
			else{
				root->frequency = root->frequency - 1;
			}
		}
	}
			
	else if(comp>0){
		root->right = removeNode(key, root->right);
	}
	else if(comp<0){
		root->left = removeNode(key, root->left);
	}
	
	if(root!=NULL){
		root->height = max(height(root->left), height(root->right)) + 1;
		root->balance = balance(root);
		
	
		if(root->balance==-2){
			if(root->right->balance==1){
				root = doubleLeft(root);
			}
			else{
				root = leftRotation(root);
			}
		}
		else if(root->balance==2){
			if(root->left->balance==-1){
				root = doubleRight(root);
			}
			else{
				root = rightRotation(root);
			}
		}
	}
	
	return(root);
			
}

void findAll(TreeNode*node, int frequency){/*In order traversal finding all nodes above/equal to frequency*/
    
    if(node!=NULL){
        if(node->left!=NULL){
			findAll(node->left, frequency);
		}
		if(node->frequency>=frequency){
			printf("key: %s, frequency: %d\n", node->key, node->frequency);
		}
		if(node->right!=NULL){
			findAll(node->right, frequency);
		}
    }
}

int findSize(TreeNode*node, int size){/*In order traversal finding size*/
	if(node!=NULL){
        if(node->left!=NULL){
			size = findSize(node->left, size);
		}
		size++;
		if(node->right!=NULL){
			size = findSize(node->right, size);
		}
    }
    
    return size;
}

int height(TreeNode * node){/*Find height of node*/
		
	if(node == NULL){
		return -1;
	}
	
	else{	
		
		node->height = max(height(node->left), height(node->right)) + 1;		
		return node->height;
	}
}

int max(int a, int b){
	
	if(a>b){
		return a;
	}
	else if(b>a){
		return b;
	}
	else{
		return a;
	}
}

TreeNode * leftRotation(TreeNode*root){
	TreeNode*temp;
	temp = root;
	root = root->right;
	temp->right = root->left;
	root->left = temp;
	root->height = max(height(root->left), height(root->right)) + 1;
	root->balance = balance(root);
	if(root->right!=NULL){
		root->right->balance = balance(root->right);
	}
	if(root->left!=NULL){
		root->left->balance = balance(root->left);
	}
	return(root);
}

TreeNode * rightRotation(TreeNode*root){
	TreeNode*temp;
	temp = root;
	root = root->left;
	temp->left = root->right;
	root->right = temp;
	root->height = max(height(root->left), height(root->right)) + 1;
	root->balance = balance(root);
	if(root->right!=NULL){
		root->right->balance = balance(root->right);
	}
	if(root->left!=NULL){
		root->left->balance = balance(root->left);
	}
	return(root);
}

TreeNode * doubleLeft(TreeNode*root){
	root->right = rightRotation(root->right);
	root = leftRotation(root);
	return(root);
}

TreeNode * doubleRight(TreeNode*root){
	root->left = leftRotation(root->left);
	root = rightRotation(root);
	return(root);
}

int balance(TreeNode*root){/*calculate bf of node*/
	if(root->left !=NULL && root->right !=NULL){
		root->balance = root->left->height - root->right->height;
	}
	else if(root->left!=NULL){
		root->balance = root->height;
	}
	else if(root->right!=NULL){
		root->balance = 0 - root->height;
	}
	else{
		root->balance = 0;
	}
	
	return(root->balance);
}
	
	
