#include <stdio.h>
#include "history.h"
#include "tokenizer.h"
#include <stdlib.h>
int main()
{
  puts("Welcome User");// welcoming message
  
  while(1)
    {
      /* Debugging Part ------------*/
      //char str[100];// storage
      //fputs(">",stdout); // inputing message
      //fgets(str,sizeof(str),stdin); // storing the string.
      //fputs(str,stdout);// print the strings
      // =========Testing debbuging uncomment==============
      //printf("from uimain: word count=%d\n",count_words(str));
      //puts("Straring the Tokenizer-----");
      //char **tokenv = tokenize(str);
      //printf("%s\n",tokenv[1]);
      //print_tokens(tokenv);
      //free_tokens(tokenv);
      //========= End of Debbugin Space=========
      char choice[100];
      char str[100];
      List *hList = init_history();
      printf("Please Choose an option \n a) make Tokens\n b) show History\n enter the number\n c) quit\n");
      fputs(">",stdout);//inputing message
      fgets(str,sizeof(choice),stdin);// storing the string.
      fputs(str,stdout);// priont the string
      add_history(hList, choice);
      switch (choice[0]) {
      case 'a':
	printf("Please enter a Sentence");
	fputs(">",stdout);
	fgets(str,sizeof(str),stdin);
	add_history(hList,str);
	char **tokenv = tokenize(str);
	print_tokens(tokenv);
	free_tokens(tokenv);
	break;
      case 'b':
	print_history(hList);
	free_history(hList);
	break;
      case 'c':
	goto done;// pointer go to terminate the program
      }
    }
 done:// end command
  return 0;
}
