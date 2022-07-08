#ifndef LISTS_H
#define LISTS_H

#include "lists.h"

#include <stdlib.h>

link LINKnew(int key, link next) {
    link l = malloc(sizeof(struct link_s));
    l->key = key;
    l->next = next;
    return l;
}

void LINKfree(link head) {
    if (head == NULL) {
        return;
    }

    LINKfree(head->next);
    free(head);
}

void walkR(link head, int first, void (*visit)(link, int, int)) {
    if (head == NULL) {
        return;
    }

    visit(head, first, head->next == NULL);
    walkR(head->next, 0, visit);
}

list LISTnew(link head) {
    list l = malloc(sizeof(struct list_s));
    l->head = head;
    return l;
}

void LISTfree(list list) {
    if (list == NULL) {
        return;
    }

    LINKfree(list->head);
    free(list);
}

link mergeR(link a, link b) {
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

void LISTmerge(list a, list b) {
    a->head = mergeR(a->head, b->head);
}

void LISTwalk(list list, void (*visit)(link, int, int)) {
    walkR(list->head, 1, visit);
}

#endif //LISTS_H
