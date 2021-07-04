#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "common-functions.h"
#define DEFAULT_CAPACITY 50

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

arr_int* scanIntArr(int length) {
    arr_int* arrInt = calloc(1, sizeof(arr_int));
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

void printIntArr(arr_int* arrInt) {
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

void freeIntArr(arr_int* arrInt) {
    free(arrInt->arr);
    free(arrInt);
}

arr_double* scanDoubleArr(int length) {
    arr_double* arrFloat = calloc(1, sizeof(arr_double)) ;
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

void printDoubleArr(arr_double* arrDouble) {
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

void freeDoubleArr(arr_double* arrDouble) {
    free(arrDouble->arr);
    free(arrDouble);
}

arr_long* scanLongArr(int length) {
    arr_long* arrLong = calloc(1, sizeof(arr_long)) ;
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

void printLongArr(arr_long* arrLong) {
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

void freeLongArr(arr_long* arrLong) {
    free(arrLong->arr);
    free(arrLong);
}

arr_string* scanStringArr(int length) {
    arr_string* arrString = calloc(1, sizeof(arr_string));
    arrString->arr = calloc(length, sizeof(char*));
    arrString->size = length;
    printf(">>> Start input array of strings:\n");
    for (int i = 0; i < length; ++i) {
        (arrString->arr)[i] = calloc(sizeof(char), 512);
        printf("- Enter element #%d:\n", i);
        scanf("%s", (arrString->arr)[i]);
    }
    printf("<<< End input array of strings.\n");
    return arrString;
}

void printStringArr(arr_string* arrString) {
    printf("[");
    for (int i = 0; i < arrString->size; ++i) {
        if (i == arrString->size - 1) {
            printf("%s", arrString->arr[i]);
        } else {
            printf("%s, ", arrString->arr[i]);
        }
    }
    printf("]");
}

void freeStringArr(arr_string* arrString) {
    for (int i = 0; i < arrString->size; ++i) {
        free(arrString->arr[i]);
    }
    free(arrString->arr);
}

matrix_bool* scanBoolMatrix(int numberOfRows, int numberOfColumns) {
    matrix_bool* matrixBool = calloc(1, sizeof(matrix_bool));
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

void printBoolMatrix(matrix_bool* matrixBool) {
    printf("[");
    for (int i = 0; i < matrixBool->size; ++i) {
        printBoolArr(&matrixBool->arr[i]);
        if (i < matrixBool->size - 1) {
            printf(",\n");
        }
    }
    printf("]");
}

void freeBoolMatrix(matrix_bool* matrixBool) {
    for (int i = 0; i < matrixBool->size; ++i) {
        free(matrixBool->arr[i].arr);
    }
    free(matrixBool->arr);
    free(matrixBool);
}

matrix_int* scanIntMatrix(int numberOfRows, int numberOfColumns) {
    matrix_int* matrixInt = calloc(1, sizeof(matrix_int));
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

void printIntMatrix(matrix_int* matrixInt) {
    printf("[");
    for (int i = 0; i < matrixInt->size; ++i) {
        printIntArr(&matrixInt->arr[i]);
        if (i < matrixInt->size - 1) {
            printf(",\n");
        }
    }
    printf("]");
}

void freeIntMatrix(matrix_int* matrixInt) {
    for (int i = 0; i < matrixInt->size; ++i) {
        free(matrixInt->arr[i].arr);
    }
    free(matrixInt->arr);
    free(matrixInt);
}

matrix_double* scanDoubleMatrix(int numberOfRows, int numberOfColumns) {
    matrix_double* matrixDouble = calloc(1, sizeof(matrix_double));
    matrixDouble->arr = calloc(numberOfRows, sizeof(arr_double));
    matrixDouble->size = numberOfRows;
    printf(">>> Start input matrix of doubles:\n");

    for (int i = 0; i < numberOfRows; ++i) {
        printf("- Start enter row #%d:\n", i);
        matrixDouble->arr[i] = *scanDoubleArr(numberOfColumns);
        printf("- Finish enter row #%d:\n", i);
    }
    printf("<<< End input matrix of doubles.\n");
    return matrixDouble;
}

void printDoubleMatrix(matrix_double* matrixDouble) {
    printf("[");
    for (int i = 0; i < matrixDouble->size; ++i) {
        printDoubleArr(&matrixDouble->arr[i]);
        if (i < matrixDouble->size - 1) {
            printf(",\n");
        }
    }
    printf("]");
}

void freeDoubleMatrix(matrix_double* matrixDouble) {
    for (int i = 0; i < matrixDouble->size; ++i) {
        free(matrixDouble->arr[i].arr);
    }
    free(matrixDouble->arr);
    free(matrixDouble);
}

matrix_long* scanLongMatrix(int numberOfRows, int numberOfColumns) {
    matrix_long* matrixLong = calloc(1, sizeof(matrix_long));
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

void printLongMatrix(matrix_long* matrixLong) {
    printf("[");
    for (int i = 0; i < matrixLong->size; ++i) {
        printLongArr(&matrixLong->arr[i]);
        if (i < matrixLong->size - 1) {
            printf(",\n");
        }
    }
    printf("]");
}

void freeLongMatrix(matrix_long* matrixLong) {
    for (int i = 0; i < matrixLong->size; ++i) {
        free(matrixLong->arr[i].arr);
    }
    free(matrixLong->arr);
    free(matrixLong);
}


