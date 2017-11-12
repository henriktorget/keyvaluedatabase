//
// Created by henrik on 11/10/17.
//

#include "node.h"
#include "parser.h"
#include <string.h>

int main(void){

    createNodeTree("data.txt");

    int typeis = GetType("config.update.interval");

    printf("%d\n", typeis);

    typeis = GetType("strings.no.button_cancel");

    printf("%d\n", typeis);

    moveconductor("strings.en.header");
    printf("\n%s\n", conductor->pszName);

    int integer = GetInt("config.update.timeout");
    printf("\n%d!!!\n", integer);

    printf("\nString: %s\n", GetString("strings.en.header"));


    printnodetree(root);
    freetree(root);


    exit(EXIT_SUCCESS);
}
