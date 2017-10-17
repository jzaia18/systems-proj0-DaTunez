/*Piotr Milewski
  Systems pd10
  HW06 -- Enlist your C skillz
  2017-10-13*/

#include "nodeList.h"
#include "main.h"

#include <stdio.h>
#include <stdlib.h>

int main(){

  //Fills the list with multiples of 7 in a descending order and prints its contents
  struct song_node *a = (struct song_node *)malloc(sizeof(struct song_node));
  a->name = "Never gonna give you up";
  a->artist = "Rick Astley";
  print_list(a);
  
  //Empties the list and prints its contents
  a = free_list(a);
  print_list(a);

  return 0;
}
