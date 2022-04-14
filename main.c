#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "td.h"

#define FILENAME ".todo"
#define MAX_LINE_LENGTH 50

int main(int argc, char* argv[]){

	int option;
	struct td_node *td = NULL;
	char **ptr;

	todo_init(&td,FILENAME,MAX_LINE_LENGTH);

	if(argc == 1){
		todo_print(&td);
	}
	else{
		while((option = getopt(argc,argv,"ad")) != -1){
			switch(option){
				case 'a':
					todo_add(&td,argv[2]);
					break;
				case 'd':
					todo_delete(&td,strtol(argv[2],ptr,10));
					break;
			}
		}
	}


	todo_write(&td,FILENAME);


	
	todo_free(td);
	
	return 0;
}
