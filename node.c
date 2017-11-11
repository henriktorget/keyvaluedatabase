//
// Created by henrik on 11/10/17.
//

#include "node.h"
#include "parser.h"

void createNodeTree(char* filename)
{
    // Create initial root node, name it.
    root = (NODE*) malloc(sizeof(NODE));
    root->pszName = (char*) "root";

    size_t len = 0;
    ssize_t read;

    // Open file read only
    f = fopen("data.txt", "r");
    if (f == 0)
        exit(EXIT_FAILURE);

    // Read it string by string.
    while((read = getline(&line, &len, f)) != -1) {


        str = line;


        for(i = 0, token = strtok(0, "="); ; i++, str = 0){

            // Break lines up into commands and parameters by splitting at '='.

            token = strtok(str, "=");

            if(token == 0)
                break;

            // Trim string whitespace around '='

            token = trimwhitespace(token);

            // Token is on the left side of '='
            if(i == 0){
                //printf("%s.", token);

                //printf("\n\tLeft side of '='\n");

                // Traverse list of nodes based on name.
                // When this loop is finished, the conductor is set to the last node in
                // 'token'

                //path = calloc(1, sizeof(token));
                //strcpy(path, token);

                //path = token;

                for(j = 0, path = token; ; j++, path = 0){


                    nodename = strtok_r(path, ".", &saveptr);

                    //printf("path %s\n", path);

                    // No more directions left in token.
                    if(nodename == 0)
                        break;

                    //printf("nodename %s\n", nodename);
                    //If this is the first time this for loop runs,
                    //it should start at root.
                    if(j == 0){
                        conductor = root;
                    }

                    // See if child exists, returns position where in array if it does.
                    // If number is negative it needs to do things accordingly.
                    nodecheck = childexists(conductor, nodename);

                    if(nodecheck >= 0 ){

                        // Node exists return position in array.
                        conductor = conductor->pnNodes[nodecheck];

                    } else if(nodecheck == -1){
                        // All nodepointers are empty. Create a new one.
                        //printf("Node '%s' not found in '%s', creating it.\n", nodename,
                        //        conductor->pszName);

                        conductor = createnode(conductor, nodename);

                    } else if(nodecheck == -2){
                        //Cant find node. Create new node. With name. Move conductor to it.
                        conductor = createnode(conductor, nodename);

                    } else if(nodecheck == -3)

                        //Child does not exist. Node is full..
                        printf("Node '%s' is full of children. You should turn some of them in for adoption.",
                               conductor->pszName);

                }


            } else if( i == 1){

                // At this point, the conductor is positioned at a leaf.

                //printf("\n\tRight side of '='\n");

                nodearg = calloc(1, sizeof(token));
                strcpy(nodearg, token);

                //printf("%s\n", nodearg);

                // Check if nodearg is in quotationmarks. Returns 1 if number, returns 0 if string.
                type = isNumber(nodearg);

                if(type == 1) {
                    //printf("Is number\n");
                    ULONG ulong = (ULONG) atoi(nodearg);
                    setNumber(conductor, ulong);
                    //printf("Number is stored as: %lu \n", conductor->ulIntVal);

                }
                else if(type == 0) {

                    //printf("Is string\n");
                    setString(conductor, nodearg);
                    //printf("String is stored as: %s\n", conductor->pszString);
                }

                else
                    printf("Whoooops");

            } else {
                printf("Error: Sum-ting wong.");
                exit(EXIT_FAILURE);
            }

        } // end for each line
    } // end of while read getline()


    free(str);
    free(line);

    fclose(f);

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

            //Allocate/create new node.
            NODE* childnode = (NODE*) malloc(sizeof(NODE));
            //Make room for name.
            childnode->pszName = malloc(sizeof(childname));
            //Move name.
            strcpy(childnode->pszName, childname);
            //Place at free position.
            node->pnNodes[k] = childnode;

            return  node->pnNodes[k];
        }
    }
    return 0;
}

void setNumber(NODE* node, ULONG number)
{

    node->ulIntVal = number;

}

void setString(NODE* node, char* str)
{
    char *nodestring;

    strcpy(nodestring, str);

    node->pszString = nodestring;

}

int GetType(char* string)
{
    char *nodenames, *savert, *parsers;
    int nodepos;


    conductor = root;

    parsers = malloc(sizeof(string));
    strcpy(parsers, string);

    for(int m = 0; ; m++, parsers = 0)
    {

        nodenames = strtok_r(parsers, ".", &savert);

        if(nodenames == 0)
            break;

        nodepos = childexists(conductor, nodenames);

        if(nodepos >= 0){
            conductor = conductor->pnNodes[nodepos];
            printf("Conductor: %s\n", conductor->pszName);
        } else if (nodename < 0) {
            printf("Nodepos returned %d\n", nodepos);
        }
    }

    printf("Int = %lu \n", conductor->ulIntVal);
    printf("String = %s \n", conductor->pszString);

    if(conductor->ulIntVal != 0)
        return 1;

    else if(conductor->pszString != 0)
        return 0;
    else
        return -1;
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