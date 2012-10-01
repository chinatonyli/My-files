#include <stdio.h>
#define LIMIT 30000
#define ENDFLAG 0
#define MAX(x, y) ( (x) > (y) ? (x) : (y))

int solve(int sum, int (*result)[2]) {
    /* 接受总边数，和一个用于保存答案的数组，返回解的个数.
     * 在解决这个问题时，我们始终假设a <= m - a - b <= b */

    int a = 0;
    int b = 0;
    int half = (sum + sum % 2) / 2; // 三条边长度的一半，遇到余数则进一
    int counter = 0; // 计数器，记录解的个数
    
    // a, b边均不能超过三条边的一半
    for (a = 1; a < half; a++) {
        // b的初始值就是MAX(a, m / 2 - a)
        for (b = MAX(a, sum / 2 - a); b < half; b++) {
            // 验证 b >= c && a <= b，我们作出的假设
            if ((b * 2 >= sum - a) && (a * 2 <= sum - b)) {
                result[counter][0] = a;
                result[counter][1] = b;
                // printf("%i, %i, %i\n", a, b, (sum - a - b));
                counter++;
            }
        }
    }
    return counter;
}

int main(void) {
    int lines;
    int solution[LIMIT][2];
    int i;
    
    printf("How many lines do you have: ");
    scanf("%i", &lines);
    printf("\nYou can build %i triangle(s): \n", solve(lines, solution));
    
    for (i = 0; solution[i][0] != ENDFLAG; i++) {
        printf("%i, %i, %i\n", solution[i][0], solution[i][1], (lines-solution[i][1]-solution[i][0]));
    }
    return 0;
}
