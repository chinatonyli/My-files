#include <stdio.h>
#include <math.h>
#define MAX 10000
int history[MAX];


int swap(int *a, int *b) {
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;

    return 0;
}

int sort(int *a, int *b, int *c) {
    while (!((*a <= *b) && (*b <= *c))) {
        if (*a > *b) {
            swap(&(*a), &(*b));
        }

        if (*b > *c) {
            swap(&(*b), &(*c));
        }
    }
    return 0;
}

int len(int * array, int max) {
    for (int i = 0; i <= max; i++) {
        if (array[i] == 0) {
            return i;
        }
    }
    return -1;
}

_Bool IsSame(int a, int b, int c) {
    int i;
    int j;

    sort(&a, &b, &c);

    for (i = 0; i < len(history, MAX); i++) {
        if (history[i] == a && history[i+1] == b && history[i+2] == c) {
            return 1;
        }
        else {
            continue;
        }
    }
    
    j = len(history, MAX);
    history[j] = a;
    history[j+1] = b;
    history[j+2] = c;

    return 0;
}

int generate(int sum, int (* result)[3]) {
    int a;
    int b = 1;
    int c;
    int counter = -1;
    
    for (a = 1; (sum - a - b) > 0; a++) {
        for (c = 2; c > 1; b++) {
            c = sum - a - b;
            if (!(IsSame(a, b, c))) {
                counter++;
                result[counter][0] = a;
                result[counter][1] = b;
                result[counter][2] = c;
            }
        }
        b = 1;
    }
    return 0;
}

_Bool Istriangle(int a, int b, int c) {
    if (fabs(a) + fabs(b) > c && fabs(a) - fabs(b) < c) {
        return 1;
    }
    else {
        return 0;
    }
}

int solve(int lines, int (* answer)[3]) {
    int result[MAX][3];
    int counter = 0;

    generate(lines, result);
    
    for (int j = 0; j < len(history, MAX); j++) {
        if (Istriangle(result[j][0] ,result[j][1], result[j][2])) {
            answer[counter][0] = result[j][0];
            answer[counter][1] = result[j][1];
            answer[counter][2] = result[j][2];
            counter++;
        }
    }
    return counter;
}

int main(void) {
    int lines;
    int answer[MAX][3];
    
    printf("How many lines do you have: ");
    scanf("%i", &lines);
    printf("\nYou can build %i triangle(s): \n", solve(lines, answer));

    for (int i = 0; answer[i][0] != 0; i++) {
        printf("%i, %i, %i\n", answer[i][0], answer[i][1], answer[i][2]);
    }
    return 0;
}
