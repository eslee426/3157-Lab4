/*
 * Name: Elisha Lee
 * UNI: esl2131
 * File: mdb-lookup.c
 * Description: 
 */


#include "mdb.h"
#include "mylist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "%s\n", "usage: mdb-lookup.c <file_name>");
        exit(1);
    }

    char *filename = argv[1];
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror(filename);
        exit(1);
    }
    
    // initialize and load list
    struct List mdbList;
    initList(&mdbList);
    loadmdb(fp, &mdbList);
    
    // prints everything in list if user presses enter
    printf("lookup: ");
    fflush(stdout);
    char buff[1000];
    int maxChar = 5; // only uses first 5 characters of lookup

    // searches for lookup keyword
    while(fgets(buff, sizeof(buff), stdin) != NULL) {
        char lookup[maxChar + 1];
        if (strlen(buff) > maxChar) {
            strncpy(lookup, buff, maxChar);
            lookup[maxChar] = '\0';
        } else { // ensures last character is not a newline character
            strncpy(lookup, buff, strlen(buff));
            lookup[strlen(buff) - 1] = '\0';
        }

        // prints matching lookups from list
        struct Node *node = mdbList.head;
        int count = 1;
        while(node) {
            struct MdbRec *recordData = (struct MdbRec *)node->data;
            if (strstr(recordData->name, lookup) || strstr(recordData->msg, lookup)) {
                printf("%4d: {%s} said {%s}\n", count, recordData->name, recordData->msg);
            }
            node = node->next;
            count++;
        }
        // asks for another lookup
        printf("\nlookup: ");
        fflush(stdout);
    }

    if (ferror(stdin)) {
        perror("stdin error");
        exit(1);
    }
    freemdb(&mdbList);

    fclose(fp);
    return 0;
}

