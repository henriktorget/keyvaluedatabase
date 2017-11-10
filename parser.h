//
// Created by henrik on 11/10/17.
//

#ifndef KEYVALUE_PARSER_H
#define KEYVALUE_PARSER_H

#include <ctype.h>
#include <stdlib.h>


char *parsetoken, *saveptr;

// Splits string in two by '=', returns array.
//char** splitinequals(char* str);

// Splits string in array of words divided by '.'
char** splitInPeriod(char* str);

// Removes whitespaces from each side of string.
char *trimwhitespace(char* str);

#endif //KEYVALUE_PARSER_H
