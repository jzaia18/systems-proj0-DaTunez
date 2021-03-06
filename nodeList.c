/*Team DaTunez -- Piotr Milewski & Jake Zaia
  Systems pd10
  Project 00
  2017-10-13*/

#include "nodeList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Helper fxn to create node
struct song_node *create_node(struct song_node *next, char *name, char *artist) {
  struct song_node *newNode = (struct song_node *)malloc(sizeof(struct song_node)); //set mem for new node
  //set newNode's contents
  strcpy(newNode->name, name);
  strcpy(newNode->artist, artist);
  newNode->next = next;
  return newNode;
}

// Helper fxn to find the length of a song_node
int get_length(struct song_node *list){
  int length = 0;
  while (list){ //iterate through all the song_nodes
    length++; 
    list = list->next;
  }
  return length;
} 

/*takes a pointer to an existing list & the data to be added, creates a new node & puts it at the beginning of the list
  returns a pointer to the beginning of the list*/
struct song_node *insert_front(struct song_node *list, char *name, char *artist){  
  return create_node(list, name, artist);
}


// Inserts a node in order (by artist name)
struct song_node *insert_order(struct song_node *list, char *name, char *artist) {
  struct song_node *init = list; //pointer to beginning of list
  if (!list || (strcmp(artist, list->artist) < 0) || (strcmp(artist, list->artist) == 0 && strcmp(name, list->name) <= 0))
    return create_node(list, name, artist);
  //run until node hits an artist with a later name alphebetically
  while (list->next && strcmp(artist, list->next->artist) > 0)
    list = list->next;
  //run until node hits an title with a later name alphebetically (and also the same artist)
  while (list->next && strcmp(name, list->next->name) > 0)
    list = list->next;
  list->next = create_node(list->next, name, artist);
  return init;
}


// Takes a pointer to a node struct & prints out all the data in the list
void print_list(struct song_node *list){
  printf("\nAll songs in the list:\n");
  while(list){
    printf("   \"%s\" by %s\n", list->name, list->artist);
    list = list->next;
  }
  printf("\n\n");
}

// Iterates through the list until it hits a node with matching title and artist (null if not found)
struct song_node *find(struct song_node *list, char *name, char *artist){
  while (list){
    if (strcmp(name, list->name) == 0 && strcmp(artist, list->artist) == 0)
      return list;
    list = list->next;
  }
  return 0;
}

// Iterates through the list until it hits a node with matching title (null if not found)
struct song_node *find_song(struct song_node *list, char *artist){
  while (list){
    if (strcmp(artist, list->artist) == 0)
      return list;
    list = list->next;
  }
  return 0;
}

// Gets a random element from the list
struct song_node *get_rand(struct song_node *list){
  int length = get_length(list);
  int randNum = rand() % length;
  // Iterates through a number from [0,length) times
  for (; randNum > 0; randNum--){
    list = list->next;
  }
  return list;
}

// Remove a node given a title & artist
struct song_node *remove_song(struct song_node *list, char *name, char *artist){
  struct song_node *tmp;
  if (strcmp(name, list->name) == 0 && strcmp(artist, list->artist) == 0){ //if node is in first position, remove it
    tmp = list->next;
    free(list);
    return tmp;
  }
  struct song_node *init = list; //track first node
  while (list->next){
    if (strcmp(name, list->next->name) == 0 && strcmp(artist, list->next->artist) == 0){
      tmp = list->next->next;
      free(list->next);
      list->next = tmp;
      return init;
    }
    list = list->next;
  }
  return init;
}

/*takes a pointer to a list as a parameter, then goes through the entire list freeing each node
  returns a pointer to the beginning of the list*/
struct song_node *free_list(struct song_node *list){
  while (list){
    struct song_node *tmp = list;
    list = list->next;
    free(tmp);
  }
  return list;
}
