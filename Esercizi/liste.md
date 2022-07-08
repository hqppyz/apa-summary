## Esercizio 1
Date due liste di interi ordinate, fonderle in una lista mantenendo l'ordine

```c
typedef struct list_s *list;

typedef struct link_s *link;

struct list_s {
    link head;
};

struct link_s {
    int key;
    link next;
};

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

void merge(list a, list b) {
    a->root = mergeR(a->root, b->root);
}
```
