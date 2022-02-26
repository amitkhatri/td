#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "td.h"
void todo_init(struct td_node** head, const char* filename, int lim){
	
	FILE* fp;
	char line[lim];

	fp = fopen(filename,"r");
	while(fgets(line,lim,fp) != NULL){
		line[strlen(line)-1] = '\0';
		todo_add(head,line);
	}

	fclose(fp);

	return;
}	

void todo_add(struct td_node** head, char* str){

	struct td_node *new_node = malloc(sizeof(struct td_node));
	
	new_node -> data = malloc(strlen(str)+1);
	strcpy(new_node->data,str);
	new_node -> next = NULL;

	if(*head == NULL)
		*head = new_node;
	else{
		
		struct td_node *cursor = *head;

		while(cursor -> next != NULL)
			cursor = cursor -> next;

		cursor -> next = new_node;
	}

	return;		
}

void todo_delete(struct td_node** head, int entry){
	int i = 1;
	struct td_node* temp = *head;
	struct td_node* prev;

	if(entry == 1){
		*head = temp -> next;
		free(temp);
		return;
	}

	while(temp != NULL && i != entry){
		prev = temp;
		temp = temp -> next;
		++i;
	}

	if(temp == NULL){
		return;
	}

	prev -> next = temp -> next;
	
	free(temp);

	return;

}

void todo_write(struct td_node** head, const char* filename){
	FILE *fp;
	struct td_node* cursor = *head;

	fp = fopen(filename,"w+");

	while(cursor != NULL){
		fputs(cursor->data,fp);
		fputs("\n",fp);
		cursor = cursor -> next;
	}

	fclose(fp);

	return;

}

void todo_print(struct td_node** head){
	
	if(*head == NULL){
		printf("No Todos.\n");
		return;
	}
	
	struct td_node* cursor = *head;

	while(cursor != NULL){
		printf("%s\n",cursor -> data);
		cursor = cursor -> next;
	}
}

void todo_free(struct td_node* head){
	while(head != NULL){
		struct td_node* temp = head;
		head = head -> next;
		free(temp -> data);
		free(temp);
	}
}
