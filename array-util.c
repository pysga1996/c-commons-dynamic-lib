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

arr_double scanDoubleArr(int length) {
    arr_double arrFloat = {calloc(length, sizeof(float)), length };
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

void printDoubleArr(arr_double arrFloat) {
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

void freeDoubleArr(arr_double arrFloat) {
    free(arrFloat.arr);
}

arr_string scanStringArr(int length) {
    arr_string arrString = {calloc(length, sizeof(char*)), length };
    printf(">>> Start input array of floats:\n");
    char tempStr[512];
    for (int i = 0; i < length; ++i) {
        printf("- Enter element #%d:\n", i);
        scanf("%s", tempStr);
        arrString.arr[i] = tempStr;
    }
    printf("<<< End input array of floats.\n");
    return arrString;
}

void printStringArr(arr_string arrString) {
    printf("[");
    for (int i = 0; i < arrString.size; ++i) {
        if (i == arrString.size - 1) {
            printf("%s", arrString.arr[i]);
        } else {
            printf("%s, ", arrString.arr[i]);
        }
    }
    printf("]");
}

void freeStringArr(arr_string arrString) {
    for (int i = 0; i < arrString.size; ++i) {
        free(arrString.arr[i]);
    }
    free(arrString.arr);
}


