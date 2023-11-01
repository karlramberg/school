/*
 Author: Karl Ramberg
 Date: 10/18/19
 Program to manage text file databases to store information
 about classes
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"class_info.h"
#include"io.h"
#include"add.h"
#include"remove.h"

#define TRUE 1
#define FALSE 0
#define MAX_DATABASE_SIZE 64
#define MAX_COMMAND_LENGTH 64

int main(int argc, char** argv) {
	// create a new database of classes 
	class_info_t* database[MAX_DATABASE_SIZE];
	int size = open_database(database, argv[1]);

	// command prompt loop
	int done = FALSE;
	while(!done) {
		printf("> ");
		char command[MAX_COMMAND_LENGTH];
		scanf("%s", command);

		if(strcmp(command, "list") == 0) {
			for(int i = 0; i < size; i++) {
				printf("%d: %s %s - %s\n",
					i+1,
					database[i]->department,
					database[i]->number,
					database[i]->location);
			}
		} else if (strcmp(command, "add") == 0) {
			size = add_class(database, size);
		} else if (strcmp(command, "remove") == 0) {
			size = remove_class(database, size);
		} else if (strcmp(command, "exit") == 0) {
			done = TRUE;
			save_database(database, argv[1], size);
			for(int i = 0; i < size; i++) {
				free(database[i]);
			}
		} else {
			printf("Invalid command, please enter list, add, remove, or exit\n"); 
		}
	}
}
