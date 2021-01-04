CC=gcc
AR=ar
FLAGS= -g -Wall

all: isort txtfind


isort: mainsort.o
	$(CC) $(FLAGS) mainsort.o -o isort

txtfind: maintxt.o
	$(CC) maintxt.o -o txtfind 
	
mainsort.o: mainsort.c isort.c isort.h
	$(CC) $(FLAGS) -c mainsort.c isort.c isort.h

maintxt.o: maintxt.c txtfind.c txtfind.h
	$(CC) $(FLAGS) -c maintxt.c txtfind.c txtfind.h

.PHONY: clean

clean:
	rm -f *.o isort txtfind