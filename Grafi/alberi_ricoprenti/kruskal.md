# Algoritmo di Kruskal
L'algoritmo di Kruskal utilizza l'approccio greedy degli alberi ricoprenti minimi.

1. Si inseriscono tutti i vertici in una foresta di alberi, ciascuno inizialmente formato solo dalla sua radice *(il vertice)*.
2. Si ordinano gli archi per peso crescente.
3. Per ogni arco, se i due vertici non sono nello stesso albero, li si uniscono.

**Complessità**:
<br>$O(|E| \space log_2{|V|})$

---

## `Implementazione`
`Wrapper`
```c
int GRAPHmstK(Graph G) {
    Edge *mst = mstK(G);

    // [[ PRINT ]] peso totale = \sum{mst[i].wt}
    for (int i = 0; i < G->V - 1; ++i) {
        // [[ PRINT ]]
        // mst[i].v => mst[i].w (di peso mst[i].wt)
    }

    free(mst);
}
```

`mstK`
```c
Edge *mstK(Graph G) {
    Edge *edges = GRAPHedges(G); // Ladj: θ(|V| + |E|), Madj: θ(|V|^2)

    // Ordino gli archi per pesi crescenti
    sortWT(edges, G->E); // MergeSort: O(|E|log|E|)

    // Inizializzo l'UF (weighted quick union): θ(|V|)
    UF uf = UFinit(G->V);
    // Per ogni arco: θ(|E|)
    for (int e = 0; e < G->E; ++e) {
        // Prova ad unirlo... O(log|V|)
        if (UFunion(edges[e].v, edges[e].w)) {
            mst[k++] = edges[e];
        }

        // Se abbiamo già aggiunto un arco per ogni vertice...
        if (k == G->V - 1) {
            // ...ci fermiamo anticipatamente :)
            break;
        }
    }

    return mst;
}
```

---

## Analisi di Complessità
Per ottenere gli archi: $\theta(|V| + |E|)$ o $\theta(|V|^2)$
<br>*ma lo escludiamo dall'algoritmo*

<br>Per ordinare gli archi: $O(|E| \space log_2|E|)$
<br>Per ogni arco: $\theta(|E|)$
<br>&ensp;&ensp;&ensp;&ensp;Ricerco e in caso unisco: $O(log|V|)$

Ci ritroviamo 2 costi:
<br>Ordinamento: $O(|E| \space log_2|E|)$
<br>Unione: $O(|E| \space log_2{|V|})$

Nell'ipotesi in cui ci trovassimo in un arco completo.
<br>*ovvero dove ogni vertice è adiacente ad ogni altro vertice*
<br>$|E| = |V|^2$

Il che renderebbe l'ordinamento:
<br>$O(|E| \space log_2{|E|})$ sostituibile con $O(|E| \space log_2{|V|^2})$
<br>Possiamo applicare le proprietà dei logaritmi e portare fuori il $2$, che essendo una moltiplicazione costante è ignorabile in un $O$.

Quindi l'ordinamento diventa uguale all'unione.

Complessità totale: $O(|E| \space log_2{|V|})$
