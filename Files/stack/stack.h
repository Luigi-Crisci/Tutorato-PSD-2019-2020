#include"list_t.h"
typedef list stack;

stack new_stack();
int empty_stack(stack s);
int push(stack s,item e);
int pop(stack s);
item get_top(stack s);
void print_stack(stack s);
void free_stack(stack s);


