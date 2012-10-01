#include <stdio.h>
#define PEOPLE 13
#define GROUP 3
#define TIMES (PEOPLE % GROUP)

int main(void) {
    int people[PEOPLE] = {1};

    for (int i = 0; i < TIMES; i++) {
        for (int j = GROUP; i < PEOPLE; j += GROUP) {
            people[GROUP] = 0;
        }
    }

    for (int i = 0; i < PEOPLE; i++) {
        if (i == 1) {
            printf("The traitor's number is %i!", i + 1);
        }
    }
}
