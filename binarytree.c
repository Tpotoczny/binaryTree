#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "binarytree.h"
#include "node.h"

//Tim's
void initialize(binary_tree* bt){

}

//Andrew's
bool search(binary_tree* bt, int key){
    return searchNodes(bt->root, key);
}

//Meaghan's
void insert(binary_tree* bt, int item){
    node* newNode = NULL; //newNode = new item inserted
    node* tmpNext = NULL; //used to look at each node

    newNode = (node*)malloc(sizeof(node));
    newNode->binary_tree = item;
    newNode->nextNodePtr = NULL;

    if (bt->root == NULL){
        bt->root = newNode;
        bt->size += 1;
    }
    else{
        tmpNext = bt->root;
        while(tmpNext->left != NULL || tmpNext->right != NULL){ //go down tree (not inserting yet)
            if (newNode->binary_tree < tmpNext){ //if the input is less than the current place in the tree...
                tmpNext = tmpNext->left //go left
            }
            else{
                tmpNext = tmpNext->right; //otherwise, go right
            }
        }
        if (newNode->binary_tree < tmpNext){ //this is where it's inserted
            tmpNext->left = newNode; // if less than, insert to left
        }
        else{
            tmpNext->right = newNode; //if more than, insert to right
        }
        bt->size += 1;
    }
}

//Tim's
void printinorder(binary_tree* bt){

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
    if(node == NULL)
        return h-1;
    int sizeLeft = treeHeight(node->left, h+1);
    int sizeRight = treeHeight(node->right, h+1);
    if(sizeLeft>sizeRight)
        return sizeLeft;
    return sizeRight;
}

//Search function using nodes
bool searchNodes(node* node, int key){
    if(node == NULL)
        return false;
    else if(node->key < key)
        return searchNodes(node->left, key);
    else if(node->key > key)
        return searchNodes(node->right, key);
    else
        return true;

}
