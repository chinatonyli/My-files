#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define INIT_SIZE 20

int main(void) {
    char *plain = (char *) malloc(sizeof(char) * INIT_SIZE);
    char letter;
    char ch;
    int key;
    int index;
    int size = INIT_SIZE;

    printf("Please input your plain: ");
    for (int i = 0; i < size; i++) {
        // 没内存了...
        if (i == size - 1) {
            plain = (char *) realloc(plain, size += INIT_SIZE);
        }
        // 用户输入字符，且不是回车
        if ((ch = getchar()) != '\n') {
            plain[i] = ch;
        }
        else {
            // 哦？用户按下了回车，写\0结束字符串
            plain[i] = '\0';
            break;
        }
    }
    
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
    free(plain);
    fprintf(stderr, "\n");
}
