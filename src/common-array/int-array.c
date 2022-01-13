#include <stdlib.h>
#include <stdio.h>
#include <common-var.h>
#include <string.h>
#include <common-array.h>

arr_int *scanIntArr(int length) {
    arr_int *arrInt = calloc(1, sizeof(arr_int));
    arrInt->arr = calloc(length, sizeof(int));
    arrInt->size = length;
    printf(">>> Start input array of integers:\n");
    char tempStr[256];
    for (int i = 0; i < length; ++i) {
        printf("- Enter element #%d:\n", i);
        scanf("%s", tempStr);
        arrInt->arr[i] = (int) strtol(tempStr, NULL, 10);
    }
    printf("<<< End input array of integers.\n");
    return arrInt;
}

arr_int *convertToIntArr(char *buff) {
    arr_int *pArrInt = calloc(1, sizeof(arr_int));
//    printf("String: %s\n", buff);
    int capacity = ARRAY_CAPACITY;
    int index = 0;
    int *arr = calloc(capacity, sizeof(int));
    char *token = strtok(buff, DELIM);
    while (token != NULL) {
        arr[index] = strtol(token, NULL, 10);
//        printf("%d - %d\n", index, arr[index]);
        index++;
        if (index >= capacity) {
            capacity += ARRAY_CAPACITY;
            arr = realloc(arr, capacity * sizeof(int));
        }
//        printf("%s\n", token);
        token = strtok(NULL, DELIM);
    }
    pArrInt->arr = arr;
    pArrInt->size = index;
    return pArrInt;
}

arr_int *readIntArr(char *fileName) {
    FILE *fp;
    char *buff = calloc(BUFFER_SIZE, sizeof(char));
    fp = fopen(fileName, "r");
    fgets(buff, BUFFER_SIZE, fp);
    arr_int *pArrInt = convertToIntArr(buff);
    fclose(fp);
    free(buff);
    return pArrInt;
}

void printIntArr(arr_int *arrInt) {
    printf("[");
    for (int i = 0; i < arrInt->size; ++i) {
        if (i == arrInt->size - 1) {
            printf("%d", arrInt->arr[i]);
        } else {
            printf("%d, ", arrInt->arr[i]);
        }
    }
    printf("]");
}

void freeIntArr(arr_int *arrInt) {
    free(arrInt->arr);
    free(arrInt);
}