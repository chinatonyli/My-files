#include <stdio.h>
#include <string.h>

int main(void) {
    char letter;
    int value = 2;

    printf("Please input your plain text: ");

    while ((letter = getchar()) != '\n') {
        if (letter >= 'A' && letter <= 'Z') {
            printf("%c", (letter - 'A' + value) % 26 + 'A');
        }
        else if (letter >= 'a' && letter <= 'z') {
            printf("%c", (letter - 'a' + value) % 26 + 'a');
        }
        else {
            printf("%c", (letter));
        }
    }
    printf("\n");
}
