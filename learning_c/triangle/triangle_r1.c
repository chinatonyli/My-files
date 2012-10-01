#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 30000
#define ENDFLAG 0


int swap(int *a, int *b) {
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;

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

int generate(int sum, int (*result)[3]) {
    // a, b, c ������
    int a;
    int b;
    int c;

    // aa, bb, cc �� a, b, c�ĸ���
    int aa;
    int bb;
    int cc;

    int i;
    int j;

    // �Ƿ���ͬ
    int same = 0;

    for (a = 1, b = 1; (sum - a - b) > 0; a++) {
        for (c = 2; c > 1; b++) {
            c = sum - a - b;

            aa = a;
            bb = b;
            cc = c;

            // �������Ѿ����ˣ���same��־��Ϊ1��
            sort(&aa, &bb, &cc);
            for (i = 0; result[i][0] != ENDFLAG; i++) {
                if (result[i][0] == aa && result[i][1] == bb && result[i][2] == cc) {
                    same = 1;
                    break;
                }
            }

            // �����ϲ���ͬ......
            if (!same) {
                //��ȡ������Ŀ���λ
                for (j = 0; j < MAX; j++) {
                    if (result[j][0] == 0) {
                        break;
                    }
                }
                
                if (j == MAX && result[j][0] != ENDFLAG) {
                    printf("Number is too big, unable to solve!\n");
                    exit(1);
                }

                //��ö�ٵ���a, b, c��������Ŀ���λ
                result[j][0] = aa;
                result[j][1] = bb;
                result[j][2] = cc;
            }
            // �������
            same = 0;
        }
        // ����b��ֵ
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

int solve(int lines, int (*answer)[3]) {
    int result[MAX][3];
    int counter = 0;

    generate(lines, result);
    
    for (int j = 0; result[j][0] != ENDFLAG; j++) {
        if (Istriangle(result[j][0], result[j][1], result[j][2])) {
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
