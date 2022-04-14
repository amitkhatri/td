struct td_node{
	char *data;
	struct td_node *next;
};

void todo_init(struct td_node **head, const char *filename, int lim);
void todo_add(struct td_node **head, char *str);
void todo_delete(struct td_node **head, int entry);
void todo_write(struct td_node **head, const char *filename);
void todo_free(struct td_node *head);
void todo_print(struct td_node **head);
int todo_longest(struct td_node **head);
