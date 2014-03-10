/*
 * Written by: Elisha Lee and Alice Chang
 * File: mdb.c
 * Description: contains loadmdb and freemdb for mdb-lookup and mdb-add
 */

#include "mdb.h"
#include "mylist.h"
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

// loads given file and puts data in linked list
int loadmdb(FILE *fp, struct List *dest) {
    struct MdbRec myRec;
    struct Node *node = NULL;
    int count = 0;
    initList(dest);

    // puts record into linked list memory
    while (fread(&myRec, sizeof(myRec), 1, fp) == 1) {
        struct MdbRec *record = (struct MdbRec *)malloc(sizeof(myRec));
        if (!record) {
            perror("malloc error");
            exit(1);
        }


        memcpy(record, &myRec, sizeof(myRec));
        node = addAfter(dest, node, record);
        if (node == NULL) {
            perror("adding error");
            exit(1); 
        }
        ++count;
    }

    if (ferror(fp)) {
        perror("error reading file");
        exit(1);
    }

    return count;
}

// frees all memeory allocated
void freemdb(struct List *list) {
	struct Node *current = list->head;
	// iterates through list and pops all nodes
        while(current) {
            current = current->next;
            free(popFront(list));
	}
}
