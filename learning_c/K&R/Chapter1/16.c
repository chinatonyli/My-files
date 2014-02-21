#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);

/* 打印任意长度的输入行 */
main()
{
    char line[MAXLINE];

    while (getline(line, MAXLINE) > 0)
        printf("%s", line);
}

int getline(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
