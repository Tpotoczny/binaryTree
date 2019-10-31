#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "binarytree.h"
#include "node.h"

//Tim's

void initialize(binary_tree* bt){
    bt->size = 0;
    bt->root = NULL;
}

//Andrew's
bool search(binary_tree* bt, int key){
    return searchNodes(bt->root, key);
}

//Meaghan's
void insert(binary_tree* bt, int item){
    node* newNode; //newNode = new item inserted
    node* tmpNext; //used to look at each node
    node* prevPtr;

    newNode = (node*)malloc(sizeof(node));
    newNode->data = item;
    newNode->left = NULL;
    newNode->right = NULL;
    bool leftRight = false; //false for left, true for right

    if (bt->root == NULL){
        bt->root = newNode;
    }
    else{
        tmpNext = bt->root;
        while(tmpNext != NULL){
            prevPtr = tmpNext;              //assign the backwards pointer
            if(item < tmpNext->data){       //if value is less than node go left
                tmpNext = tmpNext->left;
                leftRight = false;
            }else{                          //if value is greater than node, go right
                tmpNext = tmpNext->right;
                leftRight = true;
            }
        }
        if(leftRight)
            prevPtr->right = newNode;
        else
            prevPtr->left = newNode;
    }
    bt->size += 1;
}
//Tim's
void printnodesinorder(node* pnode) {
    if (pnode == NULL){
        return;
    }
    printnodesinorder(pnode->left);
    printf("%d ", pnode->data);
    printnodesinorder(pnode->right);
}

void printinorder(binary_tree* bt){
    printnodesinorder(bt->root)
}

//Meaghan's
void printpreorder(binary_tree* bt){
  if((bt->root) == NULL){// node is null returns -1
    return -1;
  }

  printf("%d\n", (bt->root)->data);// prints node data
  printpreorder((bt->root)->left);//print left recursively
  printpreorder((bt->root)->right);//print right recursively
}

//Andrew's
void printpostorder(binary_tree* bt){
  if(bt->root == NULL){ // node is null returns -1
    return -1;
  }
  printpostorder((bt->root)->left); //print left recursively
  printpostorder((bt->root)->right);//print right recursively
  printf("%d\n", (bt->root)->data);//prints node->root data val
}

//Meaghan's
int btsize(binary_tree* bt){
    return bt->size;
}

//Andrew's
int treeheight(binary_tree* bt){
    return treeHeight(bt->root, 0);
}

//Height function using nodes
int treeHeight(node* node, int h){
    if(node == NULL) //base case, return height-1 as a null node does not count
        return h-1;
    int sizeLeft = treeHeight(node->left, h+1); //move down left
    int sizeRight = treeHeight(node->right, h+1); //move down right
    if(sizeLeft>sizeRight)
        return sizeLeft;    //if size left is greater than size right, return it
    return sizeRight;       //otherwise return size right
}

//Search function using nodes
bool searchNodes(node* node, int key){
    if(node == NULL)
        return false;
    else if(node->data < key)
        return searchNodes(node->left, key);
    else if(node->data > key)
        return searchNodes(node->right, key);
    else
        return true;
}
