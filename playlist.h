#ifndef PLAYLIST_H
#define PLAYLIST_H

struct song_node *table[26];

//Helper Functions
int indexer(char *);

//Functions
void add_song(char *, char *);
struct song_node *search(char *, char *);
struct song_node *search_artist(char *);
void print_alpha(char);
void print_artist(char *);
void print_all();
void shiffle(int);
void delete_song(char *, char *);
void delete_all();

#endif
