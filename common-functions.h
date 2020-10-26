#ifndef COMMON_FUNCTIONS_SCAN_UTIL_H
#define COMMON_FUNCTIONS_SCAN_UTIL_H

typedef struct ArrInt {
    int* arr;
    int size;
} arr_int;

typedef struct ArrFloat {
    float* arr;
    int size;
} arr_float;

short int scanShortInt();

int scanInt();

unsigned int scanUnsignedInt();

long int scanLongInt();

unsigned long int scanUnsignedLongInt();

long long int scanLongLongInt();

unsigned long long int scanUnsignedLongLongInt();

float scantFloat();

long double scanLongDouble();

arr_int scanIntArr(int length);

void printIntArr(arr_int arrInt);

void freeIntArr(arr_int arrInt);

arr_float scanFloatArr(int length);

void printFloatArr(arr_float arrFloat);

void freeFloatArr(arr_float arrFloat);

#endif //COMMON_FUNCTIONS_SCAN_UTIL_H
