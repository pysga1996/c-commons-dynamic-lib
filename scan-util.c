#include <stdlib.h>
#include <stdio.h>

short int scanShortInt() {
    char tempStr[256];
    scanf("%s", tempStr);
    return (short) strtol(tempStr, NULL, 10);
}

int scanInt() {
    char tempStr[256];
    scanf("%s", tempStr);
    return strtol(tempStr, NULL, 10);
}

unsigned int scanUnsignedInt() {
    char tempStr[256];
    scanf("%s", tempStr);
    return (unsigned int) strtoul(tempStr, NULL, 10);
}

long int scanLongInt() {
    char tempStr[256];
    scanf("%s", tempStr);
    return strtol(tempStr, NULL, 10);
}

unsigned long int scanUnsignedLongInt() {
    char tempStr[256];
    scanf("%s", tempStr);
    return (unsigned long int) strtoul(tempStr, NULL, 10);
}

long long int scanLongLongInt() {
    char tempStr[256];
    scanf("%s", tempStr);
    return (long long int) strtoll(tempStr, NULL, 10);
}

unsigned long long int scanUnsignedLongLongInt() {
    char tempStr[256];
    scanf("%s", tempStr);
    return (unsigned long long int) strtoull(tempStr, NULL, 10);
}

float scantFloat() {
    char tempStr[256];
    scanf("%s", tempStr);
    return strtof(tempStr, NULL);
}

long double scanLongDouble() {
    char tempStr[256];
    scanf("%s", tempStr);
    return strtold(tempStr, NULL);
}
