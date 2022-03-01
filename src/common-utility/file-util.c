#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <common-array.h>
#include <common-string.h>
#include "common-utility.h"

#define EXIT_CODE 0
#define CONTINUE_CODE 1

arr_char *readMenu(char *menuFileName) {
    arr_char *menu = createString();
    int c;
    char *tmp;
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
        printf("%c", c);
        c = fgetc(menuPtr);
    }
}

void processMenu(char* menuFileName, ExDemoFuncMapper exDemoFuncMapper) {
    int command;
    arr_char *menu = readMenu(menuFileName);
    do {
        printf("%s", menu->arr);
        command = scanInt();
        ExDemoFuncPtr funcPtr = exDemoFuncMapper(command);
        if (funcPtr != NULL) {
            processExercise(funcPtr);
        }
    } while (command != EXIT_CODE);
    deleteString(menu);
}

void processExercise(ExDemoFuncPtr exDemoFuncPtr) {
    int command;
    printf(">>> Start >>>\n");
    do {
        exDemoFuncPtr();
        printf("Enter 1 to continue, or any other characters to get back to the main menu:\n");
        command = scanInt();
    } while (command == CONTINUE_CODE);
    printf("<<< End <<<\n\n\n");
}