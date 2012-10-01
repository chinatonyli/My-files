#include <stdio.h>
#include <string.h>
#define MAX 99902

int main(void) {
    char plain[MAX];
    char letter;
    int value;
    int index;

    printf("Please input your plain text: ");
    fgets(plain, MAX, stdin);
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
}
