#include "node.h"
#include <string.h>
#include <stdlib.h>

int childexists(NODE* node, char* childname){
  
  int strcmpVal;
  char* namecheck;

  int emptycount;

  for(int i = 0; i < MAX_NODES; i++){
 
    //printf("i = %d\n", i);
    // Check if  
    if(node->pnNodes[i] != 0){
      namecheck = node->pnNodes[i]->pszName;
      printf("Childexists(): node->pnNodes[%i]->pszName = %s\n", i, namecheck);
 
      printf("namecheck = %s, childname = %s ", 
          namecheck, childname);
      strcmpVal = strcmp(namecheck, childname);
  
      printf("strcmpVal: %d\n", strcmpVal);

      if(strcmpVal == 0)
          return i;
    
    }
    else{
      emptycount++;
    }

    //if(strcmp(namecheck, childname) == 0)
    //  return i;
  
  }

  //printf("emptycount = %d \n", emptycount);
  //  All nodepointers are empty.
  if(emptycount == MAX_NODES){
    return -1;
  } else if(emptycount == 0){
    // All nodepointers are full.
    return -3;
  }
  // If it went through all nonempty childnodes and there is room for a new one
    return -2;
}

NODE* createnode(NODE* node, char* childname){
printf("Createnode()\n");
  for(int k = 0; k < MAX_NODES; k++){
    if(node->pnNodes[k] == 0){
      
      node->pnNodes[k] = (NODE*) malloc(sizeof(NODE));

      for (int x = 0; x < MAX_NODES; x++){
      
        //node->pnNodes[k]->pnNodes[x] = (NODE*) malloc(sizeof(NODE));
        //node->pnNodes[k]->pnNodes[x] = 0;
      
      }
      node->pnNodes[k]->pszName = childname;

      return node->pnNodes[k];
    }
  }
  return 0;
}

void printnodetree(NODE* rootprint){

printf("%s\n", rootprint->pnNodes[0]->pszName);

printf("%s\n", rootprint->pnNodes[0]->pnNodes[0]->pszName);


/*
  if(rootprint == 0)
    return;

  for(int l = 0; l < 1; l++){
    if(rootprint->pnNodes[l] != 0){
    printnodetree(rootprint->pnNodes[l]);
    printf("%s ", rootprint->pnNodes[l]->pszName);
    }
  }
*/
}

void freetree(NODE* rootfree){

  if (rootfree == 0)
    return;
  
  for(int i = 0; i < MAX_NODES; i++){
    freetree(rootfree->pnNodes[i]);
    free(rootfree);
  }

}

/*
void nodetest(){

//root = malloc(sizeof(NODE));
//root->pszName = "root";

//root->pnNodes[0] = malloc(sizeof(NODE));
//root->pnNodes[1] = malloc(sizeof(NODE));

//root->pnNodes[0]->pszName = "firstchild";
//root->pnNodes[1]->pszName = "secondchild";

printf("%s and %s are children of %s\n", 
    root->pnNodes[0]->pszName,
    root->pnNodes[1]->pszName,
    root->pszName);

}

*/
