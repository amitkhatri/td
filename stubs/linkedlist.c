#include <stdio.h>
#include <stdlib.h>

struct Node{
	char *data;
	int index;
	struct Node* next;
};

int main(void){
	
	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;

	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));

	head -> index = 1;
	head -> data = "FUCK";
	head -> next = second;


	second -> index = 2;
	second -> data = "YOU";
	second -> next = third;

	third -> index = 3;
	third -> data = "TOO";
	third -> next = NULL;

	struct Node* n = head;

	while(n != NULL){
		printf("%d: %s\n",n -> index, n -> data);
		n = n -> next;
	}

	free(head);
	free(second);
	free(third);

	return 0;
}
