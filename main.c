#include "binarytree.h"
#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char* argv[]){

    //variables
    binary_tree bt;
    initialize(&bt);
    bool found;
    char num[50];
    
    //argument error throws
    if(argc > 2){
        printf("Error: Too many arguments");
        return 1;
    }else if(argc < 2){
        printf("Error: No arguments");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    
    //attempts at unit testing
    //FILE *file = fopen("testFile.txt", "r");

    int readIn;

    //if the file doesnt exist throw an error
    if (file == NULL) {
        printf("Could not open file myfile.txt.\n");
        return 1;
    }

    fscanf(file, "%d", &readIn);
    while(!feof(file)){
        printf("%d \n", readIn);
        insert(&bt, readIn);
        fscanf(file, "%d", &readIn);
    }


    //gets the values from the file and converts them to integers, then inserts them
    //THROWS SEGMENTATION FAULT, I DO NOT KNOW WHY
    /*do{
        fgets(num, 50, file);
        int placeholder = 0;
        while(num[placeholder] != '\n' && num[placeholder] != '\0'){
            placeholder += 1;
        }
        num[placeholder] = '\0';
        readIn = atoi(num);
        insert(&bt, readIn);
    }while(!feof(file));*/
    
    
    //copied from assignment PDF
    /*printf("Print in order\n");
    printinorder(&bt);
    printf("\nPrint pre order\n");
    printpreorder(&bt);
    printf("\nPrint post order\n");
    printpostorder(&bt);
    printf("\n");
    found = search(&bt,33);
    if (found){
        printf("FOUND 33\n");
    }
    found = search(&bt,38);
    if (found){
        printf("FOUND 38\n");
    }
    printf("Number of elements in tree: %d\n", btsize(&bt));
    printf("Tree height: %d\n", treeheight(&bt));*/
    
    return 0;
}