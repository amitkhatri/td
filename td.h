struct td_node{
	char *data;
	struct td_node *next;
};

void todo_init(struct td_node** head, const char* filename, int lim);
void todo_add(struct td_node** head, char* str);
void todo_free(struct td_node* head);
void print_todo(struct td_node** head);
