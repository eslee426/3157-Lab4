#include "mdb.h"
#include "mylist.h"
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

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


void freemdb(struct List *list) {
	struct Node *current = list->head;
	while(current)//iterates through list and pops all nodes
	{
		current = current->next;
		free(popFront(list));
	}
	
}
