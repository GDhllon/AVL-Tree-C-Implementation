/*Name: Gary Dhillon 
 * Date: Monday, November 24, 2014 
 * Assignment 4*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

struct TreeNode{
    char * key;
    int frequency;
    int balance;
    int height;
    struct TreeNode * left;
    struct TreeNode * right;
};

typedef struct TreeNode TreeNode;

void menu();
TreeNode * parseFile(char * fileName, TreeNode * root);
TreeNode * insert(char * key, TreeNode * root);
TreeNode * find(char * key, TreeNode * root);
TreeNode * removeNode(char * key, TreeNode * root);
TreeNode * newNode(char * key);
void flush();
void findAll(TreeNode * node, int frequency);
int findSize(TreeNode * node, int size);
int height(TreeNode * node);
int max(int a, int b);

TreeNode*rightRotation(TreeNode*root);
TreeNode*leftRotation(TreeNode*root);
TreeNode*doubleRight(TreeNode*root);
TreeNode*doubleLeft(TreeNode*root);

int balance(TreeNode*root);
