#include <stdlib.h>
#include <stdio.h>
#include <common-var.h>
#include <string.h>
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

matrix_bool *importBoolMatrix(char *fileName) {
    matrix_bool *pMatrixBool = calloc(1, sizeof(matrix_bool));
    FILE *fp;
    char *buff = calloc(BUFFER_SIZE, sizeof(char));
    fp = fopen(fileName, "r");
    int capacity = ARRAY_CAPACITY;
    int index = 0;
    arr_bool *arr = calloc(capacity, sizeof(arr_bool));
    while (fgets(buff, BUFFER_SIZE, fp) != NULL) {
        // Remove trailing newline
        buff[strcspn(buff, "\n")] = 0;
        arr_bool *pArrBool = convertToBoolArr(buff);
        arr[index] = *pArrBool;
        index++;
        if (index >= capacity) {
            capacity += ARRAY_CAPACITY;
            arr_bool *arrTmp = realloc(arr, capacity * sizeof(arr_bool));
            if (arrTmp != NULL) {
                arr = arrTmp;
            } else {
                printf("Cannot reallocate memory\n");
            }
        }
//    printf("String: %s\n", buff);
    }
    pMatrixBool->arr = arr;
    pMatrixBool->size = index;
    fclose(fp);
    free(buff);
    return pMatrixBool;
}

void printBoolMatrix(matrix_bool *pMatrixBool) {
    printf("[");
    for (int i = 0; i < pMatrixBool->size; ++i) {
        printBoolArr(&pMatrixBool->arr[i]);
        if (i < pMatrixBool->size - 1) {
            printf(",\n");
        }
    }
    printf("]");
}

void freeBoolMatrix(matrix_bool *pMatrixBool) {
    for (int i = 0; i < pMatrixBool->size; ++i) {
        free(pMatrixBool->arr[i].arr);
    }
    free(pMatrixBool->arr);
    free(pMatrixBool);
}