# Algoritmo di Bellman-Ford
L'algoritmo di Bellman-Ford cerca il cammino di peso minore tra partendo dal vertice $s$.

Utilizza un approccio di programmazione dinamica, rilassando ad ogni passo i vertici che migliorano la soluzione del passo precedente, ove possibile.

Si divide in 3 passaggi fondamentali:
1. Inizializzazione.
2. $V - 1$ passi per rilassare ogni volta $O(|V|)$ vertici.
3. L'ultimo passo dove si controlla l'esistenza di cicli infiniti, rilassando ogni vertice $\theta(|V|)$.

**Complessità**:
<br>$O(|V| \text{ } |E|)$

## `Implementazione`
```c
// Shortest Path w/Bellman Ford
void GRAPHspBF(Graph G, int s) {
    // 1. Inizializzo st e d. θ(|V|)
    int *st = malloc(G->V * sizeof(int));
    int *d = malloc(G->V * sizeof(int));
    for (int v = 0; v < G->V; ++v) {
        st[v] = -1;
        d[v] = INT_MAX;
    }

    // 1.1 Passo iniziale θ(1)
    st[s] = s;
    d[s] = 0;

    // Inizializzo il flag che rileva se c'è stata qualche relaxation nell'ultima iterazione
    int anyRelaxation = 0;
    // 2. V - 1 passi. O(|V| - 1)
    for (int i = 0; i < G->V - 1; ++i) {
        anyRelaxation = 0;

        // Rilasso ogni vertice θ(|V|)
        if (int v = 0 ; v < G->V; ++v) {
            // Se non è ancora stato stimato...
            if (d[v] == INT_MAX) {
                // ...lo salto
                continue;
            }

            // Per ogni arco del vertice. O(|E|)
            for (link t = G->(ladj[v]; t != NULL; t = t->next) {
                // Rilasso: θ(1)
                // Se il cammino che sto analizzando è più vantagioso...
                if (d[v] + t->wt < d[t->w]) {
                    // ...lo sostituisco al precedente
                    st[t->w] = v;
                    d[t->w] = d[v] + t->wt;

                    // Aggiorno il flag che mi rileva se c'è stata alcuna relaxation
                    anyRelaxation = 1;
                }
            }
        }

        // Se non c'è stata alcuna relaxation...
        if (!anyRelaxation) {
            // ...posso terminare anticipatamente
            break;
        }
    }

    int negativeCycle = 0;
    // Se nell'ultimo passo non c'è stata alcuna relaxation...
    if (!anyRelaxation) {
        // ...non ho bisogno di controllare i cicli negativi,
        // so di trovarmi già nella soluzione migliore e corretta
        
        // NOOP: Solo per chiarezza, in un'implementazione normale basta invertire l'if
    } else {
        // ...altrimenti devo controllare se sono presenti cicli negativi
        // rilassando un'ultima volta ogni arco, e se presente qualsiasi scambio allora possiamo fermarci
        
        // Per ogni vertice θ(|V|)
        for (int v = 0; v < G->V; ++v) {
            // Se non è ancora stato stimato...
            if (d[v] == INT_MAX) {
                // ...lo salto
                continue;
            }

            // Per ogni arco del vertice O(|E|)
            for (link t = G->ladj[v]; t != NULL; t = t->next) {
                // Controllo se il rilassamento avrebbe effetto
                if (d[v] + t->wt < d[t->w]) {
                    // Il rilassamento avrebbe effetto!
                    // Rilevato ciclo a peso negativo!
                    negativeCycle = 1;
                    break;
                }
            }

            // Propago l'uscita dal ciclo
            if (negativeCycle) {
                break;
            }
        }
    }

    if (negativeCycle) {
        // [[ PRINT ]]
        // Rilevato arco a ciclo negativo
    } else {
        // [[ PRINT ]]
        // Ogni vertice da 0 a G->V, cui padre è st[v] e distanza minima da s è d[v]
    }

    free(st);
    free(d);
}
```

## Analisi di Complessità
| | Passo | | Costo |
| -: | - | -: | - |
| $1.$ | Inizializzo || $\theta(\lvert{V}\rvert)$ |
| $2.$ | Per ogni passo $V$- $1$: || $O(\lvert{V - 1}\rvert)$ |
| $2.1$ | Per ogni vertice: || $\theta(\lvert{V}\rvert)$ |
| $2.1.1$ | Per ogni arco del vertice: || $O(\lvert{E}\rvert)$ |
| $2.1.1.1$ | Se minore, sostituisco: || $\theta(1)$ |
| <br>$3.$ | *$V$-esimo passo*<br>Per ogni vertice: || <br>$O(\lvert{V}\rvert)$ |
| $3.1$ | Per ogni arco del vertice: || $O(\lvert{E}\rvert)$ |
| $3.1.1$ | Controllo se sia minore: || $O(1)$ |
|||||
|||| $\boldsymbol{O(\lvert{V}\rvert \text{ } \lvert{E}\rvert)}$ |
