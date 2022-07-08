typedef struct list_s *list;

typedef struct link_s *link;

struct list_s
{
    link head;
};

struct link_s
{
    int key;
    link next;
};

link LINKnew(int key, link next);

void LINKfree(link head);

list LISTnew(link head);

void LISTfree(list list);

void LISTmerge(list a, list b);

void LISTwalk(list list, void (*visit)(link, int, int));
