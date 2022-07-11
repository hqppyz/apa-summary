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

//Link LINKinvert(Link head) {
//    if (head == NULL || head->next == NULL) {
//        return head;
//    }
//
//    Link child = head->next;
//    head->next = child->next;
//    child->next = head;
//    return LINKinvert(child);
//}

Link LINKinvert(Link head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Link last = LINKinvert(head->next);
    head->next->next = head;
    return last;
}

Link LINKexpand(Link head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    if (head->key + 1 < head->next->key) {
        head->next = LINKnew(head->key + 1, head->next);
    }

    head->next = LINKexpand(head->next);
    return head;
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

Link LINKinvertWalter(Link head) {
    Link padre = head;
    Link figlio = head->next;
    head->next = NULL;

    Link current = figlio;
    while (current->next != NULL) {
        current = current->next;
        figlio->next = padre;
        padre = figlio;
        figlio = current;
    }

    current->next = padre;
    return current;
}

Link LINKinvertNuova(Link head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Link padre = head;
    Link figlio = head->next;
    // Finché esistono figli può continuare
    while (figlio != NULL) {
        Link nipote = figlio->next;

        // Il figlio deve puntare al padre
        figlio->next = padre;

        // Aggiorno il padre
        padre = figlio;

        // E continuo col nuovo figlio
        figlio = nipote;
    }

    // Aggiorno la vecchia testa, che ora sarà l'ultimo valore
    head->next = NULL;

    // E ritorno l'ultimo figlio (che in questo momento è nullo quindi ritorno il precedente ovvero il padre)
    return padre;
}

void LISTinvert(List list) {
    // Nuova
    list->head = LINKinvertNuova(list->head);

    // Walter
//    list->head = LINKinvertWalter(list->head);

    // Mia
//    if (list->head == NULL) {
//        return;
//    }
//
//    Link previousHead = list->head;
//    list->head = LINKinvert(list->head);
//    previousHead->next = NULL;
}

void LISTsort(List list) {
    if (list == NULL || list->head == NULL) {
        return;
    }

    // Bubble Sort
    int ordered;
    do {
        ordered = 1;
        for (Link t = list->head; t != NULL; t = t->next) {
            if (t->next == NULL) {
                break;
            }

            if (t->key > t->next->key) {
                ordered = 0;

                int tmp = t->key;
                t->key = t->next->key;
                t->next->key = tmp;
            }
        }
    } while (!ordered);
}

void LISTexpand(List list) {
    if (list == NULL || list->head == NULL) {
        return;
    }

    list->head = LINKexpand(list->head);
}

Link LINKdeleteIf(Link head, int delete) {
    if (head == NULL) {
        return head;
    }

    head->next = LINKdeleteIf(head->next, !delete);
    if (delete) {
        Link next = head->next;
        free(head);
        return next;
    } else {
        return head;
    }
}

Link LINKdeleteOdds(Link head) {
    int deleteNext = 1;
    for (Link t = head; t != NULL && t->next != NULL; t = t->next) {
        if (deleteNext) {
            Link child = t->next;
            t->next = child->next;
            free(child);
        }

        deleteNext = !deleteNext;
    }

    return head;
}

void LISTdeleteOdds(List list) {
    if (list == NULL) {
        return;
    }

    list->head = LINKdeleteOdds(list->head);
}

#endif //LISTS_H
