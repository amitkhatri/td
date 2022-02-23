struct td_node{
	char *data;
	int index;
	struct td_node *next;
};

bool todo_exists(const char* filename);
void create_todo_list(const char* filename);
void print_todo_list(const char* filename,int lim);
void add_todo(const char* filename, char* line, int lim);
void todo_init(struct td_node* head, const char* filename, int lim);
