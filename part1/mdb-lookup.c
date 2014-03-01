/*
 * Name: Elisha Lee
 * UNI: esl2131
 * File: mdb-lookup.c
 * Description: 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mdb.h"
#include "mylist.h"

int main(int argc, char **arv)
{
    if (argc != 2) {
        fprintf(stderr, "s%\n", "usage: mdb-lookup.c <file_name>");
        exit(1);
    }

    char *filename = argv[1];
    File *fp = (filename, "rb");
    if (fp == NULL) {
        perror(filename);
        exit(1);
    }

    fclose(fp);
    return 0;
}
