#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"class_info.h"

#define DELIMETER ":\n"
#define MAX_LINE_LENGTH 128

/*
 open_database() reads in the file stored at path, fills the
 database provided and returns the final size
*/
int open_database(class_info_t* database[], char* path) {
	// open the database file for reading
	FILE* file = fopen(path, "r");
	if(file == NULL) {
		printf("Failed to open %s!\n", path);
		exit(-1);
	}

	// get the number of classes listed
	int size = 0;
	fscanf(file, "%d", &size);

	// eat the extra newline
	char* dummy = NULL;
	fscanf(file, "%s", dummy);

	// read and store each class in line-by-line
	char line[MAX_LINE_LENGTH];
	for(int index = 0; index < size; index++) {
		// get the next line
		fgets(line, MAX_LINE_LENGTH, file);

		database[index] = (class_info_t*)malloc(sizeof(class_info_t));

		// tokenize the line
		char* term = strtok(line, DELIMETER);
		strcpy(database[index]->department, term);
		term = strtok(NULL, DELIMETER);
		strcpy(database[index]->number, term);
		term = strtok(NULL, DELIMETER);
		strcpy(database[index]->location, term);
	}

	fclose(file);
	return size;
}

/*
 save_database() writes the provided database to the path given
*/
void save_database(class_info_t* database[], char* path, int size) {
	// open the file for writing
	FILE *file = fopen(path, "w");
	if(file == NULL) {
		printf("Failed to save data in %s", path);
		exit(-1);
	}

	// put the size on the first line
	fprintf(file, "%d\n", size);

	// write each class to it's own line
	for(int index = 0; index < size; index++) {
		fprintf(file, "%s:%s:%s\n",
			database[index]->department,
			database[index]->number,
			database[index]->location);
	}	

	fclose(file);
}
