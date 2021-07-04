#include <stdlib.h>
#include <stdio.h>
#include "common-array.h"

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
