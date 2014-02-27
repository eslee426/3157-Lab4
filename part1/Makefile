CC = gcc

INCLUDES = -I ../../lab3/part1
CFLAGS = -g -Wall $(INCLUDES)

LDFLAGS = -g -L../../lab3/part1
LDLIBS =  -lmylist

mdb-lookup: mdb-lookup.o 
mdb-lookup.o: mdb.h mdb-lookup.c

.PHONY: clean
clean:
	rm -f *.o a.out core mdb-lookup

.PHONY: all
all: clean mdb-lookup
