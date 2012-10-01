#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
  
char* lcs(const char *str1, const char *str2) {  
    int m = strlen(str1) + 1;  
    int n = strlen(str2) + 1;  
    int capacity = m * n * sizeof(int);  
    int *record = (int*) malloc(capacity);  
    int i, j;  
    memset(record, 0, capacity);  
    for (i = 1; i < n; ++i) {  
        for (j = 1; j < m; ++j) {  
            if (str1[j - 1] == str2[i - 1]) {  
                record[i * m + j] = record[(i - 1) * m + (j - 1)] + 1;  
            } else {  
                record[i * m + j] = 0;  
            }  
        }  
    }  
    int max = 0;  
    for (i = 1; i < m * n; ++i) {  
        if (record[i] > max) {  
            max = record[i];  
            j = i;  
        }  
    }  
    j = j % m - max;  
    char *ret = (char*) malloc(max + 1);  
    strncpy(ret, str1 + j, max);  
    ret[max] = 0;  
    free(record);  
    return ret;  
}  
  
/* 测试代码 */  
int main() {  
    const char *str1 = "abxyzcdefgh";  
    const char *str2 = "xyzcdefxyz";  
    char *ret = lcs(str1, str2);  
    printf(ret);
    printf("\n");  
    free(ret);  
    return 0;  
}
