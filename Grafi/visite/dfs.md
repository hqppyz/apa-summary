# DFS: Visita in Profondità
A partire da un vertice v, visito il grafo G, scopro ricorsivamente ogni vertice adiacente, se non ancora scoperto, applicando la dfs.

La differenza tra le complessità dipende dal fatto che la lista è più vantagiosa in quanto ottengo facilmente ogni adiacenza di un vertice, e il totale sarà $|E|$, mentre con la matrice ho bisogno di testare ogni vertice per ogni vertice, quindi il totale è $|V|^2$.

# Liste di Adiacenze

## Complessità
1. Inizializzazione: $\theta(|V|)$
<br>*riempio pre[V] e post[V] con -1*
2. Visita ricorsiva da v: $O(|E|)$
<br>*nel caso peggiore v ha un arco verso ogni w*
<br>*in tutto* $\theta(|E|)$

$T(n)=\theta(|V|+|E|)$


---

## Implementazione

`Wrapper`
```c
// G è il grafo
// v è il vertice da cui iniziare la visita
void GRAPHdfs(Graph G, int v) {
    // Inizializzo il tempo a zero e tutti i grafi come non scoperti/elaborati
    int time = 0;
    int *pre = malloc(G->V * sizeof(int));
    int *post = malloc(G->V * sizeof(int));
    for (int u = 0; u < G->V; ++u) {
        pre[u] = post[u] = -1;
    }

    // A partire da v, applico la dfs ad ogni vertice non visitato
    for (int u = v; u < G->V; ++u) {
        // Se il vertice non è ancora stato visitato...
        if (pre[w] == -1) {
            // Visito il vertice...
            dfsR(G, u, pre, post, &time);
            // E ricomincio, perché inizio da v ma i suoi precedenti potrebbero non esser stati analizzati
            u = 0;
        }
    }

    // [[ PRINT ]]
    printf("Tempi di scoperta:\n");
    for (int u = 0; u < G->V; ++u) {
        printf("%s: %d/%d\n", STsearchByIndex(u), pre[u], post[u]);
    }
}
```

`Ricorsiva`
```c
// G è il grafo
// v è il vertice da analizzare
// pre è il vettore (lungo V) di vertici scoperti
// post è il vettore (lungo V di vertici elaborati
// time è l'ultimo tempo
void dfsR(Graph G, int v, int *pre, int *post, int *time) {
    // Scopro v
    pre[v] = (*time)++;

    // Per ogni vertice adiacente a v
    for (link t = G->ladj[v]; t == NULL; t = t->next) {
        // Se il vertice adiacente non è ancora stato scoperto...
        if (pre[t->w] == -1) {
            // ...lo visito
            dfsR(G, t->w, pre, post, time);
        }
    }

    // Ho finito di elaborare v
    post[v] = (*time)++;
}
```

# Matrice di Adiacenze

## Complessità
1. Inizializzazione: $\theta(|V|)$
<br>*riempio pre[V] e post[V] con -1*
2. Visito ricorsiva da v: $\theta(|V|)$
<br>*per ogni v controllo l'adiacenza di ogni vertice*

$T(n)=\theta(|V|^2)$

---

## Implementazione

`Wrapper`
```c
// G è il grafo
// v è il vertice da cui iniziare la visita
void GRAPHdfs(Graph G, int v) {
    // Inizializzo il tempo a zero e tutti i grafi come non scoperti/elaborati
    int time = 0;
    int *pre = malloc(G->V * sizeof(int));
    int *post = malloc(G->V * sizeof(int));
    for (int u = 0; u < G->V; ++u) {
        pre[u] = post[u] = -1;
    }

    // A partire da v, applico la dfs ad ogni vertice non visitato
    for (int u = v; u < G->V; ++u) {
        // Se il vertice non è ancora stato visitato...
        if (pre[w] == -1) {
            // Visito il vertice...
            dfsR(G, u, pre, post, &time);
            // E ricomincio, perché inizio da v ma i suoi precedenti potrebbero non esser stati analizzati
            u = 0;
        }
    }

    // [[ PRINT ]]
    printf("Tempi di scoperta:\n");
    for (int u = 0; u < G->V; ++u) {
        printf("%s: %d/%d\n", STsearchByIndex(u), pre[u], post[u]);
    }
}
```

`Ricorsiva`
```c
// G è il grafo
// v è il vertice da analizzare
// pre è il vettore (lungo V) di vertici scoperti
// post è il vettore (lungo V di vertici elaborati
// time è l'ultimo tempo
void dfsR(Graph G, int v, int *pre, int *post, int *time) {
    // Scopro v
    pre[v] = (*time)++;

    // Per ogni vertice adiacente a v
    for (int w = 0; w < G->V;  ++w) {
        // Se v è adiacente a w, e non è ancora stato scoperto...
        if (pre[w] == -1 && G->madj[v][w]) {
            // ...lo visito
            dfsR(G, w, pre, post, time);
        }
    }

    // Ho finito di elaborare v
    post[v] = (*time)++;
}
```
