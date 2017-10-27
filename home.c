#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 10
typedef unsigned long ULONG;

FILE *f;

// String handling by strtok_r()
char *str, *path,*strPath, *spPath, *token;
char *saveptr;
int i, j;

// String fetched by getline()
char *line = NULL;
size_t len = 0;
ssize_t read;

char *trimwhitespace(char *str);

typedef struct _NODE{
  char *pszName; // Name of the node
  ULONG ulIntVal; // If numeric type, the value itself
  char *pszString; // String pointer or NULL if numeric
  struct _NODE *pnNodes[MAX_NODES]; //Pointers to the nodes
} NODE;

void main (void){
  
  //Root node.
  NODE *root;

  //Traversing node pointer
  NODE *conductor;

  root = malloc( sizeof(NODE) );
  

  //Open file, read only
  f = fopen("data.txt", "r");
    if (f == NULL)
      exit(EXIT_FAILURE);

    // Read it, string by string.
    // getline() returns ssize_t
    // Puts string in line field. 
    while((read = getline(&line, &len, f)) != -1) {
    
      //Parsing here
      for (i = 0, str = line; ; i++, str = NULL) {
      
        token = strtok_r(str, "=", &saveptr);
        if(token == NULL)
          break;
        
        //Trim string whitespace (around '=')
        token = trimwhitespace(token);

        //Find left side of '='
        if(i == 0){
          //Create/traverse nodes.

          for (j = 0, path = token; ; j++, path = NULL){
            strPath = strtok_r(path, ".", &spPath);
            if(strPath == NULL)
              break;

            // Move conductor.
            // If j == 0, set conductor at root;

//            if(j == 0)
//            conductor = root;

            // Check if node allready exists.



            //Testing
            printf("Node%d: %s\n", j, strPath);

          }
        
        }
        //Find right side of '='.
        else if(i == 1){
          //Check if string or int
          //Conductor is at correct place. 
        }
        //Print to test
        //printf("%d: %s\n", i, token);
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

  //Trim trailing space
  end = str + strlen(str) -1;
  while(end > str && isspace((unsigned char)*end)) end--;

  //Wrire a null terminator
  *(end+1) = 0;

  return str;
}


