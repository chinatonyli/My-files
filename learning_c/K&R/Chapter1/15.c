#include <stdio.h>

float fahr2celsius(float fahr);

/* 当 fahr = 0, 20, ……, 300 时，分别打印华氏温度与摄氏温度对照表；
 * 浮点数版本 */
main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;   /* 温度表的下限 */
    upper = 300; /* 温度表的上限 */
    step = 20;   /* 步长 */

    fahr = lower;
    while (fahr <= upper) {
        celsius = fahr2celsius(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}

float fahr2celsius(float fahr)
{
    return (5.0/9.0) * (fahr - 32.0);
}
