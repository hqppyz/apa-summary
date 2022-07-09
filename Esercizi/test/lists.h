#ifndef _LISTS_H
#define _LISTS_H

#include <stdio.h>

typedef struct list_s *List;

typedef struct link_s *Link;

struct list_s {
    Link head;
};

struct link_s {
    int key;
    Link next;
};

Link LINKnew(int key, Link next);

void LINKfree(Link head);

int LINKprint(Link link, FILE *stream);

int LINKprettyPrint(Link link, int first, int last);

List LISTnew(Link head);

void LISTfree(List list);

void LISTwalk(List list, int (*visit)(Link, int, int));

void LISTmerge(List a, List b);

Link LISTgetFirstFolded(List list);

#endif // _LISTS_H

