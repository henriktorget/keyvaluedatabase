#include <string.h>
#include <stdlib.h>
#include "node.h"

int emptynodes;
int k, j;


//Looks for nodename given and moves conductor to that place.
//
//Return 1 if node has been found, and conductor is at correct place.
//Return 2 if no more room for nodes at this level.  
//Return 3 if node was not found, so it created a new one with name given. 
//Return 4 if there was no nodes avaliable, so it created a new one at [0] with given name.

int moveconductor(char *strPath){


  //Iterate through next nodes.
  for (k = 0, emptynodes = 0; k < MAX_NODES; k++){

    //If it does'nt exist, don't check it.
    if(conductor->pnNodes[k] != 0){
    
      //Compare names of nodes in next layer of nodes.
      if(strcmp(conductor->pnNodes[k]->pszName, strPath) == 0){
      
        //Found node, move conductor.
        conductor = conductor->pnNodes[k];
        return 1;
      }
    } else { 
      // Count number of empty slots for nodes. 
      emptynodes++; 
    }

  }

  //Nodearray is full. Do something else.  
  if(emptynodes == 0){

    return 2;
  
  }

  //There are no nodes in the array. Put it at the first place in array.

  if(emptynodes == MAX_NODES){
  
    conductor->pnNodes[0] = malloc(sizeof(NODE));
    conductor = conductor->pnNodes[0];
    conductor->pszName = strPath;

    return 4;
  }

  // If there are nodes in the array but its not full, 
  // find fisrt NULL pointer and create a new one there. 
  
  for (j = 0; j < MAX_NODES; j++){
  

    if(conductor->pnNodes[j] == 0){
    
 
      conductor->pnNodes[j] = malloc(sizeof(NODE));
      conductor = conductor->pnNodes[j];
      conductor->pszName = strPath;

      return 3;

    }
  }
  return 0;
}

int printtree(){


  printf("Recursive tree-printing-function-algoritm.\n");

  return 1;
  
}

