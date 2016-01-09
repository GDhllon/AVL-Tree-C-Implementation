/*Name: Gary Dhillon 
 * Date: Monday, November 24, 2014 
 * Assignment 4*/

#include "a4.h"

TreeNode * parseFile(char * fileName, TreeNode * root){
	
	FILE * fr;
	char * inputLine = malloc(sizeof(char)*1000);
	char * inputCopy = malloc(sizeof(char)*1000);
	char * segment;
	char test;
	TreeNode * temp;
	
	fr = fopen(fileName, "rt");
	
	if(fr == NULL){
		printf("Invalid file name/could not open file\n");
		return NULL;
	}
	
	while(fgets(inputLine, 1000, fr)!=NULL){/*Parse line by line*/
				
		strcpy(inputCopy, inputLine);
		
		strtok(inputCopy, "\n");
		
		segment = strtok(inputCopy, " ");
		
		test = *segment;
		
		if(test!=' ' && test!='\n'){
			do{
				if(segment!=NULL){
					temp = find(segment, root);
					if(temp == NULL){
						root = insert(segment, root);
					}
					else{
						temp->frequency = temp->frequency + 1;
					}
				}
				
				segment = strtok(NULL, " ");
			
			}while(segment!=NULL);
		}
	}
	    
	return(root);
}
	    
	
	
