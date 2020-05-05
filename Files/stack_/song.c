#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"song.h"

song create_song(){
	return malloc(sizeof(struct c_song));
}

char* fgets_local(char*,int,FILE*);

void input_song(song *s){
	if(s == NULL)
		return NULL;
	*s = create_song();
	printf("---SONG INSERT---\n");
	printf("Inserisci il nome della traccia: ");
	fgets_local((*s) -> name, 256, stdin);
	printf("Inserisci il nome dell'artista: ");
	fgets_local((*s) -> artist, 256, stdin);
	printf("Inserisci la durata della traccia: ");
	scanf("%lf", &((*s) -> length));
	fgetc(stdin); //Removes newline character from stdin
}

void output_song(song s){
	printf("Name: %s -- Artist: %s --- length: %lf\n",s->name,s->artist,s->length);
}

/**
 * item interface implementation
 */

void input_item_struct(song* s){
	input_song(s);
}

void output_item_struct(song s){
	output_song(s);
}

int compare_struct(song s1,song s2){
	int res;
	if ( (res = strcmp(s1 -> name, s2 -> name)) != 0)
		return res;
	if((res = strcmp(s1 -> artist, s2 -> artist)) != 0)
		return res;
	if( s1 -> length == s2 -> length)
		return 0;
	return s1 -> length > s2 -> length ? 1 : -1;
}

song copy_struct(song e){
	song copy = new_cell();
	*copy = *e;
	strcpy(copy-> artist,e->artist);
	strcpy(copy -> name, e -> name);
	return copy;
}

void free_struct(song e){
	free(e);
}

/**
 * Modified version of fgets to remove newline character stored by fgets
 */
char* fgets_local(char* buff,int size,FILE* source){
	fgets(buff,size,source);
	if(buff[strlen(buff) - 1] == '\n')
		buff[strlen(buff) - 1] = '\0';
	return buff;
}


