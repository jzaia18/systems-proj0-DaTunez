/*Team DaTunez -- Piotr Milewski & Jake Zaia
  Systems pd10
  Project 00
  2017-10-13*/

#include "nodeList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// helper fxn to create node
struct song_node *create_node( char *name, char *artist, struct song_node *next) {
  struct song_node *newNode = (struct song_node *)malloc(sizeof(struct song_node));
  newNode->name = name;
  newNode->artist = artist;
  newNode->next = next;
  return newNode;
}

/*takes a pointer to an existing list & the data to be added, creates a new node & puts it at the beginning of the list
  returns a pointer to the beginning of the list*/
struct song_node *insert_front(struct song_node *list, char *name, char *artist){  
  return create_node(name, artist, list);
}


// Inserts a node in order (by artist name)
struct song_node *insert_order(struct song_node *list, char *name, char *artist) {
  while (!list->next && strcmp(artist, list->artist) < 0)
    list = list->next;
  return create_node(name, artist, list);
}


//takes a pointer to a node struct & prints out all the data in the list
void print_list(struct song_node *list){
  printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  while(list){
    printf("\"%s\" by %s\n", list->name, list->artist);
    list = list->next;
  }
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
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
