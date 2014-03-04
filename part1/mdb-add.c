#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mdb.h"
#include "mylist.h"

int main(int argc, char **argv)
{
	struct MdbRec myRec;
	char line[1000];

	FILE *fp = fopen(argv[1], "ab");
	if(fp == NULL)
	{
		perror("Error opening file");
		exit(1);
	}
	if (fgets(line, sizeof(line), stdin == NULL))
	{
		fprintf(stderr, "%s\n", "Uable to read name");
		exit(1);
	}
	
	strncpy(myRec.name, line, sizeof(myRec.name)-1);
	myRec.name[sizeof(r.name) -1] = '\0';

	if(myRec.name[strlen(myRec.name)-1] == '\n')
	{
		myRec.name[strlen(myRec.name)-1] = '\0';
	}

	if (fgets(line, sizeof(line), stdin) == NULL)
	{
		fprintf(stderr, "%s\n", "Unable to read message");
		exit(1);
	}

	strncpy(r.msage, line, sizeof(myrec.msg)-1);
	myRec.msg[sizeof(myRec.msg)-1] = '\0';
	
	if(myRec.msg[strlen(myRec.msg)-1] == '\n')
	{
		myRec.msg[strlen(myRec.msg)-1] = '\0';
	}	
	fclose(fp);
	return 0;
}