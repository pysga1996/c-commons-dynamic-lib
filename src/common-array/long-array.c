#include <stdlib.h>
#include <stdio.h>
#include <common-var.h>
#include <string.h>
#include <common-array.h>

arr_long *scanLongArr(int length) {
    arr_long *arrLong = calloc(1, sizeof(arr_long));
    arrLong->arr = calloc(length, sizeof(long long));
    arrLong->size = length;
    printf(">>> Start input array of longs:\n");
    char tempStr[256];
    for (int i = 0; i < length; ++i) {
        printf("- Enter element #%d:\n", i);
        scanf("%s", tempStr);
        arrLong->arr[i] = strtoll(tempStr, NULL, 10);
    }
    printf("<<< End input array of longs.\n");
    return arrLong;
}

arr_long *convertToLongArr(char *buff) {
    arr_long *pArrInt = calloc(1, sizeof(arr_long));
//    printf("String: %s\n", buff);
    int capacity = ARRAY_CAPACITY;
    int index = 0;
    long long *arr = calloc(capacity, sizeof(long long));
    char *token = strtok(buff, DELIM);
    while (token != NULL) {
        arr[index] = strtoll(token, NULL, 10);
//        printf("%d - %d\n", index, arr[index]);
        index++;
        if (index >= capacity) {
            capacity += ARRAY_CAPACITY;
            long long *arrTmp = realloc(arr, capacity * sizeof(long long));
            if (arrTmp != NULL) {
                arr = arrTmp;
            } else {
                printf("Cannot reallocate memory\n");
            }
        }
//        printf("%s\n", token);
        token = strtok(NULL, DELIM);
    }
    pArrInt->arr = arr;
    pArrInt->size = index;
    return pArrInt;
}

arr_long *importLongArr(const char *fileName) {
    FILE *fp;
    char *buff = calloc(BUFFER_SIZE, sizeof(char));
    fp = fopen(fileName, "r");
    fgets(buff, BUFFER_SIZE, fp);
    arr_long *pArrLong = convertToLongArr(buff);
    fclose(fp);
    free(buff);
    return pArrLong;
}

void printLongArr(arr_long *arrLong) {
    printf("[");
    for (int i = 0; i < arrLong->size; ++i) {
        if (i == arrLong->size - 1) {
            printf("%lld", arrLong->arr[i]);
        } else {
            printf("%lld, ", arrLong->arr[i]);
        }
    }
    printf("]");
}

void freeLongArr(arr_long *arrLong) {
    free(arrLong->arr);
    free(arrLong);
}