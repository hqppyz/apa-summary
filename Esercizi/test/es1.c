#include "es1.h"

#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

int es1main(int argc, char **argv) {
    // list a = LISTnew(LINKnew(0, LINKnew(10, NULL)));
    List a = LISTnew(NULL);

    List b = LISTnew(LINKnew(3, LINKnew(4, LINKnew(5, NULL))));
    // list b = LISTnew(NULL);

    printf("A: {");
    LISTwalk(a, LINKprettyPrint);
    printf("}\n");

    printf("B: {");
    LISTwalk(b, LINKprettyPrint);
    printf("}\n");

    LISTmerge(a, b);
    printf("A[merged]: {");
    LISTwalk(a, LINKprettyPrint);
    printf("}\n");

    LISTfree(a);
    // free(b); // b punta alla stessa testa di a, liberarla con LISTfree libererebbe la testa due volte

    return 0;
}
