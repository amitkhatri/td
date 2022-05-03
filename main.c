#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "td.h"
#include "helper.h"

#define FILENAME ".todo"
#define MAX_LINE_LENGTH 50

int main(int argc, char* argv[]){

	int option;
	struct td_node *td = NULL;
	char **ptr;

	char td_string[MAX_LINE_LENGTH];
	td_string[0] = '\0';

	todo_init(&td,FILENAME,MAX_LINE_LENGTH);

	if(argc == 1){
		todo_print(&td);
	}
	else{
		while((option = getopt(argc,argv,"ad")) != -1){
			switch(option){
				case 'a':
					//concatenate_args(argv,argc);
					//printf("The todo string is: %s\n",td_string);
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
