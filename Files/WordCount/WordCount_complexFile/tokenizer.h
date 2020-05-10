#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WORD_LENGTH 30
#define DEFAULT_DELIMITER_SIZE 45

int define_delimiters(char *path);
int is_delimeter(char c);
char* next_word(FILE *file);