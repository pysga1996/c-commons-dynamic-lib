#include <stdlib.h>
#include <stdio.h>
#include "common-functions.h"

arr_int scanIntArr(int length) {
    arr_int arrInt = { calloc(length, sizeof(int)), length };
    printf(">>> Start input array of integers:\n");
    char tempStr[256];

    for (int i = 0; i < length; ++i) {
        printf("- Enter element #%d:\n", i);
        scanf("%s", tempStr);
        arrInt.arr[i] = (int) strtol(tempStr, NULL, 10);
    }
    printf("<<< End input array of integers.\n");
    return arrInt;
}

void printIntArr(arr_int arrInt) {
    printf("[");
    for (int i = 0; i < arrInt.size; ++i) {
        if (i == arrInt.size - 1) {
            printf("%d", arrInt.arr[i]);
        } else {
            printf("%d, ", arrInt.arr[i]);
        }
    }
    printf("]");
}

void freeIntArr(arr_int arrInt) {
    free(arrInt.arr);
}

arr_float scanFloatArr(int length) {
    arr_float arrFloat = {calloc(length, sizeof(float)), length };
    printf(">>> Start input array of floats:\n");
    char tempStr[256];

    for (int i = 0; i < length; ++i) {
        printf("- Enter element #%d:\n", i);
        scanf("%s", tempStr);
        arrFloat.arr[i] = strtof(tempStr, NULL);
    }
    printf("<<< End input array of floats.\n");
    return arrFloat;
}

void printFloatArr(arr_float arrFloat) {
    printf("[");
    for (int i = 0; i < arrFloat.size; ++i) {
        if (i == arrFloat.size - 1) {
            printf("%f", arrFloat.arr[i]);
        } else {
            printf("%f, ", arrFloat.arr[i]);
        }
    }
    printf("]");
}

void freeFloatArr(arr_float arrFloat) {
    free(arrFloat.arr);
}

