#created by yochai modechai dahari
#ID: 308212570

CC=gcc
AR=ar
MAIN=main.o
LIB=libmyMath.o
POW=power.o
FLAGS= -Wall
all: mymathd mymaths mains maind 

#dynamic
maind: $(MAIN) libmyMath.so
	$(CC) $(FLAGS) -o maind $(MAIN) ./libmyMath.so

#static
mains: $(MAIN) libmyMath.a 
	$(CC) $(FLAGS) -o mains $(MAIN) libmyMath.a

#create dynamic lib .so
mymathd: basicMath.o power.o
	$(CC) -shared -o libmyMath.so basicMath.o power.o 

#create static lib libmyMath.a
mymaths: basicMath.o power.o 
	$(AR) -rcs -o libmyMath.a basicMath.o power.o 

#create mylib file
basicMath.o: basicMath.c myMath.h
	$(CC) $(FLAGS) -c basicMath.c myMath.h
	
#create mylib file
power.o: power.c myMath.h
	$(CC) $(FLAGS) -c power.c myMath.h
	
#create mylib file
main.o: main.c myMath.h  
	$(CC) $(FLAGS) -c main.c myMath.h  

.PHONY: clean all

clean:
	rm -f *.o *.a *.so mains maind
