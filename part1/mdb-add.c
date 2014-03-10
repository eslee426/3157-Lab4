#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mdb.h"
#include "mylist.h"
#include "ctype.h"
static void clean(char* c)
{
	while (*c)
	{
		if (isprint(*c) == 0)
			*c = ' ';
                c++;
	}
}
	
int main(int argc, char **argv)
{
	struct MdbRec myRec;
	char line[1000];

	if (argc !=2)
	{
		fprintf(stderr, "%s\n", "usage: mdb-add <database_file>");
		exit(1);
	}

	FILE *fp = fopen(argv[1], "a+");
	if(fp == NULL)
	{
		perror("Error opening file");
		exit(1);
	}

        struct List mdbList;
        int size = loadmdb(fp, &mdbList);
	
        printf("name please (will truncate to %d chars): ", (int)(sizeof(myRec.name)-1));
	if (fgets(line, sizeof(line), stdin) == NULL)
	{
		fprintf(stderr, "%s\n", "Uable to read name");
		exit(1);
	}
	
	
	strncpy(myRec.name, line, sizeof(myRec.name)-1);
	myRec.name[sizeof(myRec.name) -1] = '\0';

	if(myRec.name[strlen(myRec.name)-1] == '\n')
	{
		myRec.name[strlen(myRec.name)-1] = '\0';
	}
	
	
	printf("msg please (will truncate to %d chars): ", (int)(sizeof(myRec.msg)-1));
	if (fgets(line, sizeof(line), stdin) == NULL)
	{
		fprintf(stderr, "%s\n", "Unable to read message");
		exit(1);
	}

	strncpy(myRec.msg, line, sizeof(myRec.msg)-1);
	myRec.msg[sizeof(myRec.msg)-1] = '\0';
	if(myRec.msg[strlen(myRec.msg)-1] == '\n')
	{
		myRec.msg[strlen(myRec.msg)-1] = '\0';
	}
        
        struct Node *node = mdbList.head;
        while(node)
        {
           node = node->next;
        }
        struct MdbRec *record = (struct MdbRec *)malloc(sizeof(myRec));
        if(!record) {
            perror("Malloc failed");
            exit(1);
        }
        memcpy(record, &myRec, sizeof(myRec));
        node = addAfter(&mdbList, node, record);

	clean(myRec.msg);
        clean(myRec.name);
	if (fwrite(&myRec, sizeof(myRec), 1, fp) < 1)
	{
		perror("unable to write");
		exit(1);
	}

	if (fflush(fp)!=0)
	{
		perror("unable to write");
		exit(1);
	}	

        printf("%d: {%s} said {%s}\n", size + 1,  myRec.name, myRec.msg);
        fflush(stdout);
	fclose(fp);
	freemdb(&mdbList);
        return 0;

}
