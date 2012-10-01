#include <string.h>
#include <stdio.h>
#include <readline/readline.h>
 
int main() {
     char * test;
     test=readline("Prompt:");

     while(strcmp(test,"quit") != 0) {
         printf("%s\n",test);
         add_history(test);
         free(test);
         test=readline("Prompt:");
     }
     
     return 0;
}
