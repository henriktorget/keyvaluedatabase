//
// Created by henrik
//

#include "parser.h"

char* TrimWhitespace(char *str){

    char *end;

    //Trim leading space
    while(isspace((unsigned char)*str)) str++;

    if(*str == 0) // All spaces??
        return str;

    //Trim trailing space
    end = str + strlen(str) -1;
    while(end > str && isspace((unsigned char)*end)) end--;

    //Write a null terminator
    *(end+1) = '\0';

    return str;

}

int IsNumber(char* str){

    if(isdigit((unsigned char)*str))
    {
        return 1;
    }

return 0;

}

