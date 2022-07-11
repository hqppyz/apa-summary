#include "es5.h"

#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

void testListSort(char *name, List list) {
    LISTsort(list);
    printf("%s: {", name);
    LISTwalk(list, LINKprettyPrint);
    printf("}\n");
}

int es5main(int argc, char **argv) {
    testListSort("Lista normale 1, 2, 3, 4", LISTnew(LINKnew(1, LINKnew(2, LINKnew(3, LINKnew(4, NULL))))));
    testListSort("Lista normale 8, 1, 48, -4", LISTnew(LINKnew(8, LINKnew(1, LINKnew(48, LINKnew(-4, NULL))))));

    return 0;
}
