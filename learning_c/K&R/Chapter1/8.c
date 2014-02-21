#include <stdio.h>

/* 统计输入中的空格、制表符与换行符的个数 */
main()
{
    int c;
    int space, tab, newline;

    space = 0;
    tab = 0;
    newline = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++space;
        else if (c == '\t')
            ++tab;
        else if (c == '\n')
            ++newline;
    }
    printf("Spaces: %d\nTabs: %d\nNewline: %d\n", space, tab, newline);
}
