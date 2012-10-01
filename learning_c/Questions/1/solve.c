#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROW 2

int column;

int cmp(const void *a, const void *b) {
    return strcmp((char *)a,(char *)b);
}

int GetSameDigits(char (*dna)[column]) {
    int digits;
    
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < column; j++) {
            if (dna[i][j] == ' ') {
                continue;
            }
            if (dna[i][j] == dna[i+1][j]) {
                digits++;
            }
        }
    }
    return digits;
}

int main(void) {
    int SameDigits;
    char chr;

    printf("输入数据个数: ");
    scanf("%i", &column);
    printf("\n");
    column += column - 1; // 为每个数字中间的空格计算空间
    char dna[ROW][column]; // 为了简化实现，选择了有些隐晦的VLA，很多编译器不支持哦！

    
    for (int i = 0; i < ROW; i++) {
        setbuf(stdin, NULL);
        printf("输入第%i组数据: ", i+1);
        for (int j = 0; j < column; j++) {
            chr = getchar();
            if (chr != ' ') {
                dna[i][j] = ch;
            }
        }
        getchar();
    }

    qsort(dna, 2, 1*sizeof(char),cmp);
    SameDigits = GetSameDigits(dna);
    printf("重复数字个数：%i", SameDigits);
    
    return 0;  
}
