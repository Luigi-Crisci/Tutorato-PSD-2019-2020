#include"stack.h"

stack new_stack(){
	return newList();
}

int empty_stack(stack s){
	return emptyList(s);
}

int push(stack s,item e){
	return insertList(s,0,e);
}

int pop(stack s){
	return removeList(s,0);
}

item get_top(stack s){
	return getFirst(s);
}

void print_stack(stack s){
	outputList(s);
}

void free_stack(stack s){
	freeList(s);
}


