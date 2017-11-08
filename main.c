#include "node.h"
#include "parser.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

FILE *f;

char *str, *token, *path, *nodearg, *nodename;

char *saveptr1, *saveptr2;

int i, j, nodecheck;

char *line = 0;
size_t len = 0;
ssize_t read;

NODE *root;

NODE *conductor;

int main(void){

  root = (NODE*) malloc(sizeof(NODE));
  root->pszName = (char*) "root";

  for(int z = 0; z < MAX_NODES; z++){
    root->pnNodes[z] = 0;
  }

  // Open file read only
  f = fopen("data.txt", "r");
    if (f == 0)
      exit(EXIT_FAILURE);

  // Read it string by string.
  while((read = getline(&line, &len, f)) != -1) {
  
    for(i = 0, str = line; ; i++, str = 0){
    
      token = strtok_r(str, "=", &saveptr1);
      if(token == 0)
        break;

      // Trim string whitespace around '='
      token = trimwhitespace(token);

      //printf("\ntoken: %s\n", token);

      // Token is on the left side of '='
      if(i == 0){

        printf("\n\tLeft side of '='\n");
        // Traverse list of nodes based on name.
        // When this loop is finished, the conductor is set to the last node in
        // 'token'
        for(j = 0, path = token; ; j++, path = 0){
          
       printf("j: %d | ", j); 
          //If this is the first time this for loop runs,
          //it should start at root. 
          if(j == 0){
            conductor = root;
            //printf("This should be root :%s\n", conductor->pszName);
          }

          nodename = strtok_r(path, ".", &saveptr2);


          // No more directions left in token. 
          if(nodename == 0)
            break;

          printf("nodename: %s | ", nodename);
          
          // See if child exists, returns where in array.
          nodecheck = childexists((NODE*) conductor, nodename);

          printf("nodecheck: %d |\n", nodecheck);
          if(nodecheck >= 0 ){
          
            // Node exists return position in array.
            conductor = conductor->pnNodes[nodecheck];

          } else if(nodecheck == -1){
            // All nodepointers are empty. Create a new one.
            printf("Node '%s' not found in '%s', creating it.\n", nodename,
                conductor->pszName);

            conductor = createnode(conductor, nodename);          

          } else if(nodecheck == -2){
            //Cant find node.

            
            //Create new node. With name. Move conductor to it. 
            conductor = createnode(conductor, nodename);

          } else if(nodecheck == -3)

            //Child does not exist. Node is full..
            printf("Node '%s' is full of children. You should turn some of them in for adoption.", 
                conductor->pszName);
                
        } 


      } else if( i == 1){
     
        //nodearg = token;

          printf("\tRight side of '='\n");
        
          // Check if nodearg is in quotationmarks.

        } else {printf("Sum ting wong");}
    } // end for each line
  } // end of while read getline()


  printnodetree(root);

//  freetree(root);

  exit(EXIT_SUCCESS);
}

