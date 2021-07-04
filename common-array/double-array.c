#include <stdlib.h>
#include <stdio.h>
#include "common-array.h"

arr_double *scanDoubleArr(int length) {
    arr_double *arrFloat = calloc(1, sizeof(arr_double));
    arrFloat->arr = calloc(length, sizeof(double));
    arrFloat->size = length;
    printf(">>> Start input array of floats:\n");
    char tempStr[256];

    for (int i = 0; i < length; ++i) {
        printf("- Enter element #%d:\n", i);
        scanf("%s", tempStr);
        arrFloat->arr[i] = strtof(tempStr, NULL);
    }
    printf("<<< End input array of floats.\n");
    return arrFloat;
}

void printDoubleArr(arr_double *arrDouble) {
    printf("[");
    for (int i = 0; i < arrDouble->size; ++i) {
        if (i == arrDouble->size - 1) {
            printf("%f", arrDouble->arr[i]);
        } else {
            printf("%f, ", arrDouble->arr[i]);
        }
    }
    printf("]");
}

void freeDoubleArr(arr_double *arrDouble) {
    free(arrDouble->arr);
    free(arrDouble);
}