/*Team DaTunes -- Piotr Milewski & Jake Zaia
  Systems pd10
  Project 00
  2017-10-13*/

#include "nodeList.h"
#include "main.h"
#include "playlist.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  srand(time(NULL));

  printf("Testing insert_front():\n");
  struct song_node *a = insert_front(0, "never gonna give you up", "rick astley");
  print_list(a);

  a = insert_front(a, "campfire song song", "spongebob");
  print_list(a);

  a = insert_front(a, "fun song", "spongebob");
  print_list(a); 

  //Empties the list and prints its contents
  a = free_list(a);
  
  printf("\nTesting insert_order():\n");
  struct song_node *b = insert_order(0, "never gonna give you up", "rick astley");
  print_list(b);

  b = insert_order(b, "cry for help", "rick astley");
  print_list(b);

  b = insert_order(b, "campfire cong cong", "spongebob");
  print_list(b);

  b = insert_order(b, "fun song", "spongebob");
  print_list(b);

  b = insert_order(b, "sandstorm", "darude");

  printf("Attempting to locate \"fun song\" by spongebob\n");
  struct song_node *f = find(b, "fun song", "spongebob");
  printf(" Found: %s\n", f->name);
  printf("Attempting to locate \"never gonna give you up\"\n");
  f = find_song(b, "rick astley");
  printf(" Found: %s\n", f->name);
  printf("Attempting to locate \"sad violin\" (Not in the list)\n");
  f = find_song(b, "mike oldfield");
  printf(" Found: %s\n", f->name);

  printf("\nGetting 3 random Songs: \n");
  char i = 0;
  struct song_node *temp = 0;
  for (;i<3;i++) {
    temp = get_rand(b);
    printf(" \"%s\" by %s\n", temp->name, temp->artist);
  }

  printf("\nTesting remove_node: (Removing \"fun song\" & \"never gonna give you up\"");
  print_list(b);
  b = remove_song(b, "fun song", "spongebob");
  b = remove_song(b, "never gonna give you up", "rick astley");
  b = remove_song(b, "sad violin", "yes"); //not in the list
  print_list(b);

  //Playlist test functions
  add_song( "never gonna give you up", "rick astley");
  print_all();

  printf("Checking search() functionality\n");
  temp = search( "never gonna give you up", "rick astley");
  printf("Found: %s by %s\n\n", temp->name, temp->artist);

  printf("Checking search_artist() functionality\n");
  temp = search_artist( "rick astley");
  printf("Found: %s by %s\n\n", temp->name, temp->artist);

  printf("Checking print_alpha functionality\n");
  print_alpha('r');

  printf("Checking print_artist functionality\n");
  print_artist("rick astley");
  
  return 0;
}
