//
// Created by henrik on 11/10/17.
//

#include "node.h"
#include "parser.h"
#include <string.h>

FILE *f;

char  *str, *token, *path, *nodename, *nodearg;

char *saveptr1, *saveptr2;

//char **folders;

int i, j, nodecheck, type;

char *line;
size_t len = 0;
ssize_t read;

NODE *root;

NODE *conductor;


int main(void){

    // Create initial root node, name it.
    root = (NODE*) malloc(sizeof(NODE));
    root->pszName = (char*) "root";

    createNodeTree("data.txt");

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
                printf("%s.", token);

                //printf("\n\tLeft side of '='\n");

                //printf("%s\n", token);

                //folders = splitInPeriod(token);

                // Traverse list of nodes based on name.
                // When this loop is finished, the conductor is set to the last node in
                // 'token'

                path = calloc(1, sizeof(token));
                strcpy(path, token);


                for(j = 0; ; j++, path = 0){

                    nodename = strtok_r(path, ".", &saveptr2);

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

                printf("\n\tRight side of '='\n");

                nodearg = calloc(1, sizeof(token));
                strcpy(nodearg, token);

                printf("%s\n", nodearg);

                // Check if nodearg is in quotationmarks. Returns 1 if number, returns 0 if string.
                type = isNumber(nodearg);

                if(type == 1) {
                    //printf("Is number\n");
                    setNumber(conductor, atoi(nodearg));
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


    printnodetree(root);

    freetree(root);


    free(str);
    free(line);
    fclose(f);

    exit(EXIT_SUCCESS);
}
