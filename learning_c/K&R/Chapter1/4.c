#include <stdio.h>
/* 当 celsius = 0, 20, ……, 100 时，打印摄氏温度与华氏温度对照表；
 * 浮点数版本 */

main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;   /* 温度表的下限 */
    upper = 100; /* 温度表的上限 */
    step = 10;   /* 步长 */

    celsius = lower;
    while (celsius <= upper) {
        fahr = (9.0/5.0) * celsius + 32;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
