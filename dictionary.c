/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "dictionary.h"

//structure for trie
typedef struct dict {
		bool is_word;
		struct dict* children[27];
	} dict;
dict* root;

//counter of words in dictionary
unsigned int counter = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word) {	 
	dict* cursor = root;
	for(int i = 0; word[i] != '\0'; i++) {		
		int k = (word[i] == '\'') ? 26 : tolower(word[i]) - 'a';			
		if (cursor -> children[k] == NULL) return false;
		else cursor = cursor -> children[k];
	}
	return cursor -> is_word;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
//creat a node
dict* new_leaf(void) {
	dict* node = malloc(sizeof(dict));
	if (node == NULL) {
		printf("malloc is faild");
		return NULL;
	}
	for(int i = 0; i < 27; i++)
		node -> children[i] = NULL;
	return node; 
 }
 
//building the trie 
bool load(const char* dictionary) {
	
	//open dictionary file 
	FILE* dict_file = fopen(dictionary, "r");
	if (dict_file == NULL) {
		printf("Dictionary is not opened");
		return false;
	}
	
	//root initialization
	root = new_leaf();

	//init. of variable for reading letters while eof
	int x = fgetc(dict_file);
	
	//read the string from dict_file while !EOF
	do {
		//make cursor pointing to the root
		dict* cursor = root;
		
		//reading the word
		for (int c = x; c != '\n'; c = fgetc(dict_file)) {
			//letter's index k for children[k]
			int k = (c == '\'') ? 26 : c - 'a';
			
			//pulling letter into the trie
			if (cursor -> children[k] == NULL) 
				cursor -> children[k] = new_leaf();
			cursor = cursor -> children[k];
		}
		cursor -> is_word = true;
		counter++;
		x = fgetc(dict_file);
	}
	while (x != EOF);
	
	//close file
	fclose(dict_file);
	return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
	return counter;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
//free memory from the trie
int del(dict* node){
	if (node != NULL)
		for(int i = 0; i < 27; i++)
			del (node -> children[i]);
	free(node);
	return 1;
}

bool unload(void) {
	return (del(root) == 1) ? true : false;
}

//for testing
/**int main() {
	int x = (load("my_dict")) ? 1 : 0;
	printf("x = %d\n", x);
	printf("%i\n", check("cat"));
	printf("%i\n", check("Kot"));
	printf("size = %i\n", size());
	int y = (unload()) ? 1 : 0;
	printf("y = %d\n", y);
}*/
