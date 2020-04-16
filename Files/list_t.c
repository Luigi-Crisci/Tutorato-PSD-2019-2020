#include"item.h"
#include<stdio.h>
#include<stdlib.h>
#include"list_t.h"


struct node{
	item e;
	struct node* next;
};

struct c_list{
	struct node* first;
	int n;
};

/**
 * pre: true
 * post: l -> first == NULL && l -> n == 0 
 */
list newList(){
	list l = malloc(sizeof(struct c_list));
	if(l != NULL){
		l -> first = NULL;
		l -> n = 0; 
	}
	return l;
}

/**
 * 	emptyList(list) -> b
 *	pre: l != NULL
 *  post: b == 1 se l -> first == NULL, b == 0 altrimenti
 */
int emptyList(list l){
	if(l == NULL)
		return -1;
	return (l -> n == 0) ? 1 : 0;
}

int sizeList(list l){
	return l -> n;
}

static struct node* consList(struct node* l,item e){
	struct node *new = malloc(sizeof(struct node));
	if( new == NULL)
		return NULL;
	new -> e = e;
	new -> next = l;
	return new;
}

static struct node* tailList(struct node* l){
	return l -> next;
}

/**
 * pre: 0 <= pos <= sizeList(l) && e != NULLITEM 
 * 		&& l = <a1,a2,...,an>, n>=0  
 * post: l = <a1,a2,....,a_pos-1,a_e,a_pos+1,...,an>, n > 0
 */
int insertList(list l, int pos, item e){
	if(l == NULL)
		return -1;
	struct node* tmp = insertItem(l -> first,pos,e);
	if( tmp == NULL)
		return -1;
	l -> first = tmp;
	l -> n++;
	return 1;
}

/**
 * pre: 0 <= pos <= sizeList(l) && e != NULLITEM 
 * 	 l != NULL
 * post: 
 */
static struct node* insertItem(struct node *l, int pos, item e){
	if(pos == 0)
		return consList(l,e);
	
	struct node* tmp = l, *prec;
	int i=0;
	while(tmp != NULL && i < pos - 1){
		i++;
		prec = tmp;
		tmp = tailList(tmp);
	}

	if(tmp == NULL)
		return NULL;
	else{
		tmp = consList(tmp,e);
		prec -> next = tmp;
	}

	return l;
}

/**
 * pre: l != NULL && 0 <= pos <= sizeList(l)
 * 		l = <a1,a2,..,a_pos,..,an>, n>0
 * post: l = <a1,a2,...,a_pos-1,a_pos+1,...,an>, n >=0
 */
int removeList(list l, int pos){
	if (l == NULL)
		return -1;
	struct node* tmp = removeItem(l->first,pos);
	if( tmp == NULL)
		return -1;
	l -> first = tmp;
	l -> n--;
	return 1;
}

static struct node* removeItem(struct node* l, int pos){
	struct node* tmp,*prec;
	if(pos == 0){
		tmp = tailList(l);
		free(l);
		return tmp;
	}

	tmp = l;
	int i = 0;
	while (tmp != NULL && i < pos - 1){
		i++;
		prec = tmp;
		tmp = tailList(tmp);
	}

	if(tmp == NULL)
		return NULL;
	else{
		prec -> next = tailList(tmp);
		free(tmp);
	}

	return l;
}