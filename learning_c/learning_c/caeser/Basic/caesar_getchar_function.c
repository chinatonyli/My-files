#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define INIT_SIZE 2

char *getinput(int max) {
    int ch;
    char *string = NULL;

    string = (char *) malloc(sizeof(char) * INIT_SIZE);
    for (int i = 0; i < max; i++) {
        if (i == max - 1) {
            string = (char *) realloc(string, max += INIT_SIZE);
            if (string == NULL) {
                printf("Out of memory! Emergency stop!");
            }
        }
        if ((ch = getchar()) != EOF) {
            string[i] = ch;
        }
        else {
            string[i] = '\0';
            break;
        }
    }
    return string;
}

int main(void) {
    char *plain = NULL;
    char letter;
    int key;
    int index;

    printf("Please input your plain: ");
    plain = getinput(INIT_SIZE);

    printf("Please input your key (included negatives): ");
    scanf("%i", &key);

    for (index = 0; index < strlen(plain); index++) {
        letter = plain[index];
        
        if (key > 0) {
            if (isupper(letter)) {
                fprintf(stderr, "%c", (letter - 'A' + key) % 26 + 'A');
            }

            else if (islower(letter)) {
                fprintf(stderr, "%c", (letter - 'a' + key) % 26 + 'a');
            }
            else {
                fprintf(stderr, "%c", letter);
            }
        }
        else if (key <= 0) {
            if (isupper(letter)) {
                fprintf(stderr, "%c", (letter - 'Z' + key) % 26 + 'Z');
            }

            else if (islower(letter)) {
                fprintf(stderr, "%c", (letter - 'z' + key) % 26 + 'z');
            }

            else {
                fprintf(stderr, "%c", letter);
            }
        }
    }
    free(plain);
    fprintf(stderr, "\n");
}
