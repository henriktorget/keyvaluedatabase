//
// Created by henrik
//

#ifndef KEYVALUE_PARSER_H
#define KEYVALUE_PARSER_H

#include <ctype.h>
#include <stdlib.h>

#include <string.h>

// Splits string in array of words divided by '.'
char** splitInPeriod(char* str);

// Removes whitespaces from each side of string.
char *trimwhitespace(char* str);

// Checks wether a string is a number or not.
int isNumber(char* str);

#endif //KEYVALUE_PARSER_H
