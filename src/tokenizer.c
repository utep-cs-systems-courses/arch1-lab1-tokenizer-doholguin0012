#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
int space_char(char c){// point of the character is empty, space or a tab
  //printf("-->%c\n",c);
  return ( c == ' '||  c == '\t') ? 1:0;// logical parameters to check
}
int non_space_char(char c){// checking if the char is empty, space, or tab
  //printf("-->%c\n",c);
  return (c != ' '&& c != '\t' && c != '\0') ? 1:0;  //logical parameters.:
}
char *word_start(char *str){// the the first letter for the char of a word
  while(space_char(*str) && *str) {
    printf("word start founding char <%c>\n",*str);
    str+=1;
  }
  printf("word start found char<%c>\n",*str);
  return str;
}
char *word_terminator(char *word)
{
  printf("I am starting with the word <%c>\n",*word);
  while(*word){
    if(!non_space_char(*word)) {
      printf("I am returning char[%c]\n",*word);
      return word;
    }
    word++; // iterates through a string until the end of a word
  }
  puts("I didnt find a word");
  return word; // returns index after a word end
}
int count_words(char *instr)
{
   int count=0;
   while(*instr != '\0') {
     printf("printing String %s\n",instr);
     instr = word_start(instr);// finds start of a new word
     printf("Found word char<%c>\n",*instr);
     instr = word_terminator(instr);
     printf("Found end word <%c>\n",*instr);
     count++;
  }
  return count;
}
char *copy_str(char *inStr, short len){
  int  i =0;
  char *cpy = malloc((len+1)* sizeof(char));
  while(i<=len){
    cpy[i] = inStr[i];
    i++;
  }
  cpy[i] = '\0';
  // printf("-->%s\n",cpy);
  return cpy;
  
}

char **tokenize(char *str)
{
  int wordCount = count_words(str);
  printf("There is a total word <%d>\n",wordCount);
  char **tokenv = (char**) malloc((wordCount +1) * sizeof(char *));// memory tokens
  char **strv = tokenv;
  printf("Token size is [%d]\n",wordCount);
  char *endp = str;
  
  while((wordCount>0)) {
    printf("The start word is <%c>\n",*str);
    str = word_start(str);
    puts(str);
    endp = word_terminator(str);
    *tokenv = copy_str(str, endp - str);
    *(tokenv +=1);
    str = endp;
    //printf("Tokens[%d]: %s\n:",wordCount,*tokenv);
    wordCount--;
  }
  *tokenv ='\0'; // set the final token to null/terminator
  puts("token finish");
  return strv;
}
void print_tokens(char **tokens)
{
  int i = 0;// debug counter
  while(*tokens) {
    printf("token[%d]: %s\n",i,*tokens);
    //printf("%d\n",i);
    tokens++;
    i++; //debug counter
  }
}
void free_tokens(char **tokens)
{
  int index =0;
  puts("Trying to ");
  while(*(tokens+index) != 0) {
    printf("freeing token: %s\n", *(tokens+index));
    free(*(tokens+index));
    index++;
  }
  free(tokens);
  puts("all tokens free");
}
