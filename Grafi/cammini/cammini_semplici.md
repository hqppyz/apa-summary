<!-- # Cammino -->
<!-- Un cammino è un percorso che collega 2 vertici in un grafo. -->

# Cammino Semplice
Un cammino semplice è il percorso che collega 2 vertici v e w senza restrizioni sugli archi da usare, ma passando da ogni vertice al massimo 1 volta.

**Complessità**:
<br>$O(|V| + |E|)$

## `Wrapper`
```c
int camminoSemplice(GraphG G, int v, int w) {
    int *visited = calloc(G->V, sizeof(int));
    int result = camminoSempliceR(G, v, w, visited);
    free(visited);

    return result;
}
```

## `Ricorsiva`
```c
int camminoSempliceR(Graph G, int v, int w, int *visited) {
    // Se sono tornato su w, ho finito il cammino
    if (v == w) {
        return 1;
    }

    // Visito v
    visited[v] = 1;

    // Per ogni vertice adiacente a v
    for (link t = G->ladj[v]; t != NULL; t = t->next) {
        // Se w non è stato visitato, provo a proseguire il cammino verso w
        // Se il cammino è corretto, allora non ho bisogno di controllarne altri
        if (!visited[t->w] && camminoSempliceR(G, t->w, w, visited)) {
            return 1;
        }
    }

    // Se sono arrivato fino a qui questo cammino non porta verso w
    return 0;
}
```

## Analisi di Complessità con LADJ
1. Per ogni vertice adiacente a $s$ (al massimo $O(|V|)$):
    1. Analizzo ogni vertice adiacente, se non già analizzato. (al massimo $O(|E|)$)

Costo: $O(|V| + |E|)$

# Cammino Semplice di lunghezza $d$
Un cammino semplice di lunghezza $d$ è il percorso che collega 2 vertici v e w passando esattamente da $d$ vertici, senza restrizioni sugli archi da usare, ma passando da ogni vertice al massimo 1 volta.

**Complessità**:
<br>$O(|V|^2)$

## `Wrapper`
```c
int camminoSempliceD(GraphG G, int v, int w, int d) {
    int *visited = calloc(G->V, sizeof(int));
    int result = camminoSempliceR(G, v, w, d, visited);
    free(visited);

    return result;
}
```

## `Ricorsiva`
```c
int camminoSempliceDR(Graph G, int v, int w, int d, int *visited) {
    // Se sono tornato su w, ho finito il cammino
    if (v == w) {
        return d == 0;
    }

    // Visito v
    visited[v] = 1;

    // Per ogni vertice adiacente a v
    for (link t = G->ladj[v]; t != NULL; t = t->next) {
        // Se w non è stato visitato, provo a proseguire il cammino verso w
        // Se il cammino è corretto, allora non ho bisogno di controllarne altri
        if (!visited[t->w] && camminoSempliceDR(G, t->w, w, d - 1, visited)) {
            return 1;
        }
    }

    // Se il cammino da v non ha portato in w, allora lo escludo e continuo col prossimo
    visited[v] = 0;

    // Se sono arrivato fino a qui questo cammino non porta verso w
    return 0;
}
```

## Analisi di Complessità con LADJ
1. Per ogni vertice adiacente a $s$ (al massimo $O(|V|)$):
    1. Analizzo ogni vertice adiacente. (al massimo $O(|E|)$)

Visto che posso averlo già analizzato ma in un cammino che non toccava $d$ vertici, uso il backtrack e posso analizzare tutti i vertici più volte.
<br>Per ogni vertice $O(|V|)$, analizzo al massimo ogni suo arco.
<br>Nel caso peggiore, ogni vertice ha un arco verso ogni altro vertice. Quindi $O(|V|)$.

Costo: $O(|V|^2)$

---

# Cammino di Hamilton
Un cammino di Hamilton è il cammino che connette v a w **passando per tutti i vertici**.

## `Implementazione`
```c
int camminoHamilton(Graph G, int v, int w) {
    return camminoSempliceD(G, v, w, G->V - 1);
}
```

**Complessità**:
<br>La complessità è uguale alla complessità di un cammino semplice lungo $d$.
<br>Costo: $O(|V|^2)$
