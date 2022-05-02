#include <stdlib.h>
#include <stdio.h>
#include <common-var.h>
#include <string.h>
#include "common-matrix.h"

matrix_string *scanStringMatrix(int numberOfRows, int numberOfColumns) {
    matrix_string *pMatrixString = calloc(1, sizeof(matrix_string));
    pMatrixString->arr = calloc(numberOfRows, sizeof(arr_long));
    pMatrixString->size = numberOfRows;
    printf(">>> Start input matrix of longs:\n");
    for (int i = 0; i < numberOfRows; ++i) {
        printf("- Start enter row #%d:\n", i);
        pMatrixString->arr[i] = *scanStringArr(numberOfColumns);
        printf("- Finish enter row #%d:\n", i);
    }
    printf("<<< End input matrix of longs.\n");
    return pMatrixString;
}

matrix_string *importStringMatrix(const char *fileName) {
    matrix_string *pMatrixString = calloc(1, sizeof(matrix_string));
    FILE *fp;
    char *buff = calloc(BUFFER_SIZE, sizeof(char));
    fp = fopen(fileName, "r");
    int capacity = ARRAY_CAPACITY;
    int index = 0;
    arr_string *arr = calloc(capacity, sizeof(arr_string));
    while (fgets(buff, BUFFER_SIZE, fp) != NULL) {
        // Remove trailing newline
        buff[strcspn(buff, "\n")] = 0;
        arr_string *pArrString = convertToStringArr(buff);
        arr[index] = *pArrString;
        index++;
        if (index >= capacity) {
            capacity += ARRAY_CAPACITY;
            arr_string *arrTmp = realloc(arr, capacity * sizeof(arr_string));
            if (arrTmp != NULL) {
                arr = arrTmp;
            } else {
                printf("Cannot reallocate memory\n");
            }
        }
//    printf("String: %s\n", buff);
    }
    pMatrixString->arr = arr;
    pMatrixString->size = index;
    fclose(fp);
    free(buff);
    return pMatrixString;
}

void printStringMatrix(matrix_string *pMatrixString) {
    printf("[");
    for (int i = 0; i < pMatrixString->size; ++i) {
        printStringArr(&pMatrixString->arr[i]);
        if (i < pMatrixString->size - 1) {
            printf(",\n");
        }
    }
    printf("]");
}

void freeStringMatrix(matrix_string *pMatrixString) {
    for (int i = 0; i < pMatrixString->size; ++i) {
        free(pMatrixString->arr[i].arr);
    }
    free(pMatrixString->arr);
    free(pMatrixString);
}