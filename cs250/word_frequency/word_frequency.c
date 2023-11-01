// Author: Karl Ramberg
// Date:   09/23/19
// Sorts the words of a text file lexicographically
// and counts each one's frequency

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1024
#define MAX_WORD_LEN 16
#define MAX_LINE_LEN 128
#define DELIM " \n\t"

typedef struct word {
	char the_word[MAX_WORD_LEN];
	int count;
} word_t;

// find_word() returns the index of word in list or -1 if word is not found
int find_word(char *word, word_t list[], int list_size) {
	for(int i = 0; i < list_size; ++i) {
		if(strcmp(word, list[i].the_word) == 0) {
			return i;
		}
	}
	return -1;
}

// sort_words() sorts a word_t array in lexicograpghical order using bubble sort
void sort_words(word_t list[], int list_size) {
	for(int i = list_size; i > 0; --i) {
		for(int j = 0; j < i; ++j) {
			if(strcmp(list[j].the_word, list[j + 1].the_word) > 0) {
				// swap the word's places
				word_t temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	// open the file with the name provided
	FILE *file = fopen(argv[1], "r");
	if(file == NULL) {
		printf("Failed to open %s!\n", argv[1]);
		exit(-1);
	}

	word_t word_list[MAX_WORDS];
	int word_list_size = 0;

	// run through the file line by line
	char line[MAX_LINE_LEN];
	while(fgets(line, MAX_LINE_LEN, file) != NULL) {
		// split each line into words
		char *word;
		word = strtok(line, DELIM);
		do {
			int word_index = find_word(word, word_list, word_list_size);
			if(word_index != -1) { // if the word is already listed 
				word_list[word_index].count++;
			} else { // if the word isn't already listed
				strcpy(word_list[word_list_size].the_word, word);
				word_list[word_list_size].count = 1;
				word_list_size++;
			}
		} while((word = strtok(NULL, DELIM)) != NULL);
	}

	// sort the list of words
	sort_words(word_list, word_list_size);

	// print the results in a tabular format
	for(int i = 1; i <= word_list_size; ++i) {
		printf("%16s:\t%d\n", word_list[i].the_word, word_list[i].count);
	}

	fclose(file);
	exit(0);
}
