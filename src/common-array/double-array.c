#include <stdlib.h>
#include <stdio.h>
#include <common-var.h>
#include <string.h>
#include "common-array.h"

arr_double *scanDoubleArr(int length) {
    arr_double *arrFloat = calloc(1, sizeof(arr_double));
    arrFloat->arr = calloc(length, sizeof(double));
    arrFloat->size = length;
    printf(">>> Start input array of floats:\n");
    char tempStr[256];

    for (int i = 0; i < length; ++i) {
        printf("- Enter element #%d:\n", i);
        scanf("%s", tempStr);
        arrFloat->arr[i] = strtof(tempStr, NULL);
    }
    printf("<<< End input array of floats.\n");
    return arrFloat;
}

arr_double *readDoubleArr(char *fileName) {
    arr_double *pDoubleArr = calloc(1, sizeof(arr_double));
    FILE *fp;
    char *buff = calloc(BUFFER_SIZE, sizeof(char));
    fp = fopen(fileName, "r");
    fgets(buff, BUFFER_SIZE, (FILE *) fp);
//    printf("String: %s\n", buff);
    int capacity = ARRAY_CAPACITY;
    int index = 0;
    double *arr = calloc(capacity, sizeof(double));
    char *token = strtok(buff, DELIM);
    while (token != NULL) {
        arr[index] = strtod(token, NULL);
//        printf("%d - %s\n", index, arr[index]);
        index++;
        if (index >= capacity) {
            capacity += ARRAY_CAPACITY;
            arr = realloc(arr, capacity);
        }
//        printf("%s\n", token);
        token = strtok(NULL, DELIM);
    }
    pDoubleArr->arr = arr;
    pDoubleArr->size = index;
    fclose(fp);
    free(buff);
    return pDoubleArr;
}

void printDoubleArr(arr_double *arrDouble) {
    printf("[");
    for (int i = 0; i < arrDouble->size; ++i) {
        if (i == arrDouble->size - 1) {
            printf("%f", arrDouble->arr[i]);
        } else {
            printf("%f, ", arrDouble->arr[i]);
        }
    }
    printf("]");
}

void freeDoubleArr(arr_double *arrDouble) {
    free(arrDouble->arr);
    free(arrDouble);
}