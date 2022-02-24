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
	int i;
	struct td_node *td = NULL;

	todo_init(&td,FILENAME,MAX_LINE_LENGTH);

	if(argc == 1)
		print_todo(&td);
	
	/*if(argc == 1){
	}else{

			while((option = getopt(argc,argv,"a")) != -1){
		
			switch(option){
			case 'a':
				printf("-a flag!\n");
				break;
			}*/
	
	
	todo_free(td);
	return 0;
}
