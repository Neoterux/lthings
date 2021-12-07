#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_args(size_t argc, char **argv);

int main (int argc, char *argv[]){
	printf("The quantity of args: %d\n", argc);
	size_t length = sizeof(*argv);
	print_args(length, argv);

	printf("PRINTING WITH ARGC\n");
	print_args(argc, argv);	
}

void print_args(size_t argc, char **argv)
{
	for(int i = 0; i < argc; i++){
		printf("Arg at position [%d]: %s\n", i, argv[i]);
	}
}
