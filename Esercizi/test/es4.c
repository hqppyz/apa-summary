#include "es4.h"

#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

void testListInvert(char *name, List list) {
    LISTinvert(list);
    printf("%s: {", name);
    LISTwalk(list, LINKprettyPrint);
    printf("}\n");
}

int es4main(int argc, char **argv) {
    testListInvert("Lista normale 1, 2, 3, 4", LISTnew(LINKnew(1, LINKnew(2, LINKnew(3, LINKnew(4, NULL))))));

    return 0;
}
