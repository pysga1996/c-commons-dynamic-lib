#include <stdlib.h>
#include <stdio.h>
#include "common-matrix.h"

matrix_double* scanDoubleMatrix(int numberOfRows, int numberOfColumns) {
    matrix_double* matrixDouble = calloc(1, sizeof(matrix_double));
    matrixDouble->arr = calloc(numberOfRows, sizeof(arr_double));
    matrixDouble->size = numberOfRows;
    printf(">>> Start input matrix of doubles:\n");

    for (int i = 0; i < numberOfRows; ++i) {
        printf("- Start enter row #%d:\n", i);
        matrixDouble->arr[i] = *scanDoubleArr(numberOfColumns);
        printf("- Finish enter row #%d:\n", i);
    }
    printf("<<< End input matrix of doubles.\n");
    return matrixDouble;
}

void printDoubleMatrix(matrix_double* matrixDouble) {
    printf("[");
    for (int i = 0; i < matrixDouble->size; ++i) {
        printDoubleArr(&matrixDouble->arr[i]);
        if (i < matrixDouble->size - 1) {
            printf(",\n");
        }
    }
    printf("]");
}

void freeDoubleMatrix(matrix_double* matrixDouble) {
    for (int i = 0; i < matrixDouble->size; ++i) {
        free(matrixDouble->arr[i].arr);
    }
    free(matrixDouble->arr);
    free(matrixDouble);
}