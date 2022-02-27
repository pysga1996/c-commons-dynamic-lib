#include <string.h>
#include <stdlib.h>
#include <common-utility.h>
#include <common-array.h>
#include <common-var.h>

int isUppercaseCharacter(char character) {
    return character >= 'A' && character <= 'Z';
}

int isLowercaseCharacter(char character) {
    return character >= 'a' && character <= 'z';
}

int isDigit(char character) {
    return character >= '0' && character <= '9';
}

int isWordOrDigit(char character) {
    return isLowercaseCharacter(character) || isUppercaseCharacter(character) || isDigit(character);
}

int isSpecialCharacter(char character) {
    int match = 0;
    for (int i = 0; i < strlen(SPECIAL_CHARACTERS); ++i) {
        if (SPECIAL_CHARACTERS[i] == character) {
            match = 1;
            break;
        }
    }
    return match;
}

arr_char *createString() {
    arr_char *arrChar = calloc(1, sizeof(arr_char));
    char *strPtr = calloc(1, sizeof(char));
    strPtr[0] = '\0';
    arrChar->arr = strPtr;
    arrChar->size = 0;
    return arrChar;
}

void concatString(arr_char *aChar, char *characters) {
    unsigned long long currentLength = strlen(aChar->arr);
    unsigned long long appendixLength = strlen(characters);
    unsigned long long newLength = (currentLength + appendixLength);
    if (newLength > aChar->size) {
        char *newCharPtr = realloc(aChar->arr, (newLength + 1) * sizeof(char));
        aChar->arr = newCharPtr;
        aChar->size = newLength;
    }
    strcat(aChar->arr, characters);
}

void deleteString(arr_char *aChar) {
    free(aChar->arr);
    free(aChar);
}