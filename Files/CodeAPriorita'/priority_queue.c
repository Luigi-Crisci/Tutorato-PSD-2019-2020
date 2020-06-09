#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"
#include "../item.h"
#define MAX_DIM 50

struct pqueue_c
{
	item vet[MAX_DIM];
	int dim;
};

pqueue new_pqueue()
{
	pqueue q;
	q = malloc(sizeof(struct pqueue_c));
	if (q == NULL)
		return NULL;
	q->dim = 0;
	return q;
}

/**
 * empty_queue(q) -> i
 * pre: q != NULL
 * post: (i == 1 && q -> dim > 0) || (i == 0 && q -> dim == 0)
 */
int empty_queue(pqueue q)
{
	return q->dim == 0 ? 0 : 1;
}

int is_full(pqueue q)
{
	return q->dim == MAX_DIM ? 1 : 0;
}

/**
 * q = <a1,a2,.....,a_dim>, get_max(q) -> i
 * pre: q -> dim > 0
 * post: i = a1
 */
item get_max(pqueue q)
{
	if (empty_queue(q))
		return NULLITEM;
	return copy_item(q->vet[1]);
}

static void fix_up(pqueue q){
	int pos = q -> dim;
	int i = q -> dim / 2;

	item tmp;
	while (pos > 1)
	{
		if ( q -> vet[i] < q -> vet[pos]){
			tmp = q -> vet[i];
			q -> vet[i] = q -> vet[pos];
			q -> vet[pos] = tmp;
			pos = i;
			i /= 2;
		}
		else
			break;
	}
}

/**
 * pre: e != NULLITEM && q -> dim < MAX_DIM
 * post: is_heap(q)
 */
int enqueue(pqueue q, item e)
{
	if (e == NULLITEM || is_full(q))
		return 0;
	q->vet[++(q->dim)] = copy_item(e);

	fix_up(q);
	return 1;
}


static void fix_down(pqueue q){
	int curr = 1;
	int child;
	item tmp;

	while(1){
		//Trovo con chi confrontarmi
		if((curr*2) + 1 <= q -> dim)
			child = (q -> vet[curr*2] > q->vet[curr*2 + 1]) ? curr*2 : curr*2 + 1;
		else if( curr*2 <= q -> dim)
			child = curr * 2;
		else break;
		//Effettuo il confronto
		if( q -> vet[curr] < q -> vet[child]){
			tmp = q ->vet[curr];
			q -> vet[curr] = q -> vet[child];
			q -> vet[child] = tmp;
			curr = child; 
		}
		else break;
	}
}

/**
 * pre: !empty_queue(q)
 * post: is_heap(q)
 */
int dequeue(pqueue q){
	if ( empty_queue(q) )
		return 0;
	
	free_item(q -> vet[1]);
	q -> vet[1] = q -> vet[q -> dim];

	fix_down(q);
	return 1;
}
