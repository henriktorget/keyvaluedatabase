#ifndef __PARSER_H__
#define __PARSER_H__

#include <ctype.h>
#include <stdlib.h>
char *parsetoken, *saveptr;

// Splits string in two by '=', returns array.
//char** splitinequals(char* str);

// Splits string in array of words divided by '.'
char** splitInPeriod(char* str);

// Removes whitespaces from each side of string.
char *trimwhitespace(char* str);

#endif //__PARSER_H_
