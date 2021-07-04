#include <stdlib.h>
#include <stdio.h>
#include "common-matrix.h"

matrix_char *scanCharMatrix(int numberOfRows, int numberOfColumns) {
    matrix_char *matrixChar = calloc(1, sizeof(matrix_char));
    matrixChar->arr = calloc(numberOfRows, sizeof(arr_char));
    matrixChar->size = numberOfRows;
    printf(">>> Start input matrix of booleans:\n");
    for (int i = 0; i < numberOfRows; ++i) {
        printf("- Start enter row #%d:\n", i);
        matrixChar->arr[i] = *scanCharArr(numberOfColumns);
        printf("- Finish enter row #%d:\n", i);
    }
    printf("<<< End input matrix of booleans.\n");
    return matrixChar;
}

void printCharMatrix(matrix_char *matrixChar) {
    printf("[");
    for (int i = 0; i < matrixChar->size; ++i) {
        printCharArr(&matrixChar->arr[i]);
        if (i < matrixChar->size - 1) {
            printf(",\n");
        }
    }
    printf("]");
}

void freeCharMatrix(matrix_char *matrixChar) {
    for (int i = 0; i < matrixChar->size; ++i) {
        free(matrixChar->arr[i].arr);
    }
    free(matrixChar->arr);
    free(matrixChar);
}