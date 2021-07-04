#include <stdlib.h>
#include <stdio.h>
#include "common-array.h"

arr_string *scanStringArr(int length) {
    arr_string *arrString = calloc(1, sizeof(arr_string));
    arrString->arr = calloc(length, sizeof(char *));
    arrString->size = length;
    printf(">>> Start input array of strings:\n");
    for (int i = 0; i < length; ++i) {
        (arrString->arr)[i] = calloc(sizeof(char), 512);
        printf("- Enter element #%d:\n", i);
        scanf("%s", (arrString->arr)[i]);
    }
    printf("<<< End input array of strings.\n");
    return arrString;
}

void printStringArr(arr_string *arrString) {
    printf("[");
    for (int i = 0; i < arrString->size; ++i) {
        if (i == arrString->size - 1) {
            printf("%s", arrString->arr[i]);
        } else {
            printf("%s, ", arrString->arr[i]);
        }
    }
    printf("]");
}

void freeStringArr(arr_string *arrString) {
    for (int i = 0; i < arrString->size; ++i) {
        free(arrString->arr[i]);
    }
    free(arrString->arr);
}