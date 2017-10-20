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

int indexer(char *artist){
  if ((artist[0] - 'a') < 0)
    return artist[0] - 'A';
  else
    return artist[0] - 'a';
}

void add_song(char *name, char *artist){
  struct song_node *p = table[indexer(artist)];
  table[indexer(artist)] = insert_order(p, name, artist);
}

struct song_node *search(char *name, char *artist){
  struct song_node *p = table[indexer(artist)];
  return find( p, name, artist);
}

struct song_node *search_artist(char *artist){
  struct song_node *p = table[indexer(artist)];
  return find_song( p, artist);
}

void print_alpha(char letter){
  printf("Letter: %c", letter);
  print_list(table[letter - 'a']);
}

void print_artist(char *artist){
  struct song_node *p = table[indexer(artist)];
  p = find_song( p, artist);
  print_list(p);
}

void print_all(){
  int i = 0;
  for (; i < 26; i++){
    printf("Letter: %c", 'a' + i);
    print_list(table[i]);
  }
}

void shuffle(int count){
  int randNum;
  struct song_node *p;
  while (count){
    randNum = rand() % 26;
    if (
  } 
}

void delete_song(char *name, char *artist){

}

void delete_all(){

}
