#include "tokenizer.h"

#include <stdlib.h>

#include <stdio.h>

#define true 1

#define false 0



/* Returns true if c is a whitespace character*/

int space_char(char c){

  if(c==' ' || c =='\t'){

    return true;

  }

  else{

    return false;

  }

}



/* Returns true if c is not a whitespace character*/

int non_space_char(char c) {

  if(c != ' ' && c != '\t'){

    return true;

  }

  else{

    return false;

  }

}



/* Return the beginning of str*/

char *word_start(char *str){

  while(!non_space_char(*str)){

    str = str + 1;

  }

  return str;

}



/* Return the end of word*/

char *word_terminator(char *word){

  while(non_space_char((*word))){

    word = word + 1;

  }

  return word;

}



/*Returns the count of words*/

int count_words(char* str){

  int out_count = 0;

  int in_count = 1;

  int curr_state = out_count;

  int count = 0;



  while(*str){

    if(*str == ' ' || *str == '\n' || *str == '\t'){

      curr_state = out_count;

    }

    else if (curr_state == out_count){
      curr_state = in_count;

      count++;

    }

    str++;

  }

  return count;

}



int length_of_string(char *str){



  int length = -1;



  while(str++){ //iterates through the string



    length++; //adds to counter



  }



  return length;



  exit(0);



}



/* Returns a freshly allocated new zero-terminated string*/

char *copy_str(char *strIn, short len){

  char* help = strIn;

  char* strCopy = NULL;



  strCopy = (char*) malloc(sizeof(char) * (len + 1));



  strCopy[len] = '\0';



  int index = 0;

  while(*help != '\0'){

    strCopy[index++] = *help++;

  }

  return strCopy;

}



/* Returns a freshly allocated zero terminated vector of freshly allocated space separated tokens from zero terminated str.*/



char** tokenize(char* str){

  int size = count_words(str);

  char **token;



  token = (char**) malloc((size+1) * sizeof(char*));

  char* starting = str;

  char* ending = word_terminator(str);

  int i;



  for(i = 0; i < size; i++){

    if(i > 0){

      starting = word_start(ending);

      ending = word_terminator(starting);

    }



    int size_second = ending - starting;

    token[i] = malloc(size_second * sizeof(char));



    for (int j = 0; j < size_second; j++){

      token[i][j] = starting[j];

    }

  }

  return token;

}



//prints all tokens//

void print_tokens(char **token){

  int i = 0;

  while(token[i] != NULL) {

    printf("%s\n", token[i]);

    i++;

  }

}



// frees all tokens and the vector containing them. //

void free_tokens(char **token){

  int i = 0;

  while(token[i]){

    free(token[i]);

    i++;

  }

  free(token);

}
