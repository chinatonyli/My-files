#include <stdio.h>

int recursion(int depth);

int main(void) {
    recursion(0);
    return 0;
}

int recursion(int depth) {
    depth++;
    printf("%i\n", depth);
    recursion(depth);
    return 0;
}
