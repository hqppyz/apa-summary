# SelectionSort
Il selection sort è un algoritmo iterativo esponenziale, che ad ogni passo trova l'elemento minore non ancora selezionato e lo mette nella posizione corretta.

È in loco. $\checkmark$
<br>**Non** è stabile. $✗$ *Quando si scambia un elemento è possibile che quello nella posizione sbagliata scavalchi un suo simile.*

## `Implementazione`
Da chiamare con `selectionSort(V, 0, n - 1)`.
```c
void selectionSort(int *V, int l, int r) {
    // Dal primo elemento al penultimo
    for (int i = l; i < r; ++i) {
        int minI = i;

        // Dal successivo fino all'ultimo
        for (int j = i + i; j <= r; ++j) {
            if (V[j] < V[minI]) {
                minI = j;
            }
        }

        // Se i è già il minore
        if (minI == i) {
            continue;
        }

        // Altrimenti li scambio
        swap(V, i, minI);
    }
}
```

## Analisi di Complessità
Due cicli annidati.
<br>L'esterno viene eseguito $n - 1$ volte.
<br>L'interno, all'i-esima iterazione viene eseguito $(n - 1) - i$ volte.

$T(n) = (n - 1) + (n - 2) + ... + 2 + 1$
<br>Si tratta di una progressione aritmetica.
<br>$T(n) = \sum_{i = 0}^{n}{i} = \frac{n(n - 1)}{2}$

$T(n) = O(n^2)$
