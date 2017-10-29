#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "node.h"
#include <stddef.h>

FILE *f;

// String handling by strtok_r()
char *str, *path,*strPath, *spPath, *token;
char *saveptr;
int i, j, k, result;

// String fetched by getline()
char *line = NULL;
size_t len = 0;
ssize_t read;

char *trimwhitespace(char *str);

int main (void){
  
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
          //When this for loop is finished, the conductor is
          //set to the last node specified.
          for (j = 0, path = token; ; j++, path = NULL){
            strPath = strtok_r(path, ".", &spPath);
            if(strPath == NULL)
              break;

            // Move conductor.
            // If j == 0, move conductor to root;

            if(j == 0)
            conductor = root;

            // Move conductor, create new nodes on the way if needed.
            // Send it the name of the next level.
            result = moveconductor(strPath);

            switch(result){
            
              case 1 : 
                // Node has been found and conductor has moved to it.
                printf("Node '%s' has been found and conductor has moved to it.\n", strPath);
                break;

              case 2 :
                // Max number or nodes allowed reached. 
                // Do something else
                printf("Max number of nodes allowed at this level reached.\n");
                break;

              case 3 :
                // Node was not found, created a new one with name given.
                printf("Node '%s' was not found, created it.\n", strPath);
                break;

              case 4 :
                // No child-nodes at all at this level.
                // Created a new one with name given.
                printf("No childnodes, created '%s'.\n", strPath);
                break;

              default : 
                // Sum ting wong.
                printf("Default... whatever that means...\n");
                break;
            }
          }// END parse left side of '='
        }// END find left side of '='

        //Find right side of '='.
        else if(i == 1){
          //Check if string or int
          //Conductor is at correct place. 
          //Check if right side is in quotation marks.  

        } // END else if 
      } // END 
    } // END while getline()


    printtree();
     /*
     *  Nodetree has been built. Now print it out.  
     *  Try to use a recursive function for this. 
     */ 
    
    // Move conductor to the beginning of the tree. 
   // conductor = root;  

    // Check if either int or string is not NULL. 
    // If both are NULL, it's a folder.

    // Print out names of children. 
    // Save the children. 

  // Close file and linebuffer
  free(line);
  fclose(f);

  //exit(EXIT_SUCCESS);
  return 0;
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


