#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "common-functions.h"
#define DEFAULT_CAPACITY 50

arr_int scanIntArr(int length) {
    arr_int arrInt = { calloc(length, sizeof(int)), length };
    printf(">>> Start input array of integers:\n");
    char tempStr[256];

    for (int i = 0; i < length; ++i) {
        printf("- Enter element #%d:\n", i);
        scanf("%s", tempStr);
        arrInt.arr[i] = (int) strtol(tempStr, NULL, 10);
    }
    printf("<<< End input array of integers.\n");
    return arrInt;
}

void printIntArr(arr_int arrInt) {
    printf("[");
    for (int i = 0; i < arrInt.size; ++i) {
        if (i == arrInt.size - 1) {
            printf("%d", arrInt.arr[i]);
        } else {
            printf("%d, ", arrInt.arr[i]);
        }
    }
    printf("]");
}

void freeIntArr(arr_int arrInt) {
    free(arrInt.arr);
}

arr_double scanDoubleArr(int length) {
    arr_double arrFloat = {calloc(length, sizeof(float)), length };
    printf(">>> Start input array of floats:\n");
    char tempStr[256];

    for (int i = 0; i < length; ++i) {
        printf("- Enter element #%d:\n", i);
        scanf("%s", tempStr);
        arrFloat.arr[i] = strtof(tempStr, NULL);
    }
    printf("<<< End input array of floats.\n");
    return arrFloat;
}

void printDoubleArr(arr_double arrFloat) {
    printf("[");
    for (int i = 0; i < arrFloat.size; ++i) {
        if (i == arrFloat.size - 1) {
            printf("%f", arrFloat.arr[i]);
        } else {
            printf("%f, ", arrFloat.arr[i]);
        }
    }
    printf("]");
}

void freeDoubleArr(arr_double arrFloat) {
    free(arrFloat.arr);
}

arr_string scanStringArr(int length) {
    arr_string arrString = {calloc(length, sizeof(char*)), length };
    printf(">>> Start input array of strings:\n");
    for (int i = 0; i < length; ++i) {
        (arrString.arr)[i] = calloc(sizeof(char), 512);
        printf("- Enter element #%d:\n", i);
        scanf("%s", (arrString.arr)[i]);
    }
    printf("<<< End input array of strings.\n");
    return arrString;
}

void printStringArr(arr_string arrString) {
    printf("[");
    for (int i = 0; i < arrString.size; ++i) {
        if (i == arrString.size - 1) {
            printf("%s", arrString.arr[i]);
        } else {
            printf("%s, ", arrString.arr[i]);
        }
    }
    printf("]");
}

void freeStringArr(arr_string arrString) {
    for (int i = 0; i < arrString.size; ++i) {
        free(arrString.arr[i]);
    }
    free(arrString.arr);
}

arr_char* createString() {
    arr_char* arrString = malloc(sizeof(arr_char));
    *arrString = (arr_char) {calloc(DEFAULT_CAPACITY, sizeof(char)), DEFAULT_CAPACITY };
    return arrString;
}

void concatString(arr_char* aChar, char* characters) {
    unsigned long long currentLength = strlen(aChar->content);
    unsigned long long appendixLength = strlen(characters);
    unsigned long long newLength = (currentLength + appendixLength);
    if (newLength > aChar->length) {
        aChar->content = realloc(aChar->content, newLength * sizeof(char) + 1);
        aChar->length = newLength;
    }
    strcat(aChar->content, characters);
}

void deleteString(arr_char* aChar) {
    free(aChar->content);
    free(aChar);
}


