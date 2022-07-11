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
void bfsMaxD(Graph G, Q queue, int *distances, int maxDistance, int *processed) {
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
    bfsMaxK(G, queue, distances, k, &processed);

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

## Esercizio 3
Dato un grafo $G$ e un vertice $s$, ricercare tutti i cammini di lunghezza $k$.
```c
void bfsK(Graph G, Q queue, int *distances, int k) {
    while (Qsize(queue) > 0) {
        int v = Qget(queue);
        if (distances[v] >= k) {
            return;
        }

        for (link t = G->ladj[v]; t != NULL; t = t->next) {
            if (distances[t->w] == -1) {
                distances[t->w] = distances[v] + 1;
                Qput(t->w);
            }
        }
    }
}

int GRAPHpathK(Graph G, int s, int k) {
    int *distances = malloc(G->V, sizeof(int));
    for (int v = 0; v < G->V; ++v) {
        distances[v] = -1;
    }
    Q queue = Qinit();

    // s
    distances[s] = 0;
    Qput(queue, s);

    bfsK(G, Q, distances, k);

    for (int v = 0; v < G->V; ++v) {
        if (distances[s] == k) {
            printf("%s dista %d da %s.\n", STsearchByIndex(G->tab, v), k, STsearchByIndex(G->tab, s));
        }
    }

    free(distances);
    Qfree(queue);
}
```

## Esercizio 4
Dato un grafo $G$, determinare se è bipartito.
<br>Bipartito: esiste una partizione di $2$ blocchi tali che ogni vertice di una partizione è collegato solo a vertici dell'altra partizione.
<br>Secondo una ricerca di google, sembra che debba essere collegato *almeno* ad un altro vertice.

```c
int erSpecific(int level, Graph G, int *soluzione, int m, int k) {
    if (level >= G->V) {
        if (m != k) {
            return 0;
        }

        // Controllo se ogni vertice ha una partizione verso l'altra partizione
        for (int v = 0; v < G->V; ++v) {
            // Google dice che se almeno 1 vertice non ha archi allora non è bipartito
            if (G->ladj[v] == NULL) {
                return 0;
            }

            for (link t = G->ladj[v]; t != NULL; t = t->next) {
                if (soluzione[v] == soluzione[t->w]) {
                    // I vertici appartengono alla stessa partizione
                    return 0;
                }
            }
        }

        return 1;
    }

    for (int i = 0; i < m; ++i) {
        soluzione[level] = i;
        if (erSpecific(level + 1, G, soluzione, m, k)) {
            return 1;
        }
    }

    soluzione[level] = m;
    if (erSpecific(level + 1, G, soluzione, m + 1, k)) {
        return 1;
    }
}

int GRAPHbipartito(Graph G) {
    // Uso l'algoritmo di Er per partizionare in 2 blocchi il grafo, e poi controllo gli archi con backtrack.

    int *soluzione = malloc(G->V * sizeof(int));
    int result = erSpecific(0, G, soluzione, 0, 2);
    free(soluzione);
    return result;
}
```

## Esercizio 4
Dato un grafo $G$, trovare tutti i cicli semplici di lunghezza $k$.
```c
int camminoK(Graph G, int v, int w, int *visited, int d) {
    // Se ho raggiunto v
    if (v == w) {
        // La soluzione è corretta solo se è di distanza k (ergo d = 0)
        return d == 0;
    }

    // Se non è corretto il cammino ma non posso più andare altrove, mi fermo
    if (d == 0) {
        return 0;
    }

    visited[v] = 1;
    for (link t = G->ladj[v]; t != NULL; t = t->next) {
        if (!visited[t->w] && camminoK(G, t->w, w, visited, d - 1)) {
            // [[ PRINT ]] stampo l'arco, perché parte della soluzione
            return 1;
        }
    }
    visited[v] = 0;

    return 0;
}

void GRAPHcicliK(Graph G, int k) {
    // Faccio un cammino di lunghezza k da ogni vertice
    int *visited = malloc(G->V * sizeof(int));
    for (int v = 0; v < G->V; ++v) {
        for (int i = 0; i < G->V; ++i) {
            visited[i] = 0;
        }

        camminoK(G, v, v, visited, k);
    }
}
```
