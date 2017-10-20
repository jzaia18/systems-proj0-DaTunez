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
  printf("Letter: %c", letter); //print out search letter
  print_list(table[letter - 'a']);
}

//prints out all the songs of a certain artist
void print_artist(char *artist){
  struct song_node *p = table[indexer(artist)]; //set pointer to alphabetical index
  p = find_song( p, artist);
  print_list(p);
}

//prints out the entire music library
void print_all(){
  int i = 0;
  for (; i < 26; i++){ //iterate through table[]
    printf("Letter: %c", 'a' + i); //print out search letter
    print_list(table[i]);
  }
}

//shuffle - print out "count" randomly chosen songs
void shuffle(int count){
  int randNum;
  struct song_node *p;
  while (count){
    randNum = rand() % 26; //sets random number between 0 and 25
    if (table[randNum]){ //execute if there is a song_node at the index
      count--;
      p = get_rand(table[randNum]); //procure random song
      printf("%s by %s\n", p->name, p->artist);
    }
  } 
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
    free_list(table[i]); //free index i
  }
}
