//
// Created by henrik
//

#ifndef KEYVALUE_PARSER_H
#define KEYVALUE_PARSER_H

#include <ctype.h>
#include <stdlib.h>

#include <string.h>


// Removes whitespaces from each side of string.
char *TrimWhitespace(char* str);

// Checks wether a string is a number or not.
int IsNumber(char* str);

#endif //KEYVALUE_PARSER_H
