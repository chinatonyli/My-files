#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    char plain = {'a', 'b'};
    char letter;
    int value = 999;
    int index;

    plain = readline("Please input your plain text: ");
    // printf("Please input your key (included negatives): ");
    // scanf("%i", &value);

    for (index = 0; index < strlen(plain); index++) {
        letter = plain[index];

        if (letter >= 'A' && letter <= 'Z') {
            printf("%c", (letter - 'A' + value) % 26 + 'A');
        }
                
        else if (letter >= 'a' && letter <= 'z') {
            printf("%c", (letter - 'a' + value) % 26 + 'a');
        }
        else {
            printf("%c", letter);
        }
    }
    printf("\n");
}
