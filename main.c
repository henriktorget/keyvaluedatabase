//
//      Skrevet av Henrik Torget
// Eksamen i programmering i c på linux.
// Jeg har valgt å bruke lønsning B.
//

#include "node.h"

int main(void){

/**
 *  Jeg har laget eksempler med alle funnksjoner som er i oppgaven.
 *  Kjør CreateNodeTree() med egene tekstfiler om du har tester
 *  liggende så lenge du legger de på samme sted som data.txt.
 */

    // Del 1:

    printf("Del 1:\n");

    CreateNodeTree("data.txt");

    printf("\tSo far so good...\n\n");

    // Del 2:

    printf("Del 2:\n");

    printf("\tGetType(): %d\n",
           GetType("config.update.interval"));

    printf("\tGetString(): %s\n",
           GetString("strings.no.button_cancel"));

    printf("\tGetInt(): %d\n",
           GetInt("config.update.interval"));

    printf("\n");

    // Del 3:

    printf("Del 3:\n");

    printf("\tEnumerate(): \n");

    Enumerate("config.update.*");

    //Enumerate("strings.en.*");

    //Enumerate("strings.no.*");

    printf("\n\n");

    // Del 4:

    printf("Del 4:\n");

    printf("\tDelete(): ");

    MoveConductor("config.update");

    Delete("interval");

    int ret = ChildExists(conductor, "interval");

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

    //List to visualize if nodes has been deleted.
    //PrintNodeTree(root);

    // Free allocated space.
    Delete("root");

    exit(EXIT_SUCCESS);
}
