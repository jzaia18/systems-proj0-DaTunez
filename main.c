/*Team DaTunes -- Piotr Milewski & Jake Zaia
  Systems pd10
  Project 00
  2017-10-13*/

#include "nodeList.h"
#include "main.h"

#include <stdio.h>
#include <stdlib.h>

int main(){

  printf("Testing insert_front():\n");
  struct song_node *a = insert_front(0, "Never gonna give you up", "Rick Astley");
  print_list(a);

  a = insert_front(a, "Campfire Song Song", "Spongebob");
  print_list(a);

  a = insert_front(a, "FUN Song", "Spongebob");
  print_list(a); 

  //Empties the list and prints its contents
  a = free_list(a);
  
  
  printf("\nTesting insert_order():\n");
  struct song_node *b = insert_order(0, "Never gonna give you up", "Rick Astley");
  print_list(b);

  b = insert_order(b, "Cry For Help", "Rick Astley");
  print_list(b);

  b = insert_front(b, "Campfire Song Song", "Spongebob");
  print_list(b);

  b = insert_front(b, "FUN Song", "Spongebob");
  print_list(b); 
  
  return 0;
}
