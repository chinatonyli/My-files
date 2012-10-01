#include <stdio.h>
#include <math.h>

int Istriangle(int a, int b, int c) {
    if (fabs(a) + fabs(b) > c && fabs(a) - fabs(b) < c) {
        return 1;
    }
    else {
        return 0;
    }
}
int main(void) {
    int a;
    int b;
    int c;
    
    printf("Please input three lines of the triangle: ");
    scanf("%i, %i, %i", &a, &b, &c);
   
    if (Istriangle(a, b, c)) {
        printf("It is a vaild triangle.\n");
    }
    else {
        printf("It is an invaild triangle!\n");
    }
    return 0;
}
