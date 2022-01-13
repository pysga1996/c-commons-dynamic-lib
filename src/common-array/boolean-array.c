#include <stdlib.h>
#include <stdio.h>
#include <common-var.h>
#include <string.h>
#include <common-array.h>

arr_bool* scanBoolArr(int length) {
    arr_bool* arrBool = calloc(1, sizeof(arr_bool));
    arrBool->arr = calloc(length, sizeof(char));
    arrBool->size = length;
    printf(">>> Start input array of booleans:\n");
    char tempStr[256];
    for (int i = 0; i < length; ++i) {
        printf("- Enter element #%d:\n", i);
        scanf("%s", tempStr);
        char x = (char) strtol(tempStr, NULL, 10);
        if (x == 0) {
            arrBool->arr[i] = 0;
        } else {
            arrBool->arr[i] = 1;
        }
    }
    printf("<<< End input array of booleans.\n");
    return arrBool;
}

arr_bool *convertToBoolArr(char *buff) {
    arr_bool *pArrBool = calloc(1, sizeof(arr_bool));
//    printf("String: %s\n", buff);
    int capacity = ARRAY_CAPACITY;
    int index = 0;
    int *arr = calloc(capacity, sizeof(int));
    char *token = strtok(buff, DELIM);
    while (token != NULL) {
        int tmp = strtol(token, NULL, 10);
        arr[index] = tmp != 0 ? 1: 0;
//        printf("%d - %d\n", index, arr[index]);
        index++;
        if (index >= capacity) {
            capacity += ARRAY_CAPACITY;
            arr = realloc(arr, capacity * sizeof(int));
        }
//        printf("%s\n", token);
        token = strtok(NULL, DELIM);
    }
    pArrBool->arr = arr;
    pArrBool->size = index;
    return pArrBool;
}

arr_bool *readBoolArr(char *fileName) {
    FILE *fp;
    char *buff = calloc(BUFFER_SIZE, sizeof(char));
    fp = fopen(fileName, "r");
    fgets(buff, BUFFER_SIZE, fp);
    arr_bool *pArrBool = convertToBoolArr(buff);
    fclose(fp);
    free(buff);
    return pArrBool;
}

void printBoolArr(arr_bool* arrBool) {
    printf("[");
    for (int i = 0; i < arrBool->size; ++i) {
        if (i == arrBool->size - 1) {
            printf("%s", (arrBool->arr[i] == 0) ? "false" : "true");
        } else {
            printf("%s, ", (arrBool->arr[i] == 0) ? "false" : "true");
        }
    }
    printf("]");
}

void freeBoolArr(arr_bool* arrBool) {
    free(arrBool->arr);
    free(arrBool);
}
