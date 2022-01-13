#include <stdlib.h>
#include <stdio.h>
#include <common-var.h>
#include <string.h>
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

matrix_double *readDoubleMatrix(char *fileName) {
    matrix_double *pMatrixDouble = calloc(1, sizeof(matrix_double));
    FILE *fp;
    char *buff = calloc(BUFFER_SIZE, sizeof(char));
    fp = fopen(fileName, "r");
    int capacity = ARRAY_CAPACITY;
    int index = 0;
    arr_double *arr = calloc(capacity, sizeof(arr_double));
    while (fgets(buff, BUFFER_SIZE, fp) != NULL) {
        // Remove trailing newline
        buff[strcspn(buff, "\n")] = 0;
        arr_double *pArrDouble = convertToDoubleArr(buff);
        arr[index] = *pArrDouble;
        index++;
        if (index >= capacity) {
            capacity += ARRAY_CAPACITY;
            arr_double *arrTmp = realloc(arr, capacity * sizeof(arr_double));
            if (arrTmp != NULL) {
                arr = arrTmp;
            } else {
                printf("Cannot reallocate memory\n");
            }
        }
//    printf("String: %s\n", buff);
    }
    pMatrixDouble->arr = arr;
    pMatrixDouble->size = index;
    fclose(fp);
    free(buff);
    return pMatrixDouble;
}

void printDoubleMatrix(matrix_double* pMatrixDouble) {
    printf("[");
    for (int i = 0; i < pMatrixDouble->size; ++i) {
        printDoubleArr(&pMatrixDouble->arr[i]);
        if (i < pMatrixDouble->size - 1) {
            printf(",\n");
        }
    }
    printf("]");
}

void freeDoubleMatrix(matrix_double* pMatrixDouble) {
    for (int i = 0; i < pMatrixDouble->size; ++i) {
        free(pMatrixDouble->arr[i].arr);
    }
    free(pMatrixDouble->arr);
    free(pMatrixDouble);
}