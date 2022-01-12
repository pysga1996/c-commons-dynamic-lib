#include <stdlib.h>
#include <stdio.h>
#include "common-matrix.h"

matrix_long *scanLongMatrix(int numberOfRows, int numberOfColumns) {
    matrix_long *matrixLong = calloc(1, sizeof(matrix_long));
    matrixLong->arr = calloc(numberOfRows, sizeof(arr_long));
    matrixLong->size = numberOfRows;
    printf(">>> Start input matrix of longs:\n");
    for (int i = 0; i < numberOfRows; ++i) {
        printf("- Start enter row #%d:\n", i);
        matrixLong->arr[i] = *scanLongArr(numberOfColumns);
        printf("- Finish enter row #%d:\n", i);
    }
    printf("<<< End input matrix of longs.\n");
    return matrixLong;
}

void printLongMatrix(matrix_long *matrixLong) {
    printf("[");
    for (int i = 0; i < matrixLong->size; ++i) {
        printLongArr(&matrixLong->arr[i]);
        if (i < matrixLong->size - 1) {
            printf(",\n");
        }
    }
    printf("]");
}

void freeLongMatrix(matrix_long *matrixLong) {
    for (int i = 0; i < matrixLong->size; ++i) {
        free(matrixLong->arr[i].arr);
    }
    free(matrixLong->arr);
    free(matrixLong);
}