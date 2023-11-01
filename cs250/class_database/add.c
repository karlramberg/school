#include<stdio.h>
#include<stdlib.h>
#include"class_info.h"
#include"add.h"

/*
 add_class() asks the user for information about a class, 
 adds it to the end of the specified database,
 and returns the new size of the database
*/
int add_class(class_info_t* database[], int size) {
	database[size] = (class_info_t*)malloc(sizeof(class_info_t));
	printf("Enter department: ");
	scanf("%s", database[size]->department);
	printf("Enter number: ");
	scanf("%s", database[size]->number);
	printf("Enter location: ");
	scanf("%s", database[size]->location);
	return ++size;
}
