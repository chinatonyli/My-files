#include <stdio.h>
#define MAX 10

int a[MAX] = {1, 1, 2, 3, 4, 5, 6, 7, 8};
int b[MAX] = {1, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int swap(int *a, int *b) {
    int tmp;

    tmp = *b;
    *b = *a;
    *a = tmp;
    return 0;
}

int move(int *a, int offset) {
    return 0;
}

int main(void) {
    swap(&a[0], &a[9]);
    printf("%i %i\n", a[0], a[8]);
    return 0;
}

