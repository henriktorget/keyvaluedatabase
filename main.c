//
// Created by henrik on 11/10/17.
//

#include "node.h"
#include "parser.h"
#include <string.h>

int main(void){

    createNodeTree("data.txt");

    int typeis = GetType("config.loglevel");

    printf("%d\n", typeis);

    printnodetree(root);
    freetree(root);


    exit(EXIT_SUCCESS);
}
