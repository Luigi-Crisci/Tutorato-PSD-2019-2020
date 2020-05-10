#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "list_t.h"
#include "cell.h"
#include "tokenizer.h"

void to_lower_string(char* word){
	for (int i = 0; i < strlen(word); i++)
		word[i] = tolower(word[i]);
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
		to_lower_string(word);
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