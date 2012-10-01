#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define INIT_SIZE 2
#define LETTERS 26

char *getinput(int max) {
    int ch;
    char *string = NULL;

    string = (char *) malloc(sizeof(char) * INIT_SIZE);
    for (int i = 0; i < max; i++) {
        if (i == max - 1) {
            string = (char *) realloc(string, max += INIT_SIZE);
            if (string == NULL) {
                printf("Out of memory! Emergency stop!");
            }
        }
        if ((ch = getchar()) != EOF) {
            string[i] = ch;
        }
        else {
            string[i] = '\0';
            break;
        }
    }
    return string;
}

int cmp(const void *a, const void *b){
    return *(int*)a-*(int*)b;
}

int GetMode(int *array, int n)
{
    int i = 0;
    int j = 0;
    int elem = -1;
    int count = 1;
    int count1 = 1;
    int size = 0;
    int *a = NULL;
    
    for (i = 0; i < n; i++) {
        if (array[i] != 0) {
            a = realloc(a, size += sizeof(int));
            a[j] = array[i];
            j++;
        }
    }

    for (i = 0; i < j; ) {
        while (a[i] == a[i + 1]) {
            count++;
            i++;
        }
        if (count > count1) {
            count1 = count;
            elem = a[i];
        }
        count = 1;
        i++;
    }
    return elem;
}

int Sort(int arr[][2], int count) {
    int tmp1;
    int tmp2;
    int i = count, j;

    while (i > 0) {
        for (j = 0; j < i - 1; j++) {
            if (arr[j][1] < arr[j + 1][1]) {   
                tmp1 = arr[j][1];
                tmp2 = arr[j][0];
                arr[j][1] = arr[j + 1][1];
                arr[j][0] = arr[j + 1][0];
                arr[j + 1][1] = tmp1;
                arr[j + 1][0] = tmp2;
            }
        }
        i--;
    }
    return 0;
}


int main(void) {
    char *text;
    int alphabet[LETTERS][2] = {0};
    char freq[LETTERS] = {'e', 't', 'a', 'o', 'i', 'n', 's', 'h', \
        'r', 'd', 'l', 'c', 'u', 'm', 'w', 'f', 'g', \
        'y', 'p', 'b', 'v', 'k', 'j', 'x', 'q', 'z'};
    int offset;
    int offsets[LETTERS] = {0};
    char letter;
    int len;
    int c;

    printf("Input: ");
    text = getinput(INIT_SIZE);

    len = strlen(text);
    for (int i = 0; i < len; i++) {
        letter = text[i];

        if (isupper(letter)) {
            alphabet[letter - 'A'][0] = tolower(letter);
            alphabet[letter - 'A'][1] += 1;
        }
        else if (islower(letter)) {
            alphabet[letter - 'a'][0] = letter;
            alphabet[letter - 'a'][1] += 1;
        }
    }

    Sort(alphabet, LETTERS);

    for (int i = 0; i < LETTERS; i++) {
        if (alphabet[i][1] != 0) {
            //printf("%c - %i - Maybe: %c\n", alphabet[i][0], alphabet[i][1], freq[i]);
            offsets[i] = freq[i] - alphabet[i][0];
        }
    }

    qsort(offsets, LETTERS, sizeof(int), cmp);
    offset = GetMode(offsets, LETTERS);
    printf("Possible Offset %i\n\n", offset);

    printf("Do you want to print the decrypted messages [Yes/No]? ");
    if (getchar() == 'y') {
        for (int i = 0; i < len - 1; i++) {
            if (islower(text[i])) {
                if (offset < 0) {
                    printf("%c", (text[i] - 'z' + offset) % 26 + 'z');
                }
                else if (offset >= 0) {
                    printf("%c", (text[i] - 'a' + offset) % 26 + 'a');
                }
            }
            else if (isupper(text[i])) {
                if (offset < 0) {
                    printf("%c", (text[i] - 'Z' + offset) % 26 + 'Z');
                }
                else if (offset >= 0) {
                    printf("%c", (text[i] - 'A' + offset) % 26 + 'A');
                }
            }
            else {
                printf("%c", text[i]);
            }
        }
    }
    printf("\n");
    system("pause");
    return 0;
}
