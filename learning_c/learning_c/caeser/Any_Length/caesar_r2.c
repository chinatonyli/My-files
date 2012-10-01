#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>

static struct termios old, new;

/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  new = old; /* make new settings same as old settings */
  new.c_lflag &= ~ICANON; /* disable buffered i/o */
  new.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
  tcsetattr(0, TCSANOW, &new); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
//char getch(void) 
//{
//  return getch_(0);
//}

/* Read 1 character with echo */
char getche(void) 
{
  return getch_(1);
}

char *get_input() {
    char ch = '\0';
    char *str = "";
    long i = 0;
    int BufferSize = 10;

    while ((ch=getche()) != '\n') {
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
             putchar(8);
        }

        else {
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
