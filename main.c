/*Team DaTunes -- Piotr Milewski & Jake Zaia
  Systems pd10
  Project 00
  2017-10-13*/

#include "nodeList.h"
#include "main.h"

#include <stdio.h>
#include <stdlib.h>

int main(){

  printf("Testing add_front():\n");
  struct song_node *a = (struct song_node *) insert_front(0, "Never gonna give you up", "Rick Astley");
  print_list(a);

  
  //Empties the list and prints its contents
  a = free_list(a);
  print_list(a);

  
  
  return 0;
}
