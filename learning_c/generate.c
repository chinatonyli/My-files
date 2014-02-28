#include <stdio.h>
#define MAX 10000
int history[MAX];

int generate(int sum) {
    int a;
    int b;
    int c;

    for (a = 1, b = 1; (sum - a - b) > 0; a++) {
        for (c = 2; c > 1; b++) {
            c = sum - a - b;
            printf("a=%i, b=%i, c=%i\n", a, b, c);
        }
        b = 1;
    }
    return 0;
}

int main(void) {
    generate(5);
    return 0;
}
