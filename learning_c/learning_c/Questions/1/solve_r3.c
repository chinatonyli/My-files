#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROW 2
#define SEPARATOR ' '
#define MAX( x, y ) ( ((x) > (y)) ? (x) : (y) )

int column;

int GetLcsLen(int *s1, int *s2, int len1, int len2) {
    int array[len1+1][len2+1]; // 临时矩阵，加上1是为了保证在第一次循环时不会越界
    memset(array, 0, sizeof(array)); // VLA分配的内存是随机值，我们需要清空掉

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i-1] == s2[j-1]) {
                // 這裡加上的 1 是指 e1 的長度為 1
                array[i][j] = array[i-1][j-1] + 1;
            }
            else {
                array[i][j] = MAX(array[i-1][j], array[i][j-1]);
            }
        }
    }
    return array[len1][len2];
}

int main(void) {
    int Lcs_Len;
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
            while (ch = getchar(), ch != '\n' && ch != SEPARATOR) {
                data[i][j] = data[i][j] * 10 + (ch - '0');
            }
        }
    }
    
    Lcs_Len = GetLcsLen(data[0], data[1], column, column);
    printf("LCS长度：%i\n", Lcs_Len);
    
    return 0;  
}
