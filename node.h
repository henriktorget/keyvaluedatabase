//
// Created by henrik on 11/10/17.
//

#ifndef KEYVALUE_NODE_H
#define KEYVALUE_NODE_H

#define MAX_NODES 10

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long ULONG;

typedef struct _NODE{
    char *pszName; // Name of the node.
    ULONG ulIntVal; // If numeric type, the value itself.
    char *pszString; // String pointer og NULL if numeric.
    struct _NODE *pnNodes[MAX_NODES]; // Pointers to the nodes.
} NODE;


FILE *f;
char  *str, *token, *path, *nodename, *nodearg, *saveptr;

int i, j, nodecheck, type;

char *line;

NODE *root;

NODE *conductor;



void createNodeTree(char* filenname);

// Checks if child exists in given node.
int childexists(NODE* node, char* childname);

//Checks if there is
//int fullofchildren(NODE* node);

// This function return pointer to child with name nodename.
// If the child is null.
NODE* findnode(char *nodename);

//Create child at given node. Return new node.
NODE* createnode(NODE* node, char* childname);

//Sets number to given node.
void setNumber(NODE* node, ULONG number);

//Sets string to given node.
void setString(NODE* node, char* str);

//Get wether node stores string or int.
int GetType(char* string);

//Recursive print function

void printnodetree(NODE* rootprint);

//Frees memory from node specified.
void freetree(NODE* rootfree);

// Create two nodes in roots array. Print them.
void nodetest();


#endif //KEYVALUE_NODE_H
