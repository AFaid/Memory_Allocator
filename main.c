#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
#include "list.h"

int main(){
  //Initializes x bytes of memory (where x is inputted value)
  printf("Enter memory size:\t");
  unsigned int memory_size;
  scanf("%d", &memory_size);
  mem_ini(memory_size);

  //Initialize a list to store integer occurences
  List list = list_ini();

  int input = 0;
  printf("Enter Numbers:\n");
  //Take user input until EOF
  while(1){
    int cont = scanf("%d", &input);

    //If EOF (ctrl-d) is reached/enterd stop asking for input
    if(cont == EOF) break;
    Data* occurence = list_search(list, input);

    //If key with inputted value exist in list increment its value by one
    if(occurence) (*occurence)++;
    //If key with inputted value does not exist insert it as a new node into the list
    else list_add(list, input, 1);
  }

  //Print List contents
  printf("Integers\tOccurences\n");
  list_print(list);
  //Free list and memory
  list_free(list);
  mem_free();
}
