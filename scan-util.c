#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void clearStdIn(void) {
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

short int scanShortInt() {
    char tempStr[256];
    scanf("%s", tempStr);
    clearStdIn();
    return (short) strtol(tempStr, NULL, 10);
}

int scanInt() {
    char tempStr[256];
    scanf("%s", tempStr);
    clearStdIn();
    return (int) strtol(tempStr, NULL, 10);
}

unsigned int scanUnsignedInt() {
    char tempStr[256];
    scanf("%s", tempStr);
    clearStdIn();
    return (unsigned int) strtoul(tempStr, NULL, 10);
}

long int scanLongInt() {
    char tempStr[256];
    scanf("%s", tempStr);
    clearStdIn();
    return strtol(tempStr, NULL, 10);
}

unsigned long int scanUnsignedLongInt() {
    char tempStr[256];
    scanf("%s", tempStr);
    clearStdIn();
    return (unsigned long int) strtoul(tempStr, NULL, 10);
}

long long int scanLongLongInt() {
    char tempStr[256];
    scanf("%s", tempStr);
    clearStdIn();
    return (long long int) strtoll(tempStr, NULL, 10);
}

unsigned long long int scanUnsignedLongLongInt() {
    char tempStr[256];
    scanf("%s", tempStr);
    clearStdIn();
    return (unsigned long long int) strtoull(tempStr, NULL, 10);
}

float scantFloat() {
    char tempStr[256];
    scanf("%s", tempStr);
    clearStdIn();
    return strtof(tempStr, NULL);
}

long double scanLongDouble() {
    char tempStr[256];
    scanf("%s", tempStr);
    clearStdIn();
    return strtold(tempStr, NULL);
}

void scanString(char* string) {
    do {
        fgets(string, 512, stdin);
//        clearStdIn();
        fflush(stdin);
    } while (strcmp("\n", string) == 0);
}
