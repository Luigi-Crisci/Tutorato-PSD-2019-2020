typedef struct pqueue_c *pqueue;

pqueue new_pqueue();
int empty_queue(pqueue q);
int is_full(pqueue q);
item get_max(pqueue q);
int enqueue(pqueue q, item e);
int dequeue(pqueue q);