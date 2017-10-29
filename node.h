#ifndef __NODE_H__
#define __NODE_H__

#define MAX_NODES 10

#include <stdio.h>

typedef unsigned long ULONG;

typedef struct _NODE{
  char *pszName;    // Name of the node.
  ULONG ulIntVal;   // If numeric type, the value it self.
  char *pszString;  // String pointer or NULL if numeric.
  struct _NODE *pnNodes[MAX_NODES]; //Pointers to the nodes
} NODE;

//Root node
NODE *root;

//Traversing node pointer
NODE *conductor;


int moveconductor(char *strPath);

int printtree();

#endif //__HEADER_H_
