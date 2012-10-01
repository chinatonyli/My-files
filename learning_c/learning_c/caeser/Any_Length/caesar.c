#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <assert.h>
#include <ctype.h>

int getch(void) {
    int c = 0;
    struct termios org_opts, new_opts;
    int res = 0;

    // Store old settings
    res=tcgetattr(STDIN_FILENO, &org_opts);
    // assert(res == 0);
    
    // Set new terminal parms
    memcpy(&new_opts, &org_opts, sizeof(new_opts));
    new_opts.c_lflag &= ~(ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
    c = getchar();
            
    // Restore old settings
    res = tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);
    // assert(res == 0);
    return c;
}

char *get_input() {
    char ch = '\0';
    char *str = "";
    long i = 0;
    int BufferSize = 10;

    while ((ch=getch()) != '\n') {
        if (!strlen(str) % BufferSize) {
            str = strcpy((char*)malloc(strlen(str) + BufferSize), str);
        }

        if (ch != 127) {
            str[i]=ch;
            str[++i]='\0';
        }

        else if (i > 0) {
             str[--i]='\0';
             putchar(8);
             putchar(8);
             putchar(32);
             putchar(32);
             putchar(32);
             putchar(8);
             putchar(8);
             putchar(8);
             putchar(8);
             putchar(32);
             putchar(8);
        }

        else {
            putchar(8);
            putchar(8);
            putchar(32);
            putchar(32);
            putchar(8);
            putchar(8);
        }

        setbuf(stdin, NULL);
    }
    return str;
}

int main(void) {
    char * plain;
    char letter;
    int key;
    int index;

    printf("Please input your plain: ");
    plain = get_input();
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
    fprintf(stderr, "\n");
}
