#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include "common-functions.h"

arr_char* readMenu(char* menuFileName) {
    arr_char* menu = createString();
    int c;
    char* tmp;
    FILE *menuPtr = fopen(menuFileName, "r");
    if (menuPtr == NULL) {
        printf("Cannot open file \n");
        exit(ENOENT);
    }
    c = fgetc(menuPtr);
    tmp = (char[]) {c, '\0'};
    concatString(menu, tmp);
    while (c != EOF) {
        c = fgetc(menuPtr);
        tmp = (char[]) {c, '\0'};
        concatString(menu, tmp);
    }
    fclose(menuPtr);
    return menu;
}

void readMenuNoBuffer(FILE *menuPtr) {
    rewind(menuPtr);
    int c;
    if (menuPtr == NULL) {
        printf("Cannot open file \n");
        exit(ENOENT);
    }
    c = fgetc(menuPtr);
    while (c != EOF) {
        printf ("%c", c);
        c = fgetc(menuPtr);
    }
}