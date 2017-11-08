#include "parser.h"
#include <string.h>

char *trimwhitespace(char *str){

  char *end;

  //Trim leading space
  while(isspace((unsigned char)*str)) str++;

  if(*str == 0) // All spaces??
    return str;

  //Trim trailing space
  end = str + strlen(str) -1;
  while(end > str && isspace((unsigned char)*end)) end--;

  //Write a null terminator
  *(end+1) = 0;

  return str;

}
