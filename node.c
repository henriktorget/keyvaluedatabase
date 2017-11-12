//
// Created by henrik
//

#include "node.h"
#include "parser.h"

void CreateNodeTree(char* filename)
{
    // Create initial root node, name it.
    root = (NODE*) malloc(sizeof(NODE));
    root->pszName = (char*) "root";

    size_t len = 0;
    ssize_t read;

    // Open file read only
    f = fopen(filename, "r");
    if (f == 0)
        exit(EXIT_FAILURE);

    // Read it string by string.
    while((read = getline(&line, &len, f)) != -1) {


        str = line;



//        for( i = 0, token = strtok(0, "="); ; i++, str = 0){

        for( i = 0, token = str; ; i++, str = 0){
            // Break lines up into commands and parameters by splitting at '='.

            token = strtok_r(str, "=", &saveptr2);

            if(token == 0)
                break;

            // Trim string whitespace around '='

            token = TrimWhitespace(token);

            // Token is on the left side of '='
            if(i == 0){

                // Traverse list of nodes based on name.
                // When this loop is finished, the conductor is set to the last node in
                // 'token'

                for(j = 0, path = token; ; j++, path = 0){


                    nodename = strtok_r(path, ".", &saveptr);

                    // No more directions left in token.
                    if(nodename == 0)
                        break;

                    //If this is the first time this for loop runs,
                    //it should start at root.
                    if(j == 0){
                        conductor = root;
                    }

                    // See if child exists, returns position where in array if it does.
                    // If number is negative it needs to do things accordingly.
                    nodecheck = ChildExists(conductor, nodename);

                    if(nodecheck >= 0 ){

                        // Node exists return position in array.
                        conductor = conductor->pnNodes[nodecheck];

                    } else if(nodecheck == -1){
                        // All nodepointers are empty. Create a new one.
                        //printf("Node '%s' not found in '%s', creating it.\n", nodename,
                        //        conductor->pszName);

                        conductor = CreateNode(conductor, nodename);

                    } else if(nodecheck == -2){
                        //Cant find node. Create new node. With name. Move conductor to it.
                        conductor = CreateNode(conductor, nodename);

                    } else if(nodecheck == -3) {

                        //Child does not exist. Node is full..
                        printf("Node '%s' is full of children. You should turn some of them up for adoption.",
                               conductor->pszName);
                        exit(EXIT_FAILURE);

                    }

                }


            } else if( i == 1){

                // At this point, the conductor is positioned at a leaf, ready to assign values.

                nodearg = calloc(1, sizeof(token));
                strcpy(nodearg, token);

                // Check if nodearg is a number. Returns 1 if number, returns 0 if string.
                type = IsNumber(nodearg);

                if(type == 1) {

                    // String to ULONG
                    ULONG ulong = strtoul(nodearg, 0, 10);

                    SetNumber(conductor, ulong);

                }
                else if(type == 0) {

                    SetString(conductor, nodearg);

                }

                else
                    printf("Value is considered neither string or numeric.\n");

            } else {
                printf("Parsing error. More than one '='?\n");
                exit(EXIT_FAILURE);
            }

        } // end for each line

    } // end of while read getline()


    free(str);
    free(line);

    // Done with file. Close it.
    fclose(f);

}

int ChildExists(NODE* node, char* childname)
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

        } else {
            // If there's an empty node in the given node. Count it.
            emptycount++;
        }

    }


    if(emptycount == MAX_NODES) {
        // All nodes are empty
        return -1;

    } else if(emptycount == 0){

        return -3;

    }
    else if(emptycount < MAX_NODES){

        // If it went through all nonempty childnodes and there is room for a new one.
        return -2;

    }
    //else if(emptycount == 0) {

        // All nodepointers are full.
      //  return -3;

    //}

    // Sum-ting wong.
    return -4;
}

int IsEmpty(NODE* node){

    int emptycount = 0;

    for (int i = 0; i < MAX_NODES; i++) {

        if (node->pnNodes[i] != 0) {

            emptycount++;

        }
    }

    if(emptycount == 0)
        return 1;
    else
        return 0;
}

/*int moveone(char* str){

    int childExistsReturnVal = 0;
    childExistsReturnVal = childexists(conductor, str);

    if (childExistsReturnVal >= 0)
    {
        conductor = conductor->pnNodes[childExistsReturnVal];
        return 1;
    }
    else if(childExistsReturnVal < 0) {
        return childExistsReturnVal;
    }

    return;

};
 */

int MoveConductor(char* str){

    char *nodename, *savept, *parser;
    int nodepos;


    conductor = root;

    parser = malloc(sizeof(str));
    strcpy(parser, str);

    for(int m = 0; ; m++, parser = 0)
    {

        nodename = strtok_r(parser, ".", &savept);

        if(nodename == 0)
            break;

        if(*nodename == '*')
            return -1;

        nodepos = ChildExists(conductor, nodename);

        if(nodepos >= 0){
            conductor = conductor->pnNodes[nodepos];
            //printf("Conductor: %s\n", conductor->pszName);
        } else if (nodename < 0) {
            printf("Nodepos returned %d\n", nodepos);
        }
    }

}

NODE* CreateNode(NODE* node, char* childname){

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


void Delete(char* nodename){

    if(strcmp(nodename, (char*) "root") == 0){
        conductor = root;
        DeleteChildren(root);
        root = 0;
        return;
    }

    int childpos = ChildExists(conductor, nodename);

    if(childpos >= 0){
        free(conductor->pnNodes[childpos]);

    }

    if(!IsEmpty(conductor->pnNodes[childpos])){
        DeleteChildren(conductor->pnNodes[childpos]);
    } else{
        //free(conductor->pnNodes[childpos]);
        conductor->pnNodes[childpos] = 0;
    }

    /*
    if (!is_empty(conductor)) {
        if (childpos >= 0) {
            free(conductor->pnNodes[childpos]);
            conductor->pnNodes[childpos] = 0;
        }
    }*/

}

void SetNumber(NODE* node, ULONG number)
{

    node->ulIntVal = number;

}

void SetString(NODE* node, char* str)
{
    char *nodestring;

    strcpy(nodestring, str);

    node->pszString = nodestring;

}

int HasType(NODE* node){

    if(node->ulIntVal != 0 || node->pszString != 0){
        return 1;
    } else {
        return 0;
    }
}

int GetType(char* string)
{

    MoveConductor(string);

    if(HasType(conductor)) {

        if (conductor->ulIntVal != 0)
            return 1;

        else if (conductor->pszString != 0)
            return 0;

    }

    else
        return -1;
}

int GetInt(char* str){

    MoveConductor(str);

    return (int) conductor->ulIntVal;


}

char* GetString(char* str){
    MoveConductor(str);

    return conductor->pszString;
}

void Enumerate(char* str){

    if (MoveConductor(str) == -1){

        // Conductor is at asterix.
        // This position/folder should not have a value assigned
        if (HasType(conductor) == 0) {

            for(int i = 0; i < MAX_NODES; i++) {
                if (conductor->pnNodes[i] != 0) {
                    //Does it have a stringvalue?
                    if (conductor->pnNodes[i]->pszString != 0) {

                        printf("%s: ", conductor->pnNodes[i]->pszName);
                        printf("%s\n", conductor->pnNodes[i]->pszString);

                    }
                    //Or does it have an int? If neither, dont print because its a folder.
                    else if (conductor->pnNodes[i]->ulIntVal != 0) {

                        printf("%s: ", conductor->pnNodes[i]->pszName);
                        printf("%lu\n", conductor->pnNodes[i]->ulIntVal);

                    }

                }

            }

        }

    }

}

char* GetText(char* string, char* lang){
    MoveConductor("strings");

    int childpos = ChildExists(conductor, lang);
    //printf("childpos: %d\n", childpos);

    if (childpos >= 0){
        conductor = conductor->pnNodes[childpos];
        childpos = ChildExists(conductor, string);
        if(childpos >= 0){
            conductor = conductor->pnNodes[childpos];
        }
        return conductor->pszString;
    } else {
        printf("ChildExists() returned: %d \n", childpos);
    }


}

void PrintNodeTree(NODE* rootprint){


  for(int l = 0; l < MAX_NODES; l++){

    if(rootprint->pnNodes[l] != 0){

        printf("%s ", rootprint->pnNodes[l]->pszName);
        PrintNodeTree(rootprint->pnNodes[l]);

    } else {
        //printf("\n");
        return;
    }
  }

}


void DeleteChildren(NODE* rootfree) {

    if (rootfree == 0)
        return;

    for (int i = 0; i < MAX_NODES; i++) {
        if (rootfree->pnNodes[i] != 0) {
            DeleteChildren(rootfree->pnNodes[i]);
            free(rootfree->pnNodes[i]);
            rootfree->pnNodes[i] = 0;
        }
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