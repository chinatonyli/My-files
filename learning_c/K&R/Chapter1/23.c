#include <stdio.h>
#include <stdlib.h>

#define OUT 0
#define IN 1

/* 删除C程序中所有的注释，字符串和字面常量可以得到正确处理 */
main()
{
    int c;
    int status = OUT;
    int quote = OUT;
    int star = 0;
    int splash = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\'' || c == '"') {
            quote = !quote;
            putchar(c);
            continue;
        }
        
        if (quote) {
            putchar(c);
            continue;
        }

        if (splash == 1 && c == '/') {
            --splash;
            continue;
        }
        else if (splash == 0 && c == '/') {
            ++splash;
            continue;
        }

        if (star == 1 && c == '*')
            --star;
        else if (splash == 1 && c == '*')
            ++star;

        if (splash && star)
            status = IN;
        if ((splash || star) == 0)
            status = OUT;

        if (status == OUT)
            putchar(c);
    }
}
