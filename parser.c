//
// Created by henrik on 11/10/17.
//

#include "parser.h"


/*
char** splitInPeriod(char* str){

    char* parsestring = str;
    //printf("Test: %s", str):
    int number = 0;

    while(strtok_r(parsestring, ".", &saveptr) != 0)
        number++;


    char** sub_str = (char**) malloc(number * sizeof(char*));

    for (int i = 0; i < number; i++){
        parsetoken = strtok_r(str, ".", &saveptr);
        sub_str[i] = (char*) malloc(sizeof(parsetoken));

    }

    arrayLength = number;
    return sub_str;

}
*/
char* trimwhitespace(char *str){

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

int isNumber(char* str){

    if(isdigit((unsigned char)*str))
    {
        return 1;
    }

return 0;

}

