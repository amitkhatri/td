#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "td.h"

#define FILENAME ".todo"
#define MAX_LINE_LENGTH 60

int main(int argc, char* argv[]){
 	
	int option;
	int i;

	if(argc == 1){
		print_todo_list(FILENAME,MAX_LINE_LENGTH);
		return 0;
	}


	while((option = getopt(argc,argv,"a")) != -1){
		
		switch(option){
		case 'a':
			add_todo(FILENAME,argv[2],MAX_LINE_LENGTH);
			break;
		}
	}

	

	return 0;
}
