# CountingSort
Il counting sort è un algoritmo di ordinamento lineare.
<br>La posizione di un elemento non si ottiene da confronti ma la si calcola.

**Non** è in loco. $✗$ *Usa 1 (o 2) vettori di appoggio*
<br>È stabile. $\checkmark$

**Complessità**:
<br>$T(n) = O(n + k)$

---

## `Implementazione`
```c
// V: Il vettore da ordinare
// n: la lunghezza del vettore V
// k: l'intervallo massimo degli elementi di V
void countingSort(int *V, int n, int k) {
    // Inizializzo le occorrenze
    int *C = calloc(k, sizeof(int));
    // Conto le occorrenze
    for (int i = 0; i < n; ++i) {
        ++(C[V[i]]);
    }

    // Per ogni valore nell'intervallo
    int index = 0;
    for (int v = 0; v < k; ++v) {
        // Finché non ho finito le occorrenze del valore v
        while (C[v]) {
            V[index++] = v;
            --(C[v]);
        }
    }

    // Libero il vettore d'appoggio
    free(C);
}
```

---

## Analisi di Complessità

| Passo | Costo |
| - | - |
| Inizializzo C | $\theta(k)$ |
| Conto le occorrenze | $\theta(n)$ |
| Per ogni valore dell'intervallo<br>Assegno ogni occorrenza (max $n$) alla propria posizione | $\theta(k)$<br>$O(n)$ |

| Caso | Costo | |
| -: | - | - |
| Generale | $T(n) = O(n + k)$ | |
| $k = O(n)$ | $T(n) = O(n)$ | **Lineare** |
| $k > O(n^2)$ | $T(n) > O(n^2)$ | **Esponenziale** |

Il counting sort è un algoritmo ottimo se l'intervallo massimo è $O(n)$, in quanto diventa lineare.

Se l'intervallo maggiore è superiore ad n, l'algoritmo cresce rapidamente fino a diventare esponenziale.
<br>In oltre, cresce anche la complessità spaziale.
