#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 42

short cardLuhnChecksumIsValid (const char * card_number) {
    short sum = 0;
    short num_digits = strlen(card_number) - 1;
    short oddeven = num_digits & 1;
    short digit;
    for (short count = 0; count < num_digits; count++) {
        digit = card_number[count] - '0';

        if (!((count & 1) ^ oddeven)) {
            digit = digit * 2;
        }
        if (digit > 9) {
            digit = digit - 9;
        }
        sum = sum + digit;
    }
    return (sum % 10) == 0 && sum != 0;
}

int main (void) {
    char card_number[MAX];
    char * success;
    printf("Please input the number of your credit card: ");
    success = fgets(card_number, MAX, stdin);

    if (cardLuhnChecksumIsValid(card_number) == 1 && success != NULL) {
        printf("Your card number is vaild!\n");
    }
    else {
        printf("Sorry, invaild card number!\n");
    }
    return 0;
}
