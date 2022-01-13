#include <stdio.h>
#include <stdlib.h>
#include <common-array.h>

arr_char *scanCharArr(int length) {
    arr_char *arrChar = calloc(1, sizeof(arr_char));
    arrChar->arr = calloc(length, sizeof(char));
    arrChar->size = length;
    printf(">>> Start input array of characters:\n");
    char *tempStr = calloc(length, sizeof(char));
    for (int i = 0; i < length; ++i) {
        printf("- Enter element #%d:\n", i);
        scanf("%s", tempStr);
        arrChar->arr[i] = (char) strtol(tempStr, NULL, 10);
    }
    free(tempStr);
    printf("<<< End input array of characters.\n");
    return arrChar;
}

void printCharArr(arr_char *arrChar) {
    printf("[");
    for (int i = 0; i < arrChar->size; ++i) {
        if (i == arrChar->size - 1) {
            printf("%c", arrChar->arr[i]);
        } else {
            printf("%c, ", arrChar->arr[i]);
        }
    }
    printf("]");
}