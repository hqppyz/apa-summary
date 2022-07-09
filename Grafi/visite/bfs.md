# BFS: Visita in Ampiezza

## `Implementazione`
`Wrapper`
```c
void GRAPHbfs(Graph G, int s) {
    int time = 0;
    int *pre = malloc(G->V * sizeof(int));
    int *st = malloc(G->V * sizeof(int));
    int *dist = malloc(G->V * sizeof(int));
    for (int v = 0; v < G->V; ++v) {
        pre[v] = st[v] = dist[v] = -1;
    }

    Q queue = Qinit();
    Qput(queue, s);
    pre[s] = time++;
    dist[s] = 0;

    bfs(G, queue, pre, st, dist, time);

    free(pre);
    free(st);
    Qfree(queue);
}
```

`bfs`
```c
void bfs(Graph G, Q queue, int *pre, int *st, int *dist, int time) {
    while (Qsize(queue) > 0) {
        int v = Qget(queue);
        for (link t = G->ladj[v]; t != NULL; t = t->next) {
            if (pre[t->w] == -1) {
                pre[t->w] = time++;
                st[t->w] = v;
                dist[t->w] = dist[t->v] + 1;
                Qput(queue, t->w);
            }
        }
    }
}
```

## Analisi di Complessità
Operazioni sulla coda: $O(1)$
<br>Parto da v e vedo analizzo ogni vertice adiacente:
<br>Matrice delle adiacenze: $\theta(|V|^2)$
<br>Lista delle adiacenze: $\theta(|V| + |E|)$
