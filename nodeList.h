#ifndef NODELIST_H
#define NODELIST_H

//structs
struct song_node{
  char name[256];
  char artist[256];
  struct song_node *next;
};

//Functions
struct song_node *insert_front(struct song_node *, char *, char *);
struct song_node *insert_order(struct song_node *, char *, char *);
void print_list(struct song_node *);
struct song_node *find(struct song_node *, char *, char *);
struct song_node *find_song(struct song_node *, char *);
struct song_node *get_rand(struct song_node *);
struct song_node *remove_song(struct song_node *, char *, char *);
struct song_node *free_list(struct song_node *);

#endif
