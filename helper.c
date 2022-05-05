#include <stdio.h>
#include <string.h>
void concatenate_args(char *argv[], int arg_count, char *output){
	int i = 2;

	while(i < arg_count){
		if(i == (arg_count - 1)){
			strncat(output,argv[i],strlen(argv[i]));
			return;
		}

		strncat(output,argv[i],strlen(argv[i]));
		strncat(output," ",1);
		
		++i;
	}
}



