# Algoritmo di Dijkstra
L'algoritmo di Dijkstra cerca il cammino di peso minore tra partendo dal vertice $s$.

Utilizza un approccio greedy, scegliendo ogni volta l'arco a peso minimo.
<br>Questo permette di ottenere il risultato rilassando una sola volta ogni arco, ma perde di significato quando nel grafo è presente anche solo 1 arco a peso negativo.

**Complessità**:
<br>$O(|V + E| \text{ } log|V|)$
<br>$O(|V|^2 \text{ } log|V|)$

## `Implementazione`
```c
// Shortest Path w/Dijkstra
void GRAPHspD(Graph G, int s) {
    // 1. Inizializzo il vettore e la priority Q. O(1)
    int *st = malloc(G-V * sizeof(int));
    int *d = malloc(G->V * sizeof(int));
    PQ pq = PQinit(G->V);

    // 2. Salvo le distanze iniziali.
    //    Sono θ(V) PQinsert che costano O(log|V|) l'una, ovvero O(|V|log|V|).
    //    Ma posso ipotizzare di riempire già il vettore all'inizio (ovvero θ(|V))
    //    e poi inserirle tutte con la HEAPbuild, che costa O(|V|).
    //    Quindi in realtà il costo di questo passaggio è: O(|V|)
    st[s] = s;
    d[s] = 0;
    PQinsert(pq, d, s);
    for (int v = 0; v < G->V; ++v) {
        if (v == s) {
            continue;
        }

        st[v] = -1;
        d[v] = INT_MAX;
        PQinsert(pq, d, v);
    }

    // 3. Per ogni vertice: θ(|V|)
    while (PQsize(pq) > 0) {
        // Estraggo il vertice a distanza minore: O(log|V|)
        int v = PQextractMin(pq, d);
        if (d[v] == INT_MAX) {
            // Non è ancora stato processato, non lo saranno nemmeno quelli dopo di lui, posso interrompe il ciclo
            break;
        }

        // Per ogni arco del vertice: O(|E|) (che diventa θ(|E|) in tutto)
        for (link t = G->ladj[v]; t != NULL; t = t->next) {
            // Rilassamento:
            // Se il cammino è minore del cammino stimato
            if (d[v] + t->wt < d[t->w]) {
                // Sostituiscilo: O(log|V|)
                st[t->w] = v;
                d[t->w] = d[v] + t->wt;
                PQchange(pq, d, t->w);
            }
        }
    }

    // 4. Pulisco
    free(st);
    free(d);
    PQfree(pq);
}
```

## Analisi di Complessità
| | Passo | | Costo |
| -: | - | -: | - |
| $1.$ | Inizializzo || $O(\lvert\text{V}\rvert)$ |
| $2.$ | Per ogni vertice: || $\theta(\lvert\text{V}\rvert)$ |
| $2.1$ | Estraggo il vertice || $O(log\lvert\text{V}\rvert)$ |
| $2.2$ | Per ogni arco del vertice: | *ladj*<br>*madj* | $\theta(\lvert\text{E}\rvert)$<br>$\theta(\lvert\text{V}\rvert)$ |
| $2.2.1$ | Se minore, sostituisco || $O(log\lvert\text{V}\rvert)$ |
|||||
||| *ladj*<br>*madj* | $\boldsymbol{O(\lvert\text{V + E}\rvert \text{ } log\lvert\text{V}\rvert)}$<br>$\boldsymbol{O(\lvert\text{V}\rvert^2 \text{ } log\lvert\text{V}\rvert)}$ |
