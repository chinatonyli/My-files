#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>

int main(void) {
    char * plain;
    char letter;
    int value;
    int index;

    plain = readline("Please input your plain text: ");
    printf("Please input your key (included negatives): ");
    scanf("%i", &value);

    for (index = 0; index < strlen(plain); index++) {
        letter = plain[index];

        if (letter >= 'A' && letter <= 'Z') {
            fprintf(stderr, "%c", (letter - 'A' + value) % 26 + 'A');
        }
                
        else if (letter >= 'a' && letter <= 'z') {
            fprintf(stderr, "%c", (letter - 'a' + value) % 26 + 'a');
        }
        else {
            fprintf(stderr, "%c", letter);
        }
    }
    fprintf(stderr, "\n");
    free(plain);
}
