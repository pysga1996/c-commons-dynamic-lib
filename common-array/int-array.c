#include <stdlib.h>
#include <stdio.h>
#include "common-array.h"

arr_int *scanIntArr(int length) {
    arr_int *arrInt = calloc(1, sizeof(arr_int));
    arrInt->arr = calloc(length, sizeof(int));
    arrInt->size = length;
    printf(">>> Start input array of integers:\n");
    char tempStr[256];
    for (int i = 0; i < length; ++i) {
        printf("- Enter element #%d:\n", i);
        scanf("%s", tempStr);
        arrInt->arr[i] = (int) strtol(tempStr, NULL, 10);
    }
    printf("<<< End input array of integers.\n");
    return arrInt;
}

void printIntArr(arr_int *arrInt) {
    printf("[");
    for (int i = 0; i < arrInt->size; ++i) {
        if (i == arrInt->size - 1) {
            printf("%d", arrInt->arr[i]);
        } else {
            printf("%d, ", arrInt->arr[i]);
        }
    }
    printf("]");
}

void freeIntArr(arr_int *arrInt) {
    free(arrInt->arr);
    free(arrInt);
}