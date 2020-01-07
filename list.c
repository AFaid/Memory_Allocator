#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "memory.h"

// Input: N/A
// Effect: Initialize an empty list and return pointer to head.
List list_ini(void) {
	List_node *head= (List_node *) simu_malloc( sizeof(List_node) );
	head->next = NULL;
	return head;
}

// Input: 'list': Head node of list
// 		   'key': a key
// Effect: If key is in list, return the address of key’s associated data. 
// 		   If key is not in list, return NULL
Data *list_search(List list, Key key) {
	if(list->next == NULL) return NULL; //if list is empty return NULL

	List current_node = list;
	//Traverse list until last node is reached or node with given key is found
	while(current_node->next != NULL){
		if(current_node->key == key) return &(current_node->data);
		else current_node = current_node->next;
	}

	//Check last node
	if(current_node->key == key) return &(current_node->data);
	else return NULL; //If node with given key is not found return NULL

}

// Input: 'list': Head node of list
// 		   'key': key of new node to be added
//		   'data': data of new node to be added
// Effect: Add key with data into the front of list. If key is in lsit, 
//		   then do nothing.
void list_add(List list, Key key, Data data) {
	if(list_search(list, key)) return; //If node with given key exists terminate function

	List_node* new_node = (List_node *)simu_malloc(sizeof(List_node));
	new_node->key = key;
	new_node->data = data;

	//Add node after head node
	List_node* new_node_next = list->next;
	list->next = new_node;
	new_node->next = new_node_next;
}

// Input: 'list': Head node of list
// 		   'key': key of new node to be added
// Effect: Delete the node in list with its key equals to key. 
//			If no such node in list, do nothing.
void list_delete(List list, Key key) {

	List previous_node = list;
	//Traverse list
	while(previous_node->next != NULL){
		List current_node = previous_node->next;
		List next_node = current_node->next;
		//if node is found remove from list
		if(current_node->key == key){
			simu_free(current_node);
			previous_node->next = next_node;
			return;
		}

		previous_node = previous_node->next;
	}
}

// Input: 'list': Head node of list to be printed
// Effect: Linearly traversal the list and print each node’s key and data
void list_print(List list) {
	if(list->next == NULL){
		 printf("Empty List\n");
		 return;
	 }

	List current_node = list->next;
	while(current_node->next != NULL){
		print_list_node(current_node);
		current_node = current_node->next;
	}
	print_list_node(current_node);
}

// Input: 'list': Head node of list to be printed
// Effect: Free all the dynamically allocated memory of list.
void list_free(List list) {
	//Free each node in list
	while(list->next){
		list_delete(list, list->next->key);
	}
	//Free head
	simu_free(list);
	//Set list to NULL to avoid garbage value
	list = NULL; 
}
