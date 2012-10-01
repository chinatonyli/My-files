#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROW 2
#define COLUMN 10

int main(void) {
    int SameDigits;
    char chr;
    int dna[ROW][COLUMN];
    memset(dna, 0, sizeof(dna));
    setbuf(stdin, NULL);
    
    for (int i = 0; i < ROW; i++) {
        printf("输入第%i组数据: ", i+1);
        for (int j = 0; j < COLUMN; j++) {
            while (chr = getchar()) {
                if (chr == '\n' || chr == ' ') {
                    break;
                }
                printf("%c", chr);
            }
        }
    }
}
