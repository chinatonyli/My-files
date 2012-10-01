#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROW 2

int column;

int cmp(const void *a, const void *b){
    return *(int*)a-*(int*)b;
}

int GetSameDigits(int (*dna)[column]) {
    int digits = 0;
    for (int i = 0; i < ROW - 1; i++) {
        for (int j = 0; j < column; j++) {
            if (dna[i][j] == dna[i+1][j]) {
                digits++;
            }
        }
    }
    return digits;
}

int main(void) {
    int SameDigits;
    char ch;

    scanf("%i", &column);
    int dna[ROW][column]; // 为了简化实现，选择了VLA，很多编译器不支持哦！
    memset(dna, 0, sizeof(dna));
    setbuf(stdin, NULL);

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < column; j++) {
            while (ch = getchar()) {
                if (ch == '\n' || ch == ' ') {
                    break;
                }
                dna[i][j] = dna[i][j] * 10 + (ch - '0');
            }
        }
    }
    
    for (int i = 0; i < ROW; i++) {
        qsort(dna[i], column, sizeof(int), cmp);
    }

    SameDigits = GetSameDigits(dna);
    printf("%i\n", SameDigits);
    
    return 0;  
}
