#ifndef LISTS_H
#define LISTS_H

#include "lists.h"

#include <stdlib.h>

Link LINKnew(int key, Link next) {
    Link l = malloc(sizeof(struct link_s));
    l->key = key;
    l->next = next;
    return l;
}

void LINKfree(Link head) {
    if (head == NULL) {
        return;
    }

    LINKfree(head->next);
    free(head);
}

int LINKprint(Link link, FILE *stream) {
    if (link == NULL) {
        return fprintf(stream, "[NULL]");
    }
    int cursor = fprintf(stream, "{key: %d, next: ", link->key);
    if (link->next == NULL) {
        return cursor + fprintf(stream, "[NULL]}");
    } else {
        return cursor + fprintf(stream, "%d}", link->next->key);
    }
}

int LINKprettyPrint(Link link, int first, int last) {
    if (first) {
        return printf("%d", link->key);
    }
    return printf(", %d", link->key);
}

Link LINKinvert(Link head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Link child = head->next;
    head->next = child->next;
    child->next = head;
    return LINKinvert(child);
}

void walkR(Link head, int first, int (*visit)(Link, int, int)) {
    if (head == NULL) {
        return;
    }

    visit(head, first, head->next == NULL);
    walkR(head->next, 0, visit);
}

List LISTnew(Link head) {
    List l = malloc(sizeof(struct list_s));
    l->head = head;
    return l;
}

void LISTfree(List list) {
    if (list == NULL) {
        return;
    }

    LINKfree(list->head);
    free(list);
}

Link mergeR(Link a, Link b) {
    if (a == NULL) {
        return b;
    } else if (b == NULL) {
        return a;
    }

    if (a->key <= b->key) {
        a->next = mergeR(a->next, b);
        return a;
    } else {
        b->next = mergeR(a, b->next);
        return b;
    }
}

void LISTwalk(List list, int (*visit)(Link, int, int)) {
    walkR(list->head, 1, visit);
}

// Esercizio 1
void LISTmerge(List a, List b) {
    a->head = mergeR(a->head, b->head);
}

// Esercizio 2
int calculateHeight(List list, Link link) {
    int height = 0;
    for (Link t = list->head; t != NULL; t = t->next) {
        if (t == link) {
            return height;
        }

        ++height;
    }

    return -1;
}

Link LISTgetFirstFolded(List list) {
    int currentHeight = 0;
    for (Link t = list->head; t != NULL; t = t->next) {
        if (t->next == NULL) {
            return NULL;
        }

        ++currentHeight;
        int height = calculateHeight(list, t->next);
        if (height == -1 || height < currentHeight) {
            printf("CurrentHeight: %d, Height of %d: %d\n", currentHeight, t->key, height);
            return t;
        }
    }

    return NULL;
}

void LISTinvert(List list) {
    if (list == NULL || list->head == NULL) {
        return;
    }

    for () {
        // Il current punta al precedente
        // Il precedente punta
    }
    list->head = LINKinvert(list->head);
}

#endif //LISTS_H
