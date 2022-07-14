#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <common_var.h>
#include "common_matrix.h"

matrix_int *scanIntMatrix(int numberOfRows, int numberOfColumns) {
    matrix_int *matrixInt = calloc(1, sizeof(matrix_int));
    matrixInt->arr = calloc(numberOfRows, sizeof(arr_int));
    matrixInt->size = numberOfRows;
    printf(">>> Start input matrix of integers:\n");
    for (int i = 0; i < numberOfRows; ++i) {
        printf("- Start enter row #%d:\n", i);
        matrixInt->arr[i] = *scanIntArr(numberOfColumns);
        printf("- Finish enter row #%d:\n", i);
    }
    printf("<<< End input matrix of integers.\n");
    return matrixInt;
}

matrix_int *importIntMatrix(const char *fileName) {
    matrix_int *pMatrixInt = calloc(1, sizeof(matrix_int));
    FILE *fp;
    char *buff = calloc(BUFFER_SIZE, sizeof(char));
    fp = fopen(fileName, "r");
    int capacity = ARRAY_CAPACITY;
    int index = 0;
    arr_int *arr = calloc(capacity, sizeof(arr_int));
    while (fgets(buff, BUFFER_SIZE, fp) != NULL) {
        // Remove trailing newline
        buff[strcspn(buff, "\n")] = 0;
        arr_int *pArrInt = convertToIntArr(buff);
        arr[index] = *pArrInt;
        index++;
        if (index >= capacity) {
            capacity += ARRAY_CAPACITY;
            arr_int *arrTmp = realloc(arr, capacity * sizeof(arr_int));
            if (arrTmp != NULL) {
                arr = arrTmp;
            } else {
                printf("Cannot reallocate memory\n");
            }
        }
//    printf("String: %s\n", buff);
    }
    pMatrixInt->arr = arr;
    pMatrixInt->size = index;
    fclose(fp);
    free(buff);
    return pMatrixInt;
}

void printIntMatrix(matrix_int *matrixInt) {
    printf("[");
    for (int i = 0; i < matrixInt->size; ++i) {
        arr_int arrInt = matrixInt->arr[i];
        printIntArr(&arrInt);
        if (i < matrixInt->size - 1) {
            printf(",\n");
        }
    }
    printf("]");
}

void freeIntMatrix(matrix_int *matrixInt) {
    for (int i = 0; i < matrixInt->size; ++i) {
        free(matrixInt->arr[i].arr);
    }
    free(matrixInt->arr);
    free(matrixInt);
}