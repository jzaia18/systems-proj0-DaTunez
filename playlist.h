#ifndef PLAYLIST_H
#define PLAYLIST_H

struct song_node *table[26];

//Functions
void add_song(char *, char *);
struct song_node *search(char *, char *);


#endif
