#include "mdb.h"
#include "mylist.h"
#include <stdio.h>

int loadmdb(FILE *fp, struct List *dest) {
    struct MdbRec myRec;
    struct Node *node = NULL;
    
    // puts record into linked list memory
    while (fread(&myRec, sizeof(myRec), 1, fp) == 1) {
        struct MdbRec *record = (struct MdbRec *)malloc(sizeof(myRec));
        if (!record) {
            perror("malloc error");
            exit(1);
        }


        memcpy(record, &myRec, sizeof(myRec));
        node = addAfter(&dest, node, record);
        if (node == NULL) {
            perror("adding error");
            exit(1); 
        }
    }

    if (ferror(fp)) {
        perror(filename);
        exit(1);
    }

    return (int) sizeof(dest)/sizeof(record);
}


void freemdb(struct List *list) {
    traverseList(&list, &free);
    removeAllNodes(&list);
}
