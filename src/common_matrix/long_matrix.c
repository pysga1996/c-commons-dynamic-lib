#include <stdlib.h>
#include <stdio.h>
#include <common_var.h>
#include <string.h>
#include "common_matrix.h"

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

matrix_long *importLongMatrix(const char *fileName) {
    matrix_long *pMatrixInt = calloc(1, sizeof(matrix_long));
    FILE *fp;
    char *buff = calloc(BUFFER_SIZE, sizeof(char));
    fp = fopen(fileName, "r");
    int capacity = ARRAY_CAPACITY;
    int index = 0;
    arr_long *arr = calloc(capacity, sizeof(arr_long));
    while (fgets(buff, BUFFER_SIZE, fp) != NULL) {
        // Remove trailing newline
        buff[strcspn(buff, "\n")] = 0;
        arr_long *pArrLong = convertToLongArr(buff);
        arr[index] = *pArrLong;
        index++;
        if (index >= capacity) {
            capacity += ARRAY_CAPACITY;
            arr_long *arrTmp = realloc(arr, capacity * sizeof(arr_long));
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

void printLongMatrix(matrix_long *pMatrixLong) {
    printf("[");
    for (int i = 0; i < pMatrixLong->size; ++i) {
        printLongArr(&pMatrixLong->arr[i]);
        if (i < pMatrixLong->size - 1) {
            printf(",\n");
        }
    }
    printf("]");
}

void freeLongMatrix(matrix_long *pMatrixLong) {
    for (int i = 0; i < pMatrixLong->size; ++i) {
        free(pMatrixLong->arr[i].arr);
    }
    free(pMatrixLong->arr);
    free(pMatrixLong);
}