//
// Created by henrik on 11/10/17.
//

#include "node.h"
#include "parser.h"
#include <string.h>

int main(void){

    // Del 1:

    printf("Del 1:\n");

    createNodeTree("data.txt");

    printf("\tSo far so good...\n\n");

    // Del 2:

    printf("Del 2:\n");

    printf("\tGetType(): %d.\n",
           GetType("config.update.interval"));

    printf("\tGetString(): %s\n",
           GetString("strings.no.button_cancel"));

    printf("\tGetInt(): %d\n",
           GetInt("config.update.timeout"));

    printf("\n");

    // Del 3:

    printf("Del 3:\n");

    printf("\tEnumerate(): \n");

    //Enumerate("config.*");

    //Enumerate("strings.no.*");

    printf("\n");

    // Del 4:

    printf("Del 4:\n");

    printf("\tDelete(): ");

    moveconductor("config.update.interval");

    Delete(conductor);

    moveconductor("config.update");

    int ret = childexists(conductor, "interval");

        if (ret < 0)
            printf("Has been deleted\n");
        else
            printf("Was not deleted\n");

    printf("\n");

    // Del 5:

    printf("Del 5:\n");

    printf("\tGetText(): %s\n"
            ,GetText("button_cancel", "no"));
    printf("\tGetText(): %s\n"
            ,GetText("button_cancel", "en"));
/*
    printf("%d\n", typeis);

    typeis = GetType("strings.no.button_cancel");

    printf("%d\n", typeis);

     */

    //printf("\nGetText(): %s\n", GetText("button_cancel", "no"));

    /*
    moveconductor("strings.en.header");
    printf("\n%s\n", conductor->pszName);

    int integer = GetInt("config.update.timeout");
    printf("\n%d!!!\n", integer);

    printf("\nString: %s\n", GetString("strings.en.header"));


    printnodetree(root);
    */

    // Free allocated space.
    freetree(root);


    exit(EXIT_SUCCESS);
}
