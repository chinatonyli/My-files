#include <stdio.h>
#include <string.h>
#define LEN_S1 5
#define LEN_S2 5
#define MAX( x, y ) ( ((x) > (y)) ? (x) : (y) )

int lcs(int *s1, int *s2, int len1, int len2) {
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
    int s1[LEN_S1] = {1, 1, 2, 2, 3};
    int s2[LEN_S2] = {1, 1, 3, 2, 3};

    printf("LCS 的長度是%i.\n", lcs(s1, s2, LEN_S1, LEN_S2));
    return 0;
}
