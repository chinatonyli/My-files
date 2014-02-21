#include <stdio.h>
#include <ctype.h>

/* 输入若干个句子，以每行一个单词的形式打印其输出 */
main()
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            putchar('\n');
        else if (isalpha(c))
            putchar(c);
    }
    putchar('\n');
}
