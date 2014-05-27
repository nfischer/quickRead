# makefile for quickread

CC=g++
CFLAGS=-c -Wall
LFLAGS=

all: quickread

quickread: Text.o Indexer.o main.o
	$(CC) Indexer.o Text.o main.o -o quickread

Text.o:
	$(CC) $(CFLAGS) Text.cpp

main.o:
	$(CC) $(CFLAGS) main.cpp

Indexer.o:
	$(CC) $(CFLAGS) Indexer.cpp


clean:
	rm -f *.o quickread *.stackdump
