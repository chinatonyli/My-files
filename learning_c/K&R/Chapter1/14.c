#include <stdio.h>
#define CHARS 128 /* ASCII 共有 128 个字符 */

/* 打印输入中所有字符的直方图 */
main()
{
    int c;
    int characters[CHARS] = {0};
    int characters_sum = 0;
    int percent;

    int i;
    int j;

    while ((c = getchar()) != EOF) {
        characters[c]++;
        characters_sum++;
    }

    for (i = 0; i < CHARS; i++) {
        if (characters[i] != 0) {
            percent = ((double) characters[i] / (double) characters_sum) * 100;
            printf("\n%c: %2d%% ", (i+32), percent);
            for (j = 0; j < percent; j++) {
                putchar('*');
            }
        }
    }
    putchar('\n');
}
