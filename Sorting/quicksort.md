# QuickSort

# Caratteristiche
1. È in loco.
2. **NON** è stabile, la partition può scambiare valori uguali.

# Complessità Temporale
|Caso|Complessità|
|-|-|
|Peggiore|$T(n)=O(n^2)$|
|Migliore|$T(n)=O(nlog_2(n))$|
|Medio|$T(n)=O(nlog_2(n))$|

Analisi
-
Ad ogni passo:
1. a

# Implementazione

`Wrapper`
```c
void QuickSort(Item V[], int N) {
    return QuickSortR(V, 0, N - 1);
}
```

`Ricorsiva`
```c
void QuickSortR(Item V[], int l, int r) {
    if (l >= r) {
        // Terminazione
        return;
    }

    int q = partition(V, l, r);
    QuickSortR(V, l, q - 1);
    QuickSortR(V, q + 1, r);
}
```

`Partition`
```c
int partition(Item V[], int l, int r) {
    Item x = V[r]; // Scelgo il pivot
    while (1) {
        // Trovo il primo numero da sx maggiore di x 
        int i = l - 1;
        while (ITEMcompare(V[++i], x) < 0);

        // Trovo il primo numero da dx minore di x, o al max i
        int j = r;
        while (ITEMcompare(V[--j], x) > 0 && j != i);

        if (i >= j) {
            // Se j ha superato o raggiunto i, allora fermati, ho finito di scambiare
            break;
        }

        // Scambia il primo numero maggiore col primo numero minore
        swap(V, i, j);
    }

    // Scambia l'ultimo numero maggiore da sx + 1 (i) e scambialo con la posizione del pivot (r)
    swap(V, i, r);

    return i;
}
```
