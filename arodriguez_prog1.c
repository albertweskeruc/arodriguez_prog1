#include <stdio.h>

#include <stdlib.h>

#include "arodriguez_argtok.h"

/*To run type make to compile make file, then ./prog_1 to run executeable, then type a string into
the interface provided, to end the program simply type ! and it will stop the program*/

char* UI(int length); //this reads the user input by using fgets()


int main(){

   int MAX = 200;
   
   
   int i = 1; 
   char UserInput[MAX];
   
   while(i){
     

  printf("Begin typing:$");

  char* holder = UI(MAX); // calls UI() function to convert user input into a string
                          // or char pointer 

  if(*holder == '!'){ //if user inputs !, it will end the infinite loop of grabbing user input
    
    free(holder);
    return 0;
    
  }
  else{
  
  char** tokens = argtok(holder); //the char pointer or string that is returned from UI will be
                              //passed into argtok to create an array with each word in the string 
  free(holder); 
  print_tokens(tokens);
  free_tokens(tokens);
  }
   


   }
}


char* UI(int length){ 
  
  char UserInput[length];
  char* temp1;
  char* temp2;
  char* temp3; // this variable will keep track of each character the user inputs until the user
               //hits enter
  int actual_size = 1;
  fgets(UserInput,length,stdin);
  temp3 = UserInput;
  while(*temp3 != '\n'){
    temp3++;
    actual_size++;
  }
  *temp3 = '\0';
  char* point = (char *)malloc(actual_size * (sizeof(char)));
  temp1 = UserInput; // variable will go traverse the userinput to put into point
  temp2 = point; // variable will traverse point and copy the char of userinput at that position

  while(*temp1 != '\0'){
    *temp2 = *temp1;
    temp1++;
    temp2++;
  }
  
  *temp2 = '\0'; //end of string 

  return point; // returns the copied user input in a variable with the exact size of the string
  
}
