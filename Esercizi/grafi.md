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

## Esercizio 2 - Sbagliato
Dato un grafo orientato e non pesato, scrivere una funzione che ritorni un vettore con l'elenco dei vertici distanti al massimo k dal vertice v.

Approccio sbagliato, volevo si può risolvere facendo una findVerticesDR per ogni vertice adiacente alla sorgente ma meglio rifarlo con la BFS.

```c
int findVerticesDR(Graph G, int v, int w, int d, int *count) {
    visited[t->w] = 1;
    ++(*count);

    if (v == w) {
        // Se l'ho trovato, mi fermo
        return 1;
    }

    if (d - 1 <= 0) {
        // Se non posso più continuare, mi fermo
        return 0;
    }

    for (link t = G->ladj[v]; t != NULL; t = t->next) {
        if (!visited[t->w] && findVerticesDR(G, t->w, w, d - 1, distances, count)) {
            return 1;
        }
    }

    return 0;
}

int findVerticesD(Graph G, int v, int d, int **array) {
    if (G->ladj[v] == NULL) {
        return 0;
    }

    int *visited = malloc(G->V * sizeof(int));
    int total = findVerticesDR(G, v, G->ladj[v]->w, visited, 0);

    int i = 0;
    *array = malloc((total - 1) * sizeof(int));
    for (int w = 0; w < G->V; ++w) {
        if (visited[w] && v != w) {
            array[i++] = w;
        }
    }

    return total - 1;
}
```

## Esercizio 2 - Giusto (bfs)
Dato un grafo orientato e non pesato, scrivere una funzione che ritorni un vettore con l'elenco dei vertici distanti al massimo k dal vertice v.
```c
void dfsMaxD(Graph G, Q queue, int *distances, int maxDistance, int *processed) {
    while (Qsize(queue) > 0) {
        int v = Qget(queue);
        if (distances[v] >= maxDistance) {
            return 1;
        }

        for (link t = G->ladj[v]; t != NULL; t = t->next) {
            if (distances[t->w] == -1) {
                distances[t->w] = distances[v] + 1;
                Qput(queue, t->w);
                ++(*processed);
            }
        }
    }
}

int getVerticesNearby(Graph G, int s, int k, int **neighbours) {
    int processed = 0;
    int *distances = malloc(G->V * sizeof(int));
    for (int i = 0; i < G->V; ++i) {
        distances[i] = -1;
    }

    Q queue = Qinit();
    Qput(queue, s);
    distances[s] = 0;
    dfsMaxK(G, queue, distances, k, &processed);

    *neighbours = malloc(processed * sizeof(int));
    int index = 0;
    for (int v = 0; v < G->V; ++v) {
        if (v != s && distances[v] != -1) {
            (*neighbours)[index++] = v;
        }
    }

    free(distances);

    return processed;
}
```
