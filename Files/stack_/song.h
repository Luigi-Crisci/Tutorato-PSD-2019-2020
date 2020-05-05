typedef struct c_song{
	char name[256];
	char artist[256];
	double length;
} *song;


void input_song(song *s);
void output_song(song s);

//Implement item interface
void input_item_struct(song *s);
void output_item_struct(song s);
int compare_struct(song s1,song s2);
song copy_struct(song c);
void free_struct(song c);

