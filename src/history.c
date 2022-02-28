#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List *init_history(){
  List *list = malloc(sizeof(List)); // craeting memory of the size of the list to allocate
  list->root = malloc(sizeof(Item)); // setting the root allocation
  return list;
}
//
/* helper string*/
int endOfString(char *str)
{
  int count = 0;
  while(*str !='\0') {
    count++;
  }
  return count;
}
/*-----------------------*/
void add_history(List *list, char *str)
{
  Item *temp = list -> root;
  if(temp == NULL) {
    Item *newNode = (Item*)malloc(sizeof(Item));
    char *newStr = copy_str(str, endOfString(str));
    newNode ->id= 1, newNode->str = newStr, newNode->next=NULL;
  }
  
  else {
    int index = 1;
    while(temp !=NULL) {
      temp = temp->next;
      index++;
    }
    temp->next = (Item*)malloc(sizeof(Item));
    temp->next->id=index;// id is the place whre the node is 
    temp->next->str=copy_str(str,endOfString(str));// attaching the string..
  }
}
char *get_history(List *list, int id)
{
  Item *temp= list->root;
  while(temp !=0) {
    if(temp->id == id) { //? gotta know why****
      return temp ->str;
    }
    temp =  temp ->next;
  }
  printf("No Token Found");
  return '\0';
}
void print_history(List *list)
{
  if(!list) {
    printf("There is no log History!\n");
  }
  else {
    Item *temp = list->root;
    while(temp !=0) {
      printf("Log History [%d]: %s\n", temp->id, temp->str);
      
      temp ->next;
    }
  }
}
void free_history(List* list) {
  Item *temp;
  Item *head = list ->root;
  while(temp) {
    temp = head;
    head = head ->next;
    free(temp);
  }
  printf("Histroy has been Free.");
}
