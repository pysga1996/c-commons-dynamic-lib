#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "common-matrix.h"

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

matrix_int *importIntMatrix(int rows, int cols, char *fileName) {
    FILE *fp;
    int c;
    int currentRow = 0;
    int currentColumn = 0;
    matrix_int *matrixInt = calloc(1, sizeof(matrix_int));
    matrixInt->arr = calloc(rows, sizeof(arr_int));
    matrixInt->size = rows;
    for (int i = 0; i < rows; ++i) {
        matrixInt->arr[i].arr = calloc(cols, sizeof(int));
        matrixInt->arr[i].size = cols;
    }
    fp = fopen(fileName, "r");
    if (fp == NULL) {
        perror("Error while opening matrix.txt !!!");
        exit(-1);
    }
    int mark = -1;
    char numberStr[20] = "";
    char ch;
    do {
        c = fgetc(fp);
        if (feof(fp)) {
            break;
        }
//        printf("%c", c);
        if (c >= '0' && c <= '9') {
            mark++;
            ch = (char) c;
            strncat(numberStr, &ch, 1);
        } else {
            if (mark >= 0) {
                if (currentRow >= rows) {
                    break;
                }
                if (currentColumn >= cols) {
                    currentColumn = 0;
                    currentRow++;
                }
                matrixInt->arr[currentRow].arr[currentColumn] = strtol(numberStr, NULL,
                                                                       10); // convert string to integer
                memset(numberStr, 0, sizeof(numberStr)); // make string empty
                currentColumn++;
            }
            mark = -1;
        }
    } while (1);
    fclose(fp);
    return matrixInt;
}

void printIntMatrix(matrix_int *matrixInt) {
    printf("[");
    for (int i = 0; i < matrixInt->size; ++i) {
        printIntArr(&matrixInt->arr[i]);
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