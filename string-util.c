#include <string.h>
#include "common-functions.h"

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