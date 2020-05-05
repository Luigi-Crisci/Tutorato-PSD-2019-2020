typedef struct c_queue *queue;

queue new_queue();
int enqueue(queue q, item e);
int dequeue(queue q);
item get_head_item(queue q);
void free_queue(queue q);
void print_queue(queue q);
int empty_queue(queue q);