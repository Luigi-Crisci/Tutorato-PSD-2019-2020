#include"../item.h"

typedef struct node* Btree;

/**
 * t = <e,sx,dx>, get_root(t) -> e
 * Pre: t != NULL
 */
item get_item(Btree t);

/**
 * new_tree() -> b
 * Post: b != NULL
 */
Btree new_tree();

/**
 * empty_btree() --> i
 * Post: i == 1 se b == NULL, 0 altrimenti
 */
int empty_btree(Btree b);

/**
 * b=<q,sx,dx>,  set_root(b,e) --> i
 * Pre: b != NULL
 * Post: i == 0 && b = <q,sx,dx>, i == 1 && b = <e,sx,dx>
 */
int set_item(Btree b, item e);

/**
 * b = <e,sx,dx>, get_right(b) -> sx
 * Pre: b != NULL
 * Post: dx
 */
Btree get_right(Btree b);

/**
 * b = <e,sx,dx>, get_right(b) -> sx
 * Pre: b != NULL
 * Post: sx
 */
Btree get_left(Btree b);

/**
 * consBTree(e,sx,dx) --> b = <e,sx,dx>
 * Post: b != NULL && b = <e,sx,dx>
 */
Btree consBTree(item e, Btree sx, Btree dx);

/**
 * input_tree() --> b
 */
Btree input_tree();