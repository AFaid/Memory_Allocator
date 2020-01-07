#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memory.h"

static unsigned char *memory;
static BStree bst;

//Input: 'size': Number of bytes of memory to be used
//Effect: Initialize an unsigned char array of size elements and initialize a binary search tree.
void mem_ini(unsigned int size) {
	memory = (unsigned char *) malloc(size);
	bst = bstree_ini(size/5); // size/5 is large enough
	bstree_insert(bst, 0, size);
}

//Input: 'size': Number of bytes of memory to be allocated
//Effect: Allocate -size- bytes and return a pointer to the first byte allocated. 
void *simu_malloc(unsigned int size) {
	Data space_size = size+4;
	Key* index_ptr = bstree_data_search(bst, space_size);	//Search for size+4 bytes of consequtive free space
	if(index_ptr == NULL){\
		printf("Memory Full\n");
		exit(EXIT_FAILURE);
	}	//If not found return NULL

	Data* free_space_ptr = bstree_search(bst, *index_ptr);	//If found get pointer to #of free space

	int index = (int)(*index_ptr);	//convert from key to pointer int to get index
	int free_space = (int)(*free_space_ptr);	//convert data pointer to int to get #of free spaces

	bstree_delete(bst, *index_ptr);	//Delete node from tree

	*(int*)(memory+index) = size;	//Store the number of spaces used inside memory

	//if there is more free space than needed store remaining free space back into bstree
	if(size+4 < free_space){
		Key key = index + 4 + size;
		Data data = free_space - (size+4);
		bstree_insert(bst, key, data);
	}

	//return pointer to first byte of allocated space in memory
	char* char_ptr = &(memory[index+4]);
	void* position = char_ptr;
	return position;
}

//Input: 'ptr': a pointer to first address of memory to be freed
//Effect: Put the allocated memory pointed by ptr back to be free memory 
void simu_free(void *ptr) {
	Data data = *(int*)(ptr-4); //Get number of bytes to be freed
	Key key = (unsigned char*)(ptr-4) - memory; //Create key with freed index

	bstree_insert(bst,key,data); //insert freed memory back into bst
}

// Input: N/A
// Effect: Print all the free memory blocks.
void mem_print(void) {
	bstree_traversal(bst);
}

// Input: N/A
// Effect: Free memory used for the array and the binary search tree.
void mem_free(void) {
	bstree_free(bst);
	free(memory);
}