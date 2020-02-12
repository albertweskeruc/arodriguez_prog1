#ifndef _ARGTOK_
#define _ARGTOK_


// counts number of chars in the string
int string_length(char* str);

//indicates if current char is a valid character or is a space or '\0'
char is_valid_character(char c);

// finds where a new word starts in a string
char* word_start(char* str);

// finds where a word ends after the start of the word is found
char* word_end(char* str);

// counts how many words are in a string to determine how many rows are going to be in an array
int count_words(char* str);

//this will copy the next word in the string into a correctly allocated string to add into
//designated row in the array
char* copy_word(char* str);

// uses all the functions 
char** argtok(char* str);

//prints each token in the array that is created from the userinput
void print_tokens(char** tokens);

//Frees all tokens and the array containing the tokens
void free_tokens(char** tokens);

#endif
