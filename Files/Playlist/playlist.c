/**
 * Scrivere un modulo per la gestione di una playlist: questa è composta da un insieme di tracce, ed è 
 * possibile scorrerle (per ora solo in avanti), inserire una traccia, eliminare una specifica traccia,
 * ricercare un brano per nome e dividere la playlist a partire da una certa posizione;
 * OPT: permettere l'ordinamento della lista tramite il nome dei brani 
 * Una traccia è composta da un titolo, artista e durata 
 * 
 */
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"playlist.h"
#include"item.h"

playlist new_playlist(){
	return newList();
}

int add_song(playlist p,song e){
	return insertList(p,sizeList(p),e);
}

int delete_song(playlist p, song e){
	return removeList(p,searchItem(p,e));
}

song search_song(playlist p, char* name){
	if(name == NULL )
		return NULL;
	
	song s;
	for (int i = 0; i < sizeList(p); i++)
	{
		s = getItem(p,i);
		if(strcmp(s -> name,name) == 0)
			return s;
	}
	return NULL;
}

/**
 * split a list using a delimeter
 * NOTE: this function can create a memory leak, but I'll not say when. 
 * 		Find out by yourself, prevent it and commit the changes
 */
int split_list(playlist p, int delimeter,playlist *p1,playlist *p2){
	if(delimeter > sizeList(p) || delimeter < 0)
		return 0;
	if(delimeter == sizeList(p)){
		*p1 = cloneList(p);
		free(p);
		*p2 = NULL;
		return 1;
	}
	if(delimeter == 0){
		*p2 = cloneList(p);
		free(p);
		*p1 = NULL;
		return 1;
	}

	*p1 = newList();
	*p2 = newList();
	int switch_p = 0;
	for (int i = 0; i < sizeList(p); i++)
	{
		if(i == delimeter)
			switch_p = 1;
		if(!switch_p)
			insertList(*p1,sizeList(*p1),getItem(p,i));
		else
			insertList(*p2,sizeList(*p2),getItem(p,i));
	}
	free(p);
	return 1;
}

void print_playlist(playlist p){
	outputList(p);
}

