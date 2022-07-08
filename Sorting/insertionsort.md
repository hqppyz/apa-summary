# InsertionSort
L'insertion sort è un algoritmo di ordinamento iterativo esponenziale.
<br>Ad ogni passo, l'algoritmo sposta l'i-esima chiave nella sua posizione corretta, spostando avanti ogni valore precedente maggiore della chiave, fino a trovarne almeno uno minore o uguale, che segna il valore precedente della posizione della chiave.

È in loco. $\checkmark$
<br>È stabile. $\checkmark$

**Complessità**:
<br>$T(n) = O(n^2)$

## `Implementazione`
Da richiamare con `insertionSort(V, 0, n - 1)`.
```c
void insertionSort(int *V, int l, int r) {
    // Dal secondo all'ultimo elemento
    for (int i = l + 1; i <= r; ++i) {
        // L'elemento i-esimo diventa il pivot
        int x = V[i];

        // Dall'elemento precedente, fino al primo
        int j = i - 1;
        while (j >= l && A[j] > x) {
            // Se l'elemento è maggiore del pivot, sale di una posizione
            A[j + 1] = A[j];

            // Risali fino al primo
            --j;
        }

        // La prima posizione minore del pivot, diventa il pivot
        A[j + 1] = x;
    }
}
```

## Analisi di Complessità
Due cicli annidati.
<br>L'esterno viene eseguito $n - 1$ volte.
<br>L'interno, all'i-esimo iterazione viene eseguito $(n - 1) - i$ volte.

$T(n) = (n - 1) + (n - 2) + ... + 2 + 1$
<br>Si tratta di una progressione aritmetica.
<br>$T(n) = \sum_{i = 0}^{n}{i} = \frac{n(n - 1)}{2}$

$T(n) = O(n^2)$

