#ifndef BINARY_TREE //I have no idea why these are here, maybe someone can fill me in?
#define BINARY_TREE

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "node.h"
typedef struct binary_tree_struct
{
    int size;
    node* root;
}binary_tree;

void initialize(binary_tree* bt);
bool search(binary_tree* bt, int key);
void insert(binary_tree* bt, int item);
void printinorder(binary_tree* bt);
void printpreorder(binary_tree* bt);
void printpostorder(binary_tree* bt);
int btsize(binary_tree* bt);
int treeheight(binary_tree* bt);
int treeHeight(node* node, int h);
bool searchNodes(node* node, int key);
void printnodesinorder(node* pnode);
void printnodespreorder(node* pnode);
void printnodespostorder(node* pnode);

#endif
