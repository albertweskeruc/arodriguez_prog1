# include <stdio.h>

# include <stdlib.h>

# include "arodriguez_argtok.h"



int string_length(char* str){
  //check for '\0' as the end end parameter in the for loop//
  // in order for the function to know when the string ends//

  int counter = 0;
  int i;
  
  for(i = 0; str[i] != '\0'; i++){
    counter++;
  }
  return counter;
}

//checks if its a valid char or if its '\n' or '\0'
char is_valid_character(char c){
  
  if((c > 32 && c < 127)){
    //  printf("char is valid   "); used for debug
    return 1;
  }
  
  else{
    // printf("not valid "); used for debug
    return 0;
  }
    
}

//find start of each word in a string
char* word_start(char* str){ 
  
  while(is_valid_character(*str) == 0){
    str = str +1;
    }
  return str;
    
}

//find end of a word once start of a word is found
char* word_end(char* str){

  while(is_valid_character(*str) == 1){
    str = str + 1;
    }
  
      return str;
    
}

//counts how many words are in a string to determine how many rows to allocate for our
//char** argtok funtion
int count_words(char* str){

  int counter = 0;
  while (*str != '\0'){
    str = word_start(str);
    str = word_end(str);
    counter++;
  }
  // printf( "%d \n", counter); used for debug
  return counter;
}

//go through the array of pointers created and print each string stored in the array
void print_tokens(char**str){

  
  // %c chars-must use another for loop   %s strings - using this one

  int i = 0;
  
  for(i = 0; str[i] != NULL ; i++){
    //printf("2"); used for debug
    printf("Token[%d]: %s\n",i, str[i]);

  }
   
  return;
}




//free all the tokens in the char** created by argtok()
void free_tokens(char**str){

  
  
  int i;
  for(i = 0; str[i] != NULL;i++){
    free(str[i]);
  }    
  free(str);
}

char* copy_word(char* str){
 
  int word_size = 1;
  char* t = str;
  //find the word size to allocate proper memory size
  while(is_valid_character(*t) != 0){
    word_size++;
    t++;
  }
  t = str;
  char* copy = (char *)malloc(word_size * (sizeof(char)));
  char* t2 = copy; //dont want to mess with copy nor str. playing safe
  while(is_valid_character(*t) != 0){
    *t2 = *t;
    t++;
    t2++;
  }

  *t2 = '\0'; // finishing touches to indicate end of word
  
  return copy;
}


char ** argtok(char* str){

  
  char** RESULTS;
  
  int Num_Words = count_words(str)+ 1; //plus one because the last will contain null or '\0' for
                                       // the free_token()
  RESULTS = (char **)malloc( Num_Words *(sizeof(char *))); // this creates the # rows

  int i = 0;
  while(*str != '\0'){ // -1 to leave room for the last row for the null
                                                // or '\0'
    str = word_start(str);
    RESULTS[i] = copy_word(str);
    str = word_end(str);
    
    i++;
  }
   RESULTS[i] = NULL;
  
  return RESULTS;
}
