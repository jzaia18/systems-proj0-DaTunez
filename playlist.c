/*Team DaTunez -- Piotr Milewski & Jake Zaia
  Systems pd10
  Project 00
  2017-10-13*/

#include "playlist.h"
#include "nodeList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//find alphabetical number that corresponds to the first letter of artist
int indexer(char *artist){
  if ((artist[0] - 'a') < 0) //execute if first letter of artist is a capital letter
    return artist[0] - 'A';
  else //execute if first letter of artist is a lowercase letter
    return artist[0] - 'a';
}

//adds a song_node to the playlist
void add_song(char *name, char *artist){
  struct song_node *p = table[indexer(artist)]; //set pointer to alphabetical index
  table[indexer(artist)] = insert_order(p, name, artist); //insert song_node alphabetically
}

//return a pointer to a song given its name and artist
struct song_node *search(char *name, char *artist){
  struct song_node *p = table[indexer(artist)]; //set pointer to alphabetical index
  return find( p, name, artist);
}

//return a pointer to first song given its artist
struct song_node *search_artist(char *artist){
  struct song_node *p = table[indexer(artist)]; //set pointer to alphabetical index
  return find_song( p, artist);
}

//print out all the entries under "letter"
void print_alpha(char letter){
  printf("Letter: %c\n", letter-32); //print out search letter
  if (table[letter - 'a']) {
    struct song_node *currNode = table[letter-'a'];
    while (currNode) {
      printf("   \"%s\" by %s\n", currNode->name, currNode->artist);
      currNode = currNode->next;
    }
  }
  printf("\n");
}

//prints out all the songs of a certain artist
void print_artist(char *artist){
  struct song_node *list = table[indexer(artist)]; //set pointer to alphabetical index
  list = find_song( list, artist);
  printf("\nAll songs by %s:\n", artist);
  while(list){
    printf("   \"%s\"\n", list->name);
    list = list->next;
  }
  printf("\n");
}

//prints out the entire music library
void print_all(){
  printf("\nPrinting all songs, sorted by artist's name:\n");
  int i = 0;
  for (; i < 26; i++){ //iterate through table[]
    char letter = 'a' + i;
    if (table[i]) {
      printf("   Artist: %c\n      ", letter-32); //print out search letter
      struct song_node *currNode = table[i];
      while (currNode->next) {
	printf(" \"%s\" by %s, ", currNode->name, currNode->artist);
	currNode = currNode->next;
      }
      printf(" \"%s\" by %s\n", currNode->name, currNode->artist);
    }
  }
  printf("\n");
}

//shuffle - print out "count" randomly chosen songs
void shuffle(int stop){
  int count = 1;
  int randNum;
  struct song_node *p;
  printf("\nYour queue of %d random songs:\n", stop);
  while (count<=stop){
    randNum = rand() % 26; //sets random number between 0 and 25
    if (table[randNum]){ //execute if there is a song_node at the index
      p = get_rand(table[randNum]); //procure random song
      printf("  %d: %s by %s\n", count, p->name, p->artist);
      count++;
    }
  }
  printf("\n");
}

//delete a song
void delete_song(char *name, char *artist){
  struct song_node *p = table[indexer(artist)]; //set pointer to alphabetical index
  table[indexer(artist)] = remove_song(p, name, artist);
}

//delete all the nodes
void delete_all(){
  int i = 0;
  for (; i < 26; i++){ //iterate through table[]
    table[i] = free_list(table[i]); //free index i
  }
}
