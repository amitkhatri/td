#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const char* FILENAME = ".td";

bool todo_exists(const char* filename);
void create_todo_list(const char* filename);
void print_todo_list(const char* filename);

int main(int argc, char* argv[]){
 	
	//Look into getops for parsing input args

	if(todo_exists(FILENAME)){
		print_todo_list(FILENAME);
	}
	else{
		printf("Todo file doesn't exist. Creating....\n");
		create_todo_list(FILENAME);
	}	





	return 0;
}

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


void print_todo_list(const char* filename){

	/*
	1. Open File
	2. If file is blank (ie: no todos) print message
	3. Else print the todo list to stdout
	*/
	FILE *fp;
	int c;

	fp = fopen(filename,"r");
	c = fgetc(fp);
	if(c == EOF){
		printf("NO TODOS \n");
	}
	else{
		//Print todo list
	}
	return;
}
