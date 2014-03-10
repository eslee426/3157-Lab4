CC = gcc

INCLUDES = -I ../../lab3/solutions/part1
CFLAGS = -g -Wall $(INCLUDES)

LDFLAGS = -g -L../../lab3/solutions/part1
LDLIBS =  -lmylist

mdb-lookup: mdb-lookup.o 
mdb-lookup.o: mdb.h mdb-lookup.c

mdb-add: mdb-add.o
mdb-add.o: mdb.h mdb-add.c

.PHONY: clean
clean:
	rm -f *.o a.out core mdb-lookup mdb-add

.PHONY: all
all: clean mdb-lookup mdb-add
