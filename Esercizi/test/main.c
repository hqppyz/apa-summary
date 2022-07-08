#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

void printLinkKey(link l, int first, int last) {
    if (!first) {
        printf(", ");
    }
    printf("%d", l->key);
}

int main(int argc, char **argv)
{
    // list a = LISTnew(LINKnew(0, LINKnew(10, NULL)));
    list a = LISTnew(NULL);

    list b = LISTnew(LINKnew(3, LINKnew(4, LINKnew(5, NULL))));
    // list b = LISTnew(NULL);

    printf("A: {");
    LISTwalk(a, printLinkKey);
    printf("}\n");

    printf("B: {");
    LISTwalk(b, printLinkKey);
    printf("}\n");

    LISTmerge(a, b);
    printf("A[merged]: {");
    LISTwalk(a, printLinkKey);
    printf("}\n");

    LISTfree(a);
    // free(b); // b punta alla stessa testa di a, liberarla con LISTfree libererebbe la testa due volte

    return 0;
}
