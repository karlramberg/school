#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"class_info.h"
#include"remove.h"

/*
 remove_class() removes the class matching a user query,
 automatically shrinks the database,
 and returns the new size of the database
*/
int remove_class(class_info_t* database[], int size) {
	printf("Enter department or number: ");
	char query[MAX_DEPARTMENT_LENGTH];
	scanf("%s", query);
	for(int i = 0; i < size; i++) {
		if(strstr(database[i]->department, query) != NULL
		   || strstr(database[i]->number, query) != NULL) {
			free(database[i]);
			for(int j = i; j < size-1; j++) {
				database[j] = database[j+1];
			}	
			break;
		}
	}	
	return --size;
}
