#include"stack_array.h"
#include<stdlib.h>
#include"item.h"
#define DEFAULT_DIM 50
#define DEFAULT_INCREMENT 10
#define STRUCTSIZE sizeof(struct c_stack)

struct c_stack{
	item *array;
	int size,max_size;
};

stack new_stack(){
	stack s = malloc(STRUCTSIZE);
	s -> array = malloc(sizeof(item) * DEFAULT_DIM);
	s -> size = 0;
	s -> max_size = DEFAULT_DIM;
	return s;
}

int empty_stack(stack s){
	return s -> size == 0;
}

static int full(stack s){
	return s -> size == s -> max_size;
}

int push(stack s,item e){
	s -> array[s -> size] = copy_item(e);
	if ( full(s) ){
		s -> max_size+= DEFAULT_INCREMENT;
		s -> array = realloc( s -> array, sizeof(item) * (s -> max_size) );
		if( s -> array == NULL)
			return 0;
	}
	return 1;
}

int pop(stack s){
	if(empty_stack(s))
		return 0;
	free(s -> array[s -> size]);
	s -> size--;
	return 1;
}

item get_top(stack s){
	if( empty_stack(s) )
		return NULLITEM;
	return s -> array[s -> size];
}

void print_stack(stack s){
	for (int i = s -> size; i > 0; i++){
		printf("Elem %d\n",i);
		output_item(s -> array[i]);
	}
}

void free_stack(stack s){
	for (int i = 0; i < s -> size; i++)
		free_item(s -> array[i]);
	free(s -> array);
	free(s);
}
