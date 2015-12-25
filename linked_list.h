typedef struct node_t node_t;

struct node_t {
   int value;
   node_t *next;
};

node_t* new_node(int value);

void add(int value);
void add_node(node_t *head, node_t *node);
void delete_node(node_t *node);

int index_of(node_t *head, node_t *node);
void print_list(node_t *node);

//returns head of list
node_t* remove_node(node_t* head, node_t* node);
void remove_last();
void delete_list();

int list_length(node_t *head);

