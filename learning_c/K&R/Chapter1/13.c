#include <stdio.h>
#define MAX 10

/* 打印输入中单词长度的直方图 */
main()
{
    int c;
    int word = -1;
    int length = 0;
    int lengths[MAX] = {0};
    int lengths_total = 0;
    int percent;
    
    int i;
    int j;

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\t' && c != '\n')
            length++;
        else {
            word++;
            lengths[word] = length;
            length = 0;
        }
    }

    for (i = 0; i < MAX; i++) {
        lengths_total = lengths_total + lengths[i];
    }
    
    for (i = 0; i < MAX; i++) {
        percent = ((float) lengths[i] / (float) lengths_total) * 100;
        printf("Word %i: %d%% ", i+1, percent);
        for (j = 0; j < percent; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
}
