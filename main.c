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
#include <time.h>

int main(){

  //initialize some stuff
  char bar[] = "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
  srand(time(NULL));
  memset(table, 0, sizeof table);

  
  // BEGIN NODE FUNCTIONS

  
  // Test insert_front
  printf("\n\n\n%sTesting insert_front():%s", bar, bar);
  struct song_node *a = insert_front(0, "Never gonna give you up", "Rick Astley");
  print_list(a);

  a = insert_front(a, "Campfire song song", "Spongebob");
  print_list(a);

  a = insert_front(a, "FUN Song", "Spongebob");
  print_list(a); 

  
  // Test free_list
  printf("Testing free_list...");
  a = free_list(a);
  print_list(a); 


  // Test insert_order
  printf("%sTesting insert_order():%s", bar, bar);
  struct song_node *b = insert_order(0, "Never gonna give you up", "Rick Astley");
  print_list(b);

  b = insert_order(b, "Cry For Help", "Rick Astley");
  print_list(b);

  b = insert_order(b, "Campfire song song", "Spongebob");
  print_list(b);

  b = insert_order(b, "FUN Song", "Spongebob");
  print_list(b);

  b = insert_order(b, "Sandstorm", "Darude");


  // Test find
  printf("%sTesting find%s", bar, bar);

  printf("\nAttempting to locate \"FUN Song\" by Spongebob\n");
  struct song_node *f = find(b, "FUN Song", "Spongebob");
  printf("   Found: %s\n", f->name);

  printf("Attempting to locate \"Rick Astley\"\n");
  f = find_song(b, "Rick Astley");
  printf("   Found: %s\n", f->name);

  printf("Attempting to locate \"Mike Oldfield\" (Not in the list)\n");
  f = find_song(b, "Mike Oldfield");
  printf("   Found: %s\n", f->name);

  
  // Test get_rand
  printf("%sTesting get_rand%s", bar, bar);
  printf("\nGetting 5 random Songs: \n");
  char i = 0;
  struct song_node *temp = 0;
  for (;i<5;i++) {
    temp = get_rand(b);
    printf("   \"%s\" by %s\n", temp->name, temp->artist);
  }


  // Test remove_node
  printf("%sTesting remove_node%s", bar, bar);
  printf("\nRemoving \"FUN Song\", \"Never gonna give you up\", and \"Sad Violin\" (not in list)");
  print_list(b);
  b = remove_song(b, "FUN Song", "Spongebob");
  b = remove_song(b, "Never gonna give you up", "Rick Astley");
  b = remove_song(b, "Sad Violin", "yes"); //not in the list
  print_list(b);


  // Test free_list
  printf("%sTesting free_list%s", bar, bar);
  b = free_list(b);
  print_list(b);


  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
  //                                                         //
  // END NODE FUNCTIONS                                      //
  // BEGIN PLAYLIST FUNCTIONS                                //
  //                                                         //
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
  
  printf("\n%sEND OF NODE FUNCTION TESTS.\nBEGINNING OF PLAYLIST FUNCTION TESTS%s\n", bar, bar);

  
  // Test add_song
  printf("%sTesting add_song%s", bar, bar);
  print_all();
  add_song( "Never gonna give you up", "Rick Astley");
  add_song( "Cry For Help", "Rick Astley");
  add_song( "Campfire song song", "Spongebob");
  add_song( "Sandstorm", "Darude");
  add_song( "All Star", "Smash Mouth");
  add_song( "We are Number One", "Lazy Town");
  add_song( "Deja Vu", "Initial D");
  add_song( "Running in the 90s", "Initial D");
  add_song( "Gas Gas Gas", "Initial D");
  add_song( "Night of Fire", "Initial D");
  add_song( "Heartbeat", "Initial D");
  print_all();


  // Test search
  printf("%sTesting search%s\n", bar, bar);
  printf("\nAttempting to locate \"Never gonna give you up\" by Rick Astley\n");
  f = search( "Never gonna give you up", "Rick Astley");
  printf("   Found: %s\n", f->name);
  
  printf("\nAttempting to locate \"Never gonna let you down\" by Rick Astley\n");
  f = search( "Never gonna give you up", "Rick Astley");
  printf("   Found: %s\n", f->name);


  // Test search_artist
  printf("%sTesting search_artist%s\n", bar, bar);
  printf("\nAttempting to locate a song by Rick Astley\n");
  f = search_artist( "Rick Astley");
  printf("   Found: %s\n", f->name);

  printf("\nAttempting to locate a song by John Cena\n");
  f = search_artist( "John Cena");
  printf("   Found: %s\n", f->name);
  

  // Test print_alpha
  printf("%sTesting print_alpha%s\n", bar, bar);
  print_alpha('r');
  print_alpha('s');
  printf("T songs should be null...\n");
  print_alpha('t');


  // Test print_artist
  printf("%sTesting print_artist%s", bar, bar);
  print_artist("Rick Astley");
  print_artist("Spongebob");
  print_artist("Mr. DW");


  // Test shuffle
  printf("%sTesting shuffle%s", bar, bar);
  shuffle(10);
  

  // Test delete_all
  printf("%sTesting delete_all%s", bar, bar);
  delete_all();
  print_all();

  
  return 0;
}
