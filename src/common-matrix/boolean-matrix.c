#include <stdlib.h>
#include <stdio.h>
#include "common-matrix.h"

matrix_bool *scanBoolMatrix(int numberOfRows, int numberOfColumns) {
    matrix_bool *matrixBool = calloc(1, sizeof(matrix_bool));
    matrixBool->arr = calloc(numberOfRows, sizeof(arr_bool));
    matrixBool->size = numberOfRows;
    printf(">>> Start input matrix of booleans:\n");
    for (int i = 0; i < numberOfRows; ++i) {
        printf("- Start enter row #%d:\n", i);
        matrixBool->arr[i] = *scanBoolArr(numberOfColumns);
        printf("- Finish enter row #%d:\n", i);
    }
    printf("<<< End input matrix of booleans.\n");
    return matrixBool;
}

void printBoolMatrix(matrix_bool *matrixBool) {
    printf("[");
    for (int i = 0; i < matrixBool->size; ++i) {
        printBoolArr(&matrixBool->arr[i]);
        if (i < matrixBool->size - 1) {
            printf(",\n");
        }
    }
    printf("]");
}

void freeBoolMatrix(matrix_bool *matrixBool) {
    for (int i = 0; i < matrixBool->size; ++i) {
        free(matrixBool->arr[i].arr);
    }
    free(matrixBool->arr);
    free(matrixBool);
}