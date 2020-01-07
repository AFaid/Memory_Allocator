#include <stdio.h>
#include <stdlib.h>
#include "datatype.h"

// Input:	’key1’ and ’key2’ are two Keys
// Output: if return value < 0, then key1 < key2,
// 				 if return value = 0, then key1 = key2,
//				 if return value > 0, then key1 > key2,
int key_comp(Key key1, Key key2){
    return key1-key2;
}

// Input:	’data1’ and ’data2’ are two Data
// Output: if return value < 0, then data1 < data2,
// 				 if return value = 0, then data1 = data2,
//				 if return value > 0, then data1 > data2,
int data_comp(Data data1, Data data2) {
    return data1-data2;
}

//	Input: ’key’: a Key
//	Effect: key is printed
void key_print(Key key) {
    printf("%d", key);
}

//	Input: ’data’: a Data
//	Effect: data is printed
void data_print(Data data) {
    printf("%d", data);
}

//	Input: ’node’: a Node
//	Effect: node.key is printed and then the node.data is printed
void print_node(Node node) {
    key_print(node.key);
    data_print(node.data);
}

//	Input: ’node’: a pointer to List_node
//	Effect: node->key is printed and then the node->data is printed
void print_list_node(List_node *node) {
    key_print(node->key);
    printf("\t\t");
    data_print(node->data);
    printf("\n");
}


//Input: a key, data and list_node object pointer
//Output: initializes a list_node object and returns pointer to othe node
List_node* List_node_ini(int key, int data, List_node* next){
	
    List_node* newList_node = malloc(sizeof(List_node));
    //Return NULL if memory allocation failed
    if(!newList_node) return NULL;
    
	newList_node->key = key;
	newList_node->data = data;
	newList_node->next = next;

	return newList_node;
} 
