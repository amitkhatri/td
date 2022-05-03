#include <stdio.h>
#include <string.h>
char *concatenate_args(char **args, int arg_count, int line_length){
	
	int i = 2;
    char output[line_length];
	output[0] = '\0';

	while(i < arg_count){
		if(i == (arg_count - 1)){
			strncat(output,args[i],strlen(args[i]));
		}
		else{
			strncat(output, args[i],strlen(args[i]));
			strncat(output," ",1);
		}
		++i;
	}

//	printf("Output is %s\n",output);

	return output;
}



