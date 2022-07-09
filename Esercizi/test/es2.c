#include "es2.h"

#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

void test(char *name, List list, int prettyPrint) {
    printf("Testing '%s'...", name);
    if (prettyPrint) {
        printf(" {");
        LISTwalk(list, LINKprettyPrint);
        printf("}");
    }
    printf("\n");

	Link foldedLink = LISTgetFirstFolded(list);
    printf("FoldedLink: ");
    LINKprint(foldedLink, stdout);
    printf("\n\n");

    LISTfree(list);
}

int es2main(int argc, char **argv) {
	test("Empty List", LISTnew(NULL), 1);
    test("Only head list", LISTnew(
            LINKnew(1, NULL)
    ), 1);
    test("Non-folding list", LISTnew(
            LINKnew(1,
                    LINKnew(2,
                            LINKnew(3, NULL)
                    )
            )
    ), 1);

    Link secondLink = LINKnew(2, LINKnew(3, NULL));
    secondLink->next->next = LINKnew(4, secondLink);
    test("Folding list", LISTnew(LINKnew(1, secondLink)), 0);

    return 0;
}
