#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FILENAME ".td"

bool todo_exists(const char* filename);
void create_todo_list(const char* filename);


int main(int argc, char* argv[]){
 	
	//Look into getops for parsing input args

	if(todo_exists(FILENAME)){
		printf("File exists\n");
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
