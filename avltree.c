/*Name: Gary Dhillon 
 * Date: Monday, November 24, 2014 
 * Assignment 4*/

#include "a4.h"

int main(){
	
	menu();
	return 0;
}

void menu(){
	
	int frequency, size;
	char choice;
	char * input = malloc(sizeof(char)*30);
	TreeNode * root, *temp;
	root = NULL;
	temp = NULL;
	
	printf("******************************\n");
	printf("Welcome to the AVL tree Program\n");
	printf("Name: Gary Dhillon\n");
	printf("******************************\n");
	
	do{
		printf("\n\n");
		printf("1. Initialization\n");
		printf("2. Find\n");
		printf("3. Insert\n");
		printf("4. Remove\n");
		printf("5. Check Height and Size\n");
		printf("6. Find All (above a given frequency)\n");
		printf("7. Exit\n");
		printf("avl/> ");
		choice = getchar();
		flush();
		
		switch(choice){
			
			case '1':/*Initialization*/
			printf("filename: ");
			fgets(input, 30, stdin);
			strtok(input, "\n");
			root = parseFile(input, root);
			break;
			
			case '2': /*Find*/
			printf("find key: ");
			fgets(input, 30, stdin);
			strtok(input, "\n");
			temp = find(input, root);
			if(temp==NULL){
				printf("no_such_key\n");
			}
			else{
				printf("key: %s, frequency: %d\n", temp->key, temp->frequency);
			}
			break;
			
			case '3': /*Insert*/
			printf("insert key: ");
			fgets(input, 30, stdin);
			strtok(input, "\n");			
			temp = find(input, root);
			if(temp == NULL){
				root = insert(input, root);
				printf("key: %s, frequency: 1", input);
			}
			else{
				temp->frequency = temp->frequency + 1;
				printf("key: %s, frequency: %d\n", temp->key, temp->frequency);
			}
			break;
			
			case '4': /*Remove*/
			printf("remove key: ");
			fgets(input, 30, stdin);
			strtok(input, "\n");			
			temp = find(input, root);
			if(temp == NULL){
				printf("no_such_key\n");
			}
			else{
				if(temp->frequency>1){
					printf("key: %s, frequency: %d\n", temp->key, temp->frequency-1);
				}
				else{
					printf("key: %s, frequency: 0\n", input);
				}
				root = removeNode(input, root);
			}
			break;
			
			case '5': /*Check Height and Size*/
			size = 0;
			size = findSize(root, size);
			printf("height: %d, size: %d\n", root->height, size);
			break;
			
			case '6': /*Find all above frequency*/
			printf("frequency: ");
			fgets(input, 30, stdin);
			frequency = atoi(input);
			if(frequency>=1){
				findAll(root, frequency);
			}
			else{
				printf("Invalid frequency entered, enter a value 1 or greater\n");
			}
			break;
			
			case '7':
			printf("Exiting\n");
			break;						
			
		}
		
	}while(choice!='7');
		
		
}

/*Flush input buffer*/
void flush()
{
    while(getchar()!='\n');
} 
	
		
	
