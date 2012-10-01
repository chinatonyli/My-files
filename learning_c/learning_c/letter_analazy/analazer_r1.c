#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 80
#define LETTERS 26

int main(void) {
    char text[MAX];
    int alphabet[LETTERS] = {0};
    char letter;
    int len;

    printf("Input: ");
    fgets(text, MAX, stdin);

    len = strlen(text);
    for (int i = 0; i < len; i++) {
        letter = text[i];

        if (isupper(letter)) {
            alphabet[letter - 'A'] += 1;
        }
        else if (islower(letter)) {
            alphabet[letter - 'a'] += 1;
        }
    }

    for (int i; i < LETTERS; i++) {
        if (alphabet[i] != 0) {
            printf("%c - %i\n", i + 'a', alphabet[i]);
        }
    }
    return 0;
}
