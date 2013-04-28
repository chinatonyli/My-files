#include <stdio.h>
#include <string.h>

void doublenum(char *number);

int main(void) {
    char number[] = {"0999"};
    
    doublenum(number);
    printf("%s\n", number);
    return 0;
}

void doublenum(char *number) {
    int digits; // 进位

    for (int i = strlen(number) - 1; i >= 0; i--) {
        number[i] -= '0';
        number[i] *= 2;
        if (number[i] >= 10) {
            digits = number[i] - 9;
            number[i] -= 10;
        }
        number[i] += digits;
        digits = 0;
        printf("Digits = %i, number[%i] = %i\n", digits, i, number[i]);
        number[i] += '0';
    }
}
