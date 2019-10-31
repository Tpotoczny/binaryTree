#include "binarytree.h"
#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char* argv[]){
    //variables
    binary_tree bt;
    bool found;
    
    //should only work if the only argument entered is the filename
    FILE *file = fopen(argv[0], "r");
    int readIn;
    char emptyChar;
    while(!feof(file) && emptyChar != '\n'){
        fscanf(file, "%d", &readIn);
        fscanf(file, "%c", &emptyChar);
        insert(&bt, readIn);
    }

    //copied from assignment PDF
    printf("Print in order\n");
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
    printf("Tree height: %d\n", treeheight(&bt));

    return 0;
}