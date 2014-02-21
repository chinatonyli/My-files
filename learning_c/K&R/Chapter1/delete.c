#include <stdio.h>
#include <stdlib.h>


#define NORMAL 0
#define STRCON 1
#define STRING 2
#define MAY_ENTER 3
#define MAY_EXIT 4
#define COMMENT 5


inline void ERROR(void)
{
    printf("Error!\n");
    exit(1);
}


int main(void)
{
    unsigned int state = NORMAL;
    char c;

    while ((c = getchar()) != EOF) {

        switch (c) {
            case '\'':
                if (state == NORMAL)
                    state = STRCON;
                else if (state == STRCON)
                    state = NORMAL;
                else
                    ERROR();
                break;
            case '"':
                if (state == NORMAL)
                    state = STRING;
                else if (state == STRING)
                    state = NORMAL;
                else
                    ERROR();
                break;
            case '/':
                if (state == NORMAL) {
                    state = MAY_ENTER;
                }
                else if (state == MAY_EXIT) {
                    state = NORMAL;
                    continue;
                }
                else
                    ERROR();
                break;
            case '*':
                if (state == MAY_ENTER)
                    state = COMMENT;
                else if (state == COMMENT)
                    state = MAY_EXIT;
                else
                    ERROR();
                break;
            default:
                break;
        }

        if ((state == NORMAL) || (state == STRCON) || (state == STRING)) {
            printf("State: %d ", state);
            putchar(c);
            putchar('\n');
        }

    }
}
