#include <stdlib.h>
#include <string.h>
#include "common-functions.h"
#define DEFAULT_CAPACITY 50

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

arr_char* createString() {
    arr_char* arrString = malloc(sizeof(arr_char));
    *arrString = (arr_char) {calloc(DEFAULT_CAPACITY, sizeof(char)), DEFAULT_CAPACITY };
    return arrString;
}

void concatString(arr_char* aChar, char* characters) {
    unsigned long long currentLength = strlen(aChar->arr);
    unsigned long long appendixLength = strlen(characters);
    unsigned long long newLength = (currentLength + appendixLength);
    if (newLength > aChar->size) {
        aChar->arr = realloc(aChar->arr, newLength * sizeof(char) + 1);
        aChar->size = newLength;
    }
    strcat(aChar->arr, characters);
}

void deleteString(arr_char* aChar) {
    free(aChar->arr);
    free(aChar);
}