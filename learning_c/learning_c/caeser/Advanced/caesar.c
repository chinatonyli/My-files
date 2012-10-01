#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 80

int main(void) {
    char plain[MAX];
    char letter;
    int key;
    int index;

    printf("Please input your plain: ");
    fgets(plain, MAX, stdin);
    printf("Please input your key (included negatives): ");
    scanf("%i", &key);

    for (index = 0; index < strlen(plain); index++) {
        letter = plain[index];
        
        if (key > 0) {
            key += index;
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
            key -= index;
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
    fprintf(stderr, "\n");
}
