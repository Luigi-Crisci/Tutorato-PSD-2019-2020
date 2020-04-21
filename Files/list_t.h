typedef struct c_list *list;

list newList();

int emptyList(list l);

int sizeList(list l);

static struct node* consList(struct node* l,item e);

static struct node* tailList(struct node* l);

int insertList(list l, int pos, item e);

static struct node* insertItem(struct node *l, int pos, item e);

int removeList(list l, int pos);

static struct node* removeItem(struct node* l, int pos);

list cloneList(list l);

item getFirst(list l);

item getItem(list l,int pos);

list inputList();

void outputList(list l);

list mergeList(list l1,list l2);

void freeList(list l);
