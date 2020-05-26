#include"../list.h"
#include"../Struct/song.h"
typedef list playlist;

playlist new_playlist();
int add_song(playlist p,song e);
int delete_song(playlist p, song e);
song search_song(playlist p, char* name);
void print_playlist(playlist p);
int split_list(playlist p, int delimeter,playlist *p1,playlist *p2);