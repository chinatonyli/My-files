/* 用N根长度相同的火柴，首尾顺次连接，摆成一个三角形。能摆成不同的三角形的个数为多少？
 * Author: Biergaizi
 * Copyright: GPL v3 or later. */

#include <stdio.h>
#include <math.h> // 求绝对值
#include <stdlib.h> // exit()函数需要它
#define MAX 30000 // 数组大小
#define ENDFLAG 0 // 表示数组结束（没有更多数字）的标志，由于数组从0开始，故为此值.


int swap(int *a, int *b) {
    /* 接受a, b的地址. 交换a, b的位置.
     * 用于进行冒泡排序。交换位置时采用了比较诡异的异或计算，请自行查阅资料以便理解. */

    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;

    return 0;
}

int sort(int *a, int *b, int *c) {
    /* 接受a, b, c的地址，然后进行冒泡排序. */
    
    while (!((*a <= *b) && (*b <= *c))) {
        if (*a > *b) {
            swap(&(*a), &(*b));
        }

        if (*b > *c) {
            swap(&(*b), &(*c));
        }
    }
    return 0;
}

_Bool Istriangle(int a, int b, int c) {
    /* 判断线段a, b, c是否可组成一个三角形. 返回布尔值.
     * 三角形的两边之和大于第三边，两边之差的绝对值小于第三边. */

    if (a + b > c && fabs(a-b) < c) {
        return 1;
    }
    else {
        return 0;
    }
}

int solve(int sum, int (*result)[2]) {
    /* 接受参数：总边数sum，要保存答案的二维数组result.
     * 由于三角形的第三条边总是可以由sum - a - b求出，所以没有必要保存. */

    int a;  // a, b, c 三条边
    int b;
    int c;
    int aa; // aa, bb, cc 是 a, b, c的副本
    int bb;
    int cc;
    int i; // 供循环用
    int counter = 0; // 计数器，每找到一组解加1，即解的个数
    _Bool same = 0; // flag，表示解是否相同

    for (a = 1, b = 1; (sum - a - b) > 0; a++) {
        for (c = 2; c > 1; b++) {
            c = sum - a - b;
            aa = a; // 使用a, b, c值的拷贝，使其不影响for循环判断
            bb = b; // TODO: 使用指针
            cc = c;

            // 判断组合是否存在
            sort(&aa, &bb, &cc); // 先排序. TODO: 排序指针
            for (i = 0; result[i][0] != ENDFLAG; i++) {
                if (result[i][0] == aa && result[i][1] == bb) {
                    same = 1;
                    break;
                }
            }
            
            // 如果组合不存在......
            if (!same && Istriangle(aa, bb, (sum - aa - bb))) {
                // 如果超过了数组大小
                if (counter == MAX && result[counter][0] != ENDFLAG) {
                    printf("Number is too big, unable to solve!\n");
                    exit(1);
                }
            
                //将枚举到得a, b存入数组的空闲位
                result[i][0] = aa;
                result[i][1] = bb;
                counter++;
            }
            // 重置flag
            same = 0;
        }
        // 重置b的值
        b = 1;
    }
    return counter;
}

int main(void) {
    int lines; // 总边数
    int solution[MAX][2]; // 保存解之二维数组
    int i; // 供循环用
    
    printf("How many lines do you have: ");
    scanf("%i", &lines);
    printf("\nYou can build %i triangle(s): \n", solve(lines, solution));

    for (i = 0; solution[i][0] != 0; i++) {
        printf("%i, %i, %i\n", solution[i][0], solution[i][1], (lines-solution[i][1]-solution[i][0]));
    }
    return 0;
}
