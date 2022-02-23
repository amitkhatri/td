#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "td.h"
bool todo_exists(const char* filename){

	FILE *fp;

	if((fp = fopen(filename,"r"))){
		fclose(fp);
		return true;
	}
	
	return false;
}

void create_todo_list(const char* filename){
	
	FILE *fp;

	fp = fopen(filename, "w");
	fclose(fp);

	return;
}


void print_todo_list(const char* filename,int lim){

	FILE *fp;
	char line[lim];
	int c;

	fp = fopen(filename,"r");
	c = fgetc(fp);

	if(c == EOF){
		printf("NO TODOS \n");
		return;
	}
	
	/* fgetc advances the buffer one character. ungetc will
	   set the buffer back one character.

	   Without ungetc(c,fp), fgets will miss the first
	   character from the file stream
	*/

	ungetc(c,fp);

	while(fgets(line,lim,fp) != NULL)
		printf("%s",line);

	fclose(fp);

	return;
}


void add_todo(const char* filename, char* line, int lim){

	FILE *fp;

	fp = fopen(filename,"a");
	fputs(line,fp);
	fputs("\n",fp);

	fclose(fp);

	printf("\"%s\" sucessfully added to todos\n",line);

	return;


}

void todo_init(struct td_node* head, const char* filename, int lim){
	
	FILE *fp;
	char line[lim];
	int c;

	fp = fopen(filename,"r");
	c = fgetc(fp);

	if(c == EOF){
		return;
	}


	/* fgetc advances the buffer one character. ungetc will
	   set the buffer back one character.

	   Without ungetc(c,fp), fgets will miss the first
	   character from the file stream
	*/

	ungetc(c,fp);


	while(fgets(line,lim,fp) != NULL)
		//Add each todo to the linked list
		printf("%s",line);
	

	fclose(fp);
}

void todo_add(struct td_node** head, char* str){
	struct td_node *new_node = malloc(sizeof(struct td_node));
	new_node -> data = str;
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

void print_linked_list(struct td_node* head){
	
	struct td_node* cursor = head;

	while(cursor != NULL){
		printf("%s\n",cursor -> data);
		cursor = cursor -> next;
	}
}