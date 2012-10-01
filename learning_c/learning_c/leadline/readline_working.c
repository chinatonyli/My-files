#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
 
int main() {
     char * test;
     test=readline("Prompt:");

     printf("%c\n",test[0]);
     free(test);
     
     return 0;
}
