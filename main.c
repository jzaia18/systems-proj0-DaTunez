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

  //initialize some stuff
  srand(time(NULL));
  memset(table, 0, sizeof table);

  printf("Testing insert_front():\n");
  struct song_node *a = insert_front(0, "Never gonna give you up", "Rick Astley");
  print_list(a);

  a = insert_front(a, "Campfire song song", "Spongebob");
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

  b = insert_order(b, "Campfire song song", "Spongebob");
  print_list(b);

  b = insert_order(b, "FUN Song", "Spongebob");
  print_list(b);

  b = insert_order(b, "Sandstorm", "Darude");

  printf("Attempting to locate \"FUN Song\" by Spongebob\n");
  struct song_node *f = find(b, "FUN Song", "Spongebob");
  printf(" Found: %s\n", f->name);
  printf("Attempting to locate \"Rick Astley\"\n");
  f = find_song(b, "Rick Astley");
  printf(" Found: %s\n", f->name);
  printf("Attempting to locate \"Mike Oldfield\" (Not in the list)\n");
  f = find_song(b, "Mike Oldfield");
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

  //Playlist test functions
  add_song( "Never gonna give you up", "Rick Astley");
  add_song( "Cry For Help", "Rick Astley");
  add_song( "Campfire song song", "Spongebob");
  print_all();

  printf("Checking search() functionality\n");
  temp = search( "Never gonna give you up", "Rick Astley");
  printf("Found: %s by %s\n\n", temp->name, temp->artist);

  printf("Checking search_artist() functionality\n");
  temp = search_artist( "Rick Astley");
  printf("Found: %s by %s\n\n", temp->name, temp->artist);

  printf("Checking print_alpha functionality\n");
  print_alpha('r');

  printf("Checking print_artist functionality\n");
  print_artist("Rick Astley");
 
  printf("Checking shuffle functionality\n");
  shuffle(3);
 
  return 0;
}
