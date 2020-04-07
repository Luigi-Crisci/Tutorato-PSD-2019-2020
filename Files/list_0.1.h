#include"item.h"
typedef struct nodo* list;

/**
 * newList() -> list
 * pre: true
 * post: list = NULL
*/
list newList();

/**
 * emptyList(list) -> int
 * pre: true
 * post: 0 se l != NULL, 1 se l == NULL 
 */
int emptyList(list l);

/**
 * consList(item,list) -> l
 * pre: l = <a1,a2,...,an>, n>=0
 * post: l = <e,a1,a1,...,an>, n>=1
 */
list consList(item e, list l);

/**
 * tailList(list) -> list
 * pre: l = <a1,a2,...,an>, n>0
 * post: l = <a2,a3,...,an>, n>=0
*/
list tailList(list l);

/**
 * getFirst(list) -> item 
 * pre: l = <a1,a2,....,an>,
 * post: item = a1 -> e
 */
item getFirst(list l);

/**
 * truncate(list l) -> l
 * pre: l = <a1,a2,...,an>, n>0
 * post: l = <a1>
 */
list truncate(list l);
