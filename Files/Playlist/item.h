typedef void* item;
#define NULLITEM NULL

void input_item(item *x);
void output_item(item x);
int compare_item(item x1,item x2);
item copy_item(item);
void free_item(item);