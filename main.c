/*Team DaTunes -- Piotr Milewski & Jake Zaia
  Systems pd10
  Project 00
  2017-10-13*/

#include "nodeList.h"
#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

  b = insert_order(b, "Campfire Song Song", "Spongebob");
  print_list(b);

  b = insert_order(b, "FUN Song", "Spongebob");
  print_list(b);

  b = insert_order(b, "Sandstorm", "Darude");

  printf("Attempting to locate \"FUN Song\" by Spongebob\n");
  struct song_node *f = find(b, "FUN Song", "Spongebob");
  printf(" Found: %s\n", f->name);
  printf("Attempting to locate \"Never gonna give you up\"\n");
  f = find_song(b, "Never gonna give you up");
  printf(" Found: %s\n", f->name);
  printf("Attempting to locate \"Sad Violin\" (Not in the list)\n");
  f = find_song(b, "Sad Violin");
  printf(" Found: %s\n", f->name);

  printf("\nGetting 3 random Songs: \n");
  char i = 0;
  struct song_node *temp = 0;
  for (;i<3;i++) {
    temp = get_rand(b);
    printf(" \"%s\" by %s\n", temp->name, temp->artist);
  }

  printf("\nTesting remove_node: (Removing \"FUN Song\" & \"Never gonna give you up\"");
  print_list(b);
  b = remove_song(b, "FUN Song", "Spongebob");
  b = remove_song(b, "Never gonna give you up", "Rick Astley");
  b = remove_song(b, "Sad Violin", "yes"); //not in the list
  print_list(b);
}
