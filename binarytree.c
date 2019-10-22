#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "binarytree.h"

//Tim's
void initialize(binary_tree* bt){

}

//Andrew's
bool search(binary_tree* bt, int key){
    if(bt->/*int value*/ == NULL){
        return false;
    }
    else if(key < bt->/*int value*/){
        return search(/*left reference*/, key);
    }else if(key > bt->/*int value*/){
        return search(/*right reference*/, key);
    }else{
        return true;
    }
}

//Meaghan's
void insert(binary_tree* bt, int item){

}

//Tim's
void printinorder(binary_tree* bt){

}

//Meaghan's
void printpreorder(binary_tree* bt){

}

//Andrew's
void printpostorder(binary_tree* bt){

}

//Meaghan's
int btsize(binary_tree* bt){

}

//Andrew's
int treeheight(binary_tree* bt){

}