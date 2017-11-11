//
// Created by henrik on 11/10/17.
//

#include "node.h"
#include <string.h>

void createNodeTree(char* filename)
{

}

int childexists(NODE* node, char* childname)
{

    int strcmpVal;
    int emptycount = 0;

    for(int k = 0; k < MAX_NODES; k++){

        // Check if there is a node at this posistion.
        if(node->pnNodes[k] != 0) {

            // Compare name of node with the node you are looking for.
            strcmpVal = strcmp(node->pnNodes[k]->pszName, childname);

            //When it finds a node with the correct name. Return the position to it in the array.
            if (strcmpVal == 0)
                return k;

        }

        else {
            // If there's an empty node in the given node. Count it.
            emptycount++;
        }

    }

    if(emptycount == MAX_NODES){

        // All nodes are empty,
        return -1;

    } else if(emptycount < MAX_NODES){

        // If it went through all nonempty childnodes and there is room for a new one.
        return -2;

    } else if(emptycount == 0) {

        // All nodepointers are full.
        return -3;

    }

    // Sum-ting wong.
    return -4;
}

NODE* createnode(NODE* node, char* childname){

    for(int k = 0; k < MAX_NODES; k++){
        if(node->pnNodes[k] == 0){

            NODE* childnode = (NODE*) malloc(sizeof(NODE));
            childnode->pszName = malloc(sizeof(childname));
            childnode->pszName = childname;

            node->pnNodes[k] = childnode;

            return  node->pnNodes[k];
        }
    }
    return 0;
}

void setNumber(NODE* node, int number)
{

    node->ulIntVal = (ULONG) number;

}

void setString(NODE* node, char* str)
{
    char *nodestring;

    strcpy(nodestring, str);

    node->pszString = nodestring;

}

void printnodetree(NODE* rootprint){


  for(int l = 0; l < MAX_NODES; l++){

    if(rootprint->pnNodes[l] != 0){

        printf("%s ", rootprint->pnNodes[l]->pszName);
        printnodetree(rootprint->pnNodes[l]);

    } else {
        //printf("\n");
        return;
    }
  }

}

void freetree(NODE* rootfree){

    if (rootfree == 0)
        return;

    for(int i = 0; i < MAX_NODES; i++)
        freetree(rootfree->pnNodes[i]);

    free(rootfree);

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