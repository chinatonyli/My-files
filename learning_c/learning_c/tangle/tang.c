#include <stdio.h>
#define LIMIT 30000
#define ENDFLAG 0
#define MAX(x, y) ( (x) > (y) ? (x) : (y))

int solve(int sum, int (*result)[2]) {
    /* �����ܱ�������һ�����ڱ���𰸵����飬���ؽ�ĸ���.
     * �ڽ���������ʱ������ʼ�ռ���a <= m - a - b <= b */

    int a = 0;
    int b = 0;
    int half = (sum + sum % 2) / 2; // �����߳��ȵ�һ�룬�����������һ
    int counter = 0; // ����������¼��ĸ���
    
    // a, b�߾����ܳ��������ߵ�һ��
    for (a = 1; a < half; a++) {
        // b�ĳ�ʼֵ����MAX(a, m / 2 - a)
        for (b = MAX(a, sum / 2 - a); b < half; b++) {
            // ��֤ b >= c && a <= b�����������ļ���
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
