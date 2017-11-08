#ifndef __NODE_H__
#define __NODE_H__

#define MAX_NODES 10

#include <stdio.h>
#include <stdlib.h>


typedef unsigned long ULONG;

typedef struct _NODE{
  char *pszName; // Name of the node.
  struct _NODE *pnNodes[MAX_NODES]; // Pointers to the nodes.
} NODE;

// Root node
//NODE *root = (NODE*) malloc(sizeof(NODE));


//Traversing node 'cursor'
//NODE *conductor;

// Checks if child exists in given node. 
int childexists(NODE* node, char* childname);

//Checks if there is 
//int fullofchildren(NODE* node);

// This function return pointer to child with name nodename.
// If the child is null.  
NODE* findnode(char *nodename);

//Move conductor to this existin node. 
//NODE* moveconductor(nodename);

//Create child at given node. Return new node. 
NODE* createnode(NODE* node, char* childname);

//Recursive print function

void printnodetree(NODE* rootprint);

//Frees memory from node specified. 
void freetree(NODE* rootfree);

// Create two nodes in roots array. Print them. 
void nodetest();

#endif //__NODE_H__
