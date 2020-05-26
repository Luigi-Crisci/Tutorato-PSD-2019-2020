#include<stdlib.h>
#include<stdio.h>
#include"alb_bin.h"

struct node{
	item e;
	struct node *sx,*dx;
};

/**
 * new_tree() -> b
 * Post: b != NULL
 */
Btree new_tree(){
	return NULL;
}

/**
 * empty_btree() --> i
 * Post: i == 1 se b == NULL, 0 altrimenti
 */
int empty_btree(Btree b){
	return b == NULL;
}

/**
 * t = <e,sx,dx>, get_root(t) -> e
 * Pre: t != NULL
 */
item get_item(Btree t){
	return t -> e;
}


/**
 * b=<q,sx,dx>,  set_root(b,e) --> i
 * Pre: b != NULL
 * Post: i == 0 se b == NULL, i == 1 b = <e,sx,dx>
 */
int set_item(Btree b, item e){
	if( empty_btree(b) )
		return 0;
	b -> e = copy_item(e);
	return 1;
}

/**
 * b = <e,sx,dx>, get_right(b) -> sx
 * Pre: b != NULL
 * Post: dx
 */
Btree get_right(Btree b){
	return b == NULL ? NULL : b -> dx;
}

/**
 * b = <e,sx,dx>, get_right(b) -> sx
 * Pre: b != NULL
 * Post: sx
 */
Btree get_left(Btree b){
	return b == NULL ? NULL : b -> sx;
}

/**
 * consBTree(e,sx,dx) --> b = <e,sx,dx>
 * Post: b = <e,sx,dx>, altrimenti NULL
 */
Btree consBTree(item e, Btree sx, Btree dx){
	Btree b = (Btree) malloc(sizeof(struct node));
	if( b != NULL ){
		set_item(b,e);
		b -> sx = sx;
		b -> dx = dx;
	}
	return b;
}

/**
 * input_tree() --> b
 */
static Btree input_tree_(int level){

	int s;
	printf("Vuoi inserire un nodo (livello %d)?\n",level);
	scanf("%d",&s);
	if( s == 0)
		return NULL;

	item e;
	Btree sx, dx;

	input_item(&e);
	sx = input_tree_(level + 1);
	dx = input_tree_(level + 1);

	return consBTree(e,sx,dx);
}

Btree input_tree(){
	return input_tree_(0);
}


