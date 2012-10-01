#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define ROW 2
#define column 10

int cmp(const void *a,const void *b)
{
    int *c = (int *)a;
    int *d = (int *)b;
    if(*c != *d)
        return *c - *d;
    return *(d+1) - *(c+1);
}

int main()
{
    int i, j;
    int a[2][10]={{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, 
        {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}};
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < column; j++) {
            printf("%i ", a[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    qsort(a,ROW,sizeof(a[0]),cmp);
   
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < column; j++) {
            printf("%i ", a[i][j]);
        }
        printf("\n");
    }

    system("pause");
    return 0;
}
