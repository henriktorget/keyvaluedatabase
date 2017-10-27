#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void main (void){

  FILE *f;

  // String handling by strtok_r()
  char *str1, *str2, *token, *subtoken;
  char *saveptr1, *saveptr2;
  int i;

  char *token_trimmed;

  // String fetched by getline()
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  char *trimwhitespace(char *str);

  //Open file, read only
  f = fopen("data.txt", "r");
    if (f == NULL)
      exit(EXIT_FAILURE);
  // Read it, string by string.
  // getline() returns ssize_t
  // Puts string in line field. 
    while((read = getline(&line, &len, f)) != -1) {
    
      //printf("Retrieved line of length %zu :\n", read);
      //printf("%s", line);
      
      //Parsing here
      //Split with '='  
      for (i = 0, str1 = line; ; i++, str1 = NULL) {
      
        token = strtok_r(str1, "=", &saveptr1);
        if(token == NULL)
          break;
        
        //Trim string whitespace (around '=')
        token = trimwhitespace(token);

        //Print to test
        printf("%d: %s\n", i, token);

      //  for(str2 = token; ; str2 = NULL)
      }
      
    }


  // Close file and linebuffer
  free(line);
  fclose(f);

  exit(EXIT_SUCCESS);
}



char *trimwhitespace(char *str)
{
  char *end;

  //Trim leading space
  while(isspace((unsigned char)*str)) str++;

  if(*str == 0) // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) -1;
  while(end > str && isspace((unsigned char)*end)) end--;

  //Wrire a null terminator
  *(end+1) = 0;

  return str;
}


