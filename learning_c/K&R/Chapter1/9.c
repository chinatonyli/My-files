#include <stdio.h>

/* 将输入复制到输出，多个连续空格用一个空格代替 */
main()
{
    int c;
    int space = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            space++;
        else
            space = 0;

        if (space > 1) {
            continue;
        }

        putchar(c);
    }
}
