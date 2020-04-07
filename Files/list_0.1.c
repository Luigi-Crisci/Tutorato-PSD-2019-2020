#include"item.h"
#include<stdlib.h>
#include"list_0.1.h"

struct nodo {
    int e;
    struct nodo* next;
};

/**
 * newList() -> list
 * pre: true
 * post: list = NULL
*/
list newList(){
    return NULL;
}

/**
 * emptyList(list) -> int
 * pre: true
 * post: 0 se l != NULL, 1 se l == NULL 
 */
int emptyList(list l){
    if( l == NULL )
        return 1;
    else
        return 0;

    //return l == NULL ? 1 : 0;
}

/**
 * consList(item,list) -> l
 * pre: l = <a1,a2,...,an>, n>=0
 * post: l = <e,a1,a2,...,an>, n>=1
 */
list consList(item e, list l){
    list new = malloc(sizeof(struct nodo));
    new -> e = e;
    new -> next = l;
    return new;
}

/**
 * tailList(list) -> list
 * pre: l = <a1,a2,...,an>, n>0
 * post: l = <a2,a3,...,an>, n>=0
*/
list tailList(list l){
    if( emptyList(l) )
        return NULL;
    return l -> next;
}

/**
 * getFirst(list) -> item 
 * pre: l = <a1,a2,....,an>, n>0
 * post: item = a1 -> e
 */
item getFirst(list l){
    if( emptyList(l) )
        return NULLITEM;
    return l->e;   

    //return (emptyList(l)) ? NULLITEM : l-> e;
}


