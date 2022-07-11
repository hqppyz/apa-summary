## Esercizio 1
Data una lista di interi singolo puntata del tipo 1->3->10, generare i valori in mezzo 1->2->3->4->5->6->7->8->9->10.
```c
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

void LISTexpand(List list) {
    if (list == NULL || list->head == NULL) {
        return;
    }

    list->head = LINKexpand(list->head);
}
```

## Esercizio 2
Dato un grafo $G$, un vertice $s$, e una lunghezza $k$, trovare i cammini ciclici dal vertice $s$ di lunghezza $k$.
```c
int camminiK(Graph G, int v, int w, int d, int k, int *visited, Edge path[k]) {
    if (d >= k) {
        if (v != w) {
            return 0;
        }

        // [[ PRINT EDGES ]]
        printf("Cammino: {\n");
        for (int i = 0; i < k; ++i) {
            printf("\t(%s => %s) di costo %d\n", path[i]->i);
        }
        printf("}\n");

        return 1;
    }

    visited[v] = 1;
    for (link t = G->ladj[v]; t != NULL; t = t->next) {
        if (!visited[t->w]) {
            path[d] = EDGEcreate(t->v, t->w, t->wt);
            if (camminiK(G, t->w, w, visited, path, d - 1, k)) {
                // Se si ferma era l'ultimo e quindi v, a meno che non fosse un multigrafo non troverò altre soluzioni
                return 1;
            }
        }
    }
    visited[v] = 0;

    return 0;
}

void GRAPHcicliK(Graph G, int s, int k) {
    int *visited = calloc(G->V, sizeof(int));
    Edge path[k];
    camminiK(G, s, s, 0, k, visited, path);
    free(visited);
    free(path);
}
```

## Esercizio 3
Data una lista, cancellare gli elementi dispari (testa = 0).
```c
Link LINKdeleteIf(Link head, int delete) {
    if (head == NULL) {
        return head;
    }

    head->next = LINKdeleteIf(head->next, !delete);
    if (delete) {
        Link next = head->next;
        free(head); // O LINKfree se non ricorre sul next
        return next;
    } else {
        return head;
    }
}

void LISTdeleteOdds(List list) {
    if (list == NULL) {
        return;
    }

    list->head = LINKdeleteIf(list->head, 0);
}
```

## Esercizio 4
Dati due vettori e le loro lunghezze, generare in un nuovo vettore l'intersezione insiemistica degli originali.
```c
int intersect(int *a, int aLength, int *b, int bLength, int **result) {
    // Lungo al massimo min(a, b)
    int min = a <= b ? a : b;
    *result = malloc(min * sizeof(int));

    int len = 0;
    for (int i = 0; i < aLength; ++i) {
        for (int j = 0; j < bLength; ++j) {
            if (a[i] == b[j]) {
                (*result)[len++] = a[i];
                break;
            }
        }
    }

    return len;
}
```

## Esercizio 5
Dati due vettori ordinati e le loro lunghezze, generare in un nuovo vettore l'intersezione insiemistica degli originali.
```c
//               V
// a = [1, 3, 8, 9]
//
//                        V
// b = [1, 2, 3, 6, 7, 8]
//
// r = [1, 3, 8]
int intersect(int *a, int aLength, int *b, int bLength, int **result) {
    int min = a <= b ? a : b;
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
```
