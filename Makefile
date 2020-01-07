
mymemory: main.o list.o memory.o bst.o datatype.o
	gcc datatype.o bst.o memory.o list.o main.o -o mymemory

main.o: main.c
	gcc -c main.c -o main.o

list.o: list.h list.c
	gcc -c list.c -o list.o

memory.o: memory.h memory.c
	gcc -c memory.c -o memory.o

bst.o: bst.h bst.c
	gcc -c bst.c -o bst.o 

datatype.o: datatype.h datatype.c
	gcc -c datatype.c -o datatype.o

clean: 
	rm *.o mymemory