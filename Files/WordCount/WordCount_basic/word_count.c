#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../list.h"
#include "../Struct/cell.h"

/**
 * Find next word, delimited only by newline characters and spaces
 */
char* next_word(FILE* fc){
	char *word = calloc(30,sizeof(char));
	char c;
	int length = 0;
	while ( (c=fgetc(fc)) != EOF)
	{
		if((c == ' ' || c == '\n') && length == 0)
			continue;
		if((c == ' ' || c == '\n') && length > 0){
			word[length] = '\0';
			return word;
		}
		word[length++] = c;
	}
	
	if( length == 0)
		word = NULL;
	else
		word[length] = '\0';
	return word;
}

int main(int argc, char **argv)
{
	if(argc < 2){
		fprintf(stderr,"No path provided, please relaunch with a filepath\n");
		return 0;
	}

	char *path,*word;
	path = malloc( sizeof(char) * strlen(argv[1]));
	strcpy(path,argv[1]);
	FILE *fc = fopen(path,"r");
	list list = newList();

	cell tmp;
	tmp.value = 1;
	while ((word = next_word(fc)) != NULL)
	{
		strcpy(tmp.key, word);
		if(!updateList(list,&tmp))
			if(!insertList(list,0,&tmp)){
				fprintf(stderr,"Error while using list\n");
				return 1;
			}
		free(word);
	}
	fclose(fc);

	outputList(list);

	return 0;
}