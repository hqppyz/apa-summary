#include "es6.h"

#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

void testListExpand(char *name, List list) {
    LISTexpand(list);
    printf("%s: {", name);
    LISTwalk(list, LINKprettyPrint);
    printf("}\n");
}

void testListDeleteOdds(char *name, List list) {
    LISTdeleteOdds(list);
    printf("%s: {", name);
    LISTwalk(list, LINKprettyPrint);
    printf("}\n");
}

//               V
// a = [1, 3, 8, 9]
//
//                        V
// b = [1, 2, 3, 6, 7, 8]
//
// r = [1, 3, 8]
int intersect(const int *a, int aLength, const int *b, int bLength, int **result) {
    int min = aLength <= bLength ? aLength : bLength;
    *result = malloc(min * sizeof(int));
    int aIndex = 0;
    int bIndex = 0;
    int len = 0;
    while (aIndex < aLength && bIndex < bLength) {
        int compare = a[aIndex] - b[bIndex];
        if (compare == 0) {
            (*result)[len++] = a[aIndex];

            ++aIndex;
            ++bIndex;
        } else if (compare < 0) {
            ++aIndex;
        } else {
            ++bIndex;
        }
    }
    return len;
}

void printVec1(char *name, int *vector, int length) {
    printf("%s: [", name);
    for (int i = 0; i < length; ++i) {
        if (i != 0) {
            printf(", ");
        }
        printf("%d", vector[i]);
    }
    printf("]\n");
}

// Data una lista di interi singolo puntata del tipo 1->3->10, generare i valori in mezzo 1->2->3->4->5->6->7->8->9->10.
int es6main(int argc, char **argv) {
//    testListExpand("Lista normale 1, 3, 10", LISTnew(LINKnew(1, LINKnew(3, LINKnew(10, NULL)))));
//    testListDeleteOdds("Lista normale 1, 2, 3, 4, 5", LISTnew(LINKnew(1, LINKnew(2, LINKnew(3, LINKnew(4, LINKnew(5, NULL)))))));
//    testListDeleteOdds("Lista normale 1, 2, 3, 4, 5, 6", LISTnew(LINKnew(1, LINKnew(2, LINKnew(3, LINKnew(4, LINKnew(5,
//LINKnew(6, NULL))))))));

//// a = [1, 3, 8, 9]
////
////                        V
//// b = [1, 2, 3, 6, 7, 8]
////
//// r = [1, 3, 8]
    int A[] = {1, 3, 8, 9};
    int aLength = sizeof(A) / sizeof(A[0]);
    printVec1("a", A, aLength);
    int B[] = {1, 2, 3, 6, 7, 8};
    int bLength = sizeof(B) / sizeof(B[0]);
    printVec1("b", B, bLength);

    int *R;
    int rLength = intersect(A, aLength, B, bLength, &R);
    printVec1("r", R, rLength);

    return 0;
}
