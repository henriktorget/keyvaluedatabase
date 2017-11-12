//
// Created by henrik
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
char  *str, *token, *path, *nodename, *nodearg, *saveptr, *saveptr2;

int i, j, nodecheck, type;

char *line;

NODE *root;

NODE *conductor;



void CreateNodeTree(char* filenname);

// Checks if child exists in given node.
int ChildExists(NODE* node, char* childname);

//Checks if there is
//int fullofchildren(NODE* node);

// Checks if a node has any children at all.
int IsEmpty(NODE* node);

//Traverses conductor along path like "config.update.interval".
// When this function is finished, conductor points at "interval" in this case.
int MoveConductor(char* str);

//Create child at given node. Return new node.
NODE* CreateNode(NODE* node, char* childname);

// Deletes node with children.
void Delete(char* nodename);

//Sets number to given node.
void SetNumber(NODE* node, ULONG number);

//Sets string to given node.
void SetString(NODE* node, char* str);

// Returns 1 if node has a value assigned. 0 if not. -1 if both.
int HasType(NODE* node);

//Get wether node stores string or int.
int GetType(char* string);

//Get int
int GetInt(char* str);

// Get string
char* GetString(char* str);

// Enumerate
void Enumerate(char* str);

//GetText
char* GetText(char* string, char* lang);

//Recursive print function
void PrintNodeTree(NODE* rootprint);

// Function used by Delete() to recursively delete all cildnodes.
void DeleteChildren(NODE* rootfree);

#endif //KEYVALUE_NODE_H
