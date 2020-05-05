#include<stdlib.h>
#include<stdio.h>
#include"item.h"
#include"queue.h"
#define QUEUESIZE sizeof(struct c_queue)

typedef struct node{
	item e;
	node* next;
} node;

struct c_queue{
	struct node *head,*tail;
	int size; 
};

queue new_queue(){
	queue q = malloc(QUEUESIZE);
	q -> head = NULL;
	q -> tail = NULL;
	q -> size = 0;
	return q;
}

int empty_queue(queue q){
	return q -> size == 0;
}


int enqueue(queue q, item e){
	node *new = malloc(sizeof(node));
	if( new == NULL)
		return 0;
	new -> e = copy_item(e);
	new -> next = NULL;
	if( empty_queue(q) )
		q -> head = q -> tail = new;
	else{
		q -> tail -> next = new;
		q -> tail = new;
	}
	(q -> size)++;
	return 1;
}

int dequeue(queue q){
	if ( empty_queue(q) )
		return 0;
	if ( q -> size == 1){
		free_node( q -> head );
		q -> head = q -> tail = NULL;
	}
	else
	{
		node *tmp = q -> head;
		q -> head = q -> head -> next;
		free_node(tmp);
	}
	(q -> size)--;
	return 1;
}

item get_head_item(queue q){
	return empty_queue(q) ? NULLITEM : q -> head -> e;
}

static void free_node(node* n){
	free_item( n -> e);
	free(n);
}

void print_queue(queue q){
	for (node* tmp = q -> head; tmp != NULL; tmp = tmp -> next)
		output_item(tmp -> e);
}

void free_queue(queue q){
	for (node* tmp = q -> head,*succ; tmp != NULL; tmp = tmp -> next){
		succ = tmp -> next;
		free_node(tmp);
		tmp = succ;
	}
	free(q);
}