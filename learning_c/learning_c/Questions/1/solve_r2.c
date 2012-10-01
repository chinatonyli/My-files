#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROW 2

int column;

int cmp(const void *a, const void *b){
    return *(int*)a-*(int*)b;
}

int GetSameDigits(int (*data)[column]) {
    int digits = 0;
    for (int i = 0; i < ROW - 1; i++) {
        for (int j = 0; j < column; j++) {
            if (data[i][j] == data[i+1][j]) {
                digits++;
            }
        }
    }
    return digits;
}

int main(void) {
    int SameDigits;
    char ch;

    printf("输入数据个数: ");
    scanf("%i", &column);
    printf("\n");
    int data[ROW][column]; // 为了简化实现，选择了VLA，很多编译器不支持哦！
    memset(data, 0, sizeof(data));
    setbuf(stdin, NULL);

    for (int i = 0; i < ROW; i++) {
        printf("输入第%i组数据: ", i + 1);
        for (int j = 0; j < column; j++) {
            while (ch = getchar()) {
                if (ch == '\n' || ch == ' ') {
                    break;
                }
                data[i][j] = data[i][j] * 10 + (ch - '0');
            }
        }
    }
    
    for (int i = 0; i < ROW; i++) {
        qsort(data[i], column, sizeof(int), cmp);
    }

    SameDigits = GetSameDigits(data);
    printf("重复数字个数：%i\n", SameDigits);
    
    return 0;  
}
