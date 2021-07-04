#include <stdlib.h>
#include <stdio.h>
#include "common-array.h"

arr_long *scanLongArr(int length) {
    arr_long *arrLong = calloc(1, sizeof(arr_long));
    arrLong->arr = calloc(length, sizeof(long long));
    arrLong->size = length;
    printf(">>> Start input array of longs:\n");
    char tempStr[256];
    for (int i = 0; i < length; ++i) {
        printf("- Enter element #%d:\n", i);
        scanf("%s", tempStr);
        arrLong->arr[i] = strtoll(tempStr, NULL, 10);
    }
    printf("<<< End input array of longs.\n");
    return arrLong;
}

void printLongArr(arr_long *arrLong) {
    printf("[");
    for (int i = 0; i < arrLong->size; ++i) {
        if (i == arrLong->size - 1) {
            printf("%lld", arrLong->arr[i]);
        } else {
            printf("%lld, ", arrLong->arr[i]);
        }
    }
    printf("]");
}

void freeLongArr(arr_long *arrLong) {
    free(arrLong->arr);
    free(arrLong);
}