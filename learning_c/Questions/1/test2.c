#include <stdio.h>
int main(void) {
    char a[2][2] = {"aa", "bb"};
    char b[2][2] = {"aa", "bb"};

    printf("%i\n", a[1][1]==b[1][1]);
}
