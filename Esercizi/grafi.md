## Esercizio 1
Dato un grafo non orientato, e due nodi, trovare, se esiste, un cammino che li connette di lunghezza pari a 3.

```c
int camminoSempliceDR(Graph G, int v, int w, int d) {
    // Ho raggiunto w
    if (v == w) {
        return d == 0;
    }

    visited[v] = 1;
    for (link t = G->ladj[v]; t != NULL; t = t->next) {
        if (!visited[t->w] && camminoSempliceDR(G, t->w, w, d - 1, visited)) {
            return 1;
        }
    }
    visited[v] = 0;

    return 0;
}

// d = 3
int camminoSempliceD(Graph G, int v, int w, int d) {
    int *visited = calloc(d, sizeof(int));
    result = camminoSempliceDR(G, v, w, d, visited);
    free(visited);
    return result;
}
```
