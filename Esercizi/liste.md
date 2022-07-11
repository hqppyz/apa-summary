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

## Esercizio 2
Data una lista linkata, scrivere una funzione che verifichi se si ripiega su se stessa, e ritorni il nodo in questione, altrimenti NULL.

```c
int calculateHeight(Node root, Node node) {
    int height = 0;
    for (link t = root; t != NULL; t = t->next) {
        if (t == node) {
            return height;
        }

        ++height;
    }

    return -1;
}

Node getFoldedNode(Node root) {
    int currentHeight = 0;
    for (link t = root; t != NULL; t = t->next) {
        ++currentHeight;

        int height = calculateHeight(root, t->next);
        if (height == -1 || height < currentHeight) {
            return t;
        }
    }

    return NULL;
}
```

## Esercizio 3
Data una lista linkata (o doppiamente linkata) ordinarla.
```c
typedef struct list_s *list;

typedef struct link_s *link;

struct list_s {
    link head;
}

struct link_s {
    int value;
    link next;
}

void LISTsort(List list) {
    if (list == NULL || list->head == NULL) {
        return;
    }

    // Bubble Sort
    int ordered;
    do {
        ordered = 1;
        for (link t = list->head; t != NULL; t = t->next) {
            if (t->next == NULL) {
                break;
            }

            if (t->value > t->next->value) {
                ordered = 0;

                int tmp = t->value;
                t->value = t->next->value;
                t->next->value = tmp;
            }
        }
    } while(!ordered);
}
```
