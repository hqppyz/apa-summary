# MergeSort

## Caratteristiche

1. **NON** è in loco, usa un vettore ausiliario.
2. È stabile.

---

## Complessità Temporale
$T(n)=O(nlog_2(n))$

Analisi
-

Ad ogni passo:
1. Divido il vettore a metà:<br>$D(n) = \theta(1)$

2. Risolvo $2$ sottoproblemi di dimensione $\frac{n}{2}$:<br>$2T(\frac{n}{2})$

3. Termino con un semplice controllo:<br>$\theta(1)$

4. Combino i due sottoproblemi:<br>$C(n) = \theta(n)$

Sommati:
<br>$T(n) = D(n) + 2T(\frac{n}{2}) + \theta(1) + C(n)$
<br>$T(n) = 2T(\frac{n}{2}) + n$

---

Equazione alle ricorrenze:

|||
|-|-|
|$T(n) = 2T(\frac{n}{2}) + n$|se $n > 1$|
|$T(1) = 1$|se $n = 1$|


---

## Implementazione

`Wrapper`
```c
void MergeSort(Item V[], int N) {
    int H[N]; // Vettore ausiliario
    MergeSortR(V, H, 0, N - 1);
}
```

`Ricorsiva`
```c
void MergeSortR(Item V[], Item H[], int l, int r) {
    if (l >= r) {
        // Terminazione
        return;
    }

    // Divisione
    int q = (l + r) / 2;
    
    // Chiamate ricorsive
    MergeSortR(V, H, l, q);
    MergeSortR(V, H, q + 1, r);

    // Ricombinazione
    Merge(V, H, l, q, r);
}
```

`Ricombinazione`
```c
void Merge(Item V[], Item H[], int l, int q, int r) {
    int indexL = l;
    int indexR = q + 1;

    // Dall'inizio alla fine (da i a r)
    for (int i = l; i <= r; ++i) {
        if (indexL > q) {
            // Finito di leggere il vettore sx
            H[i] = V[indexR++];
        } else if (indexR > r) {
            // Finito di leggere il vettore dx
            H[i] = V[indexL++];
        } else if (ITEMcompare(V[indexL], V[indexR]) <= 0) {
            // V[indice sx] è <= V[indice dx]
            H[i] = V[indexL++];
        } else {
            // V[indice sx] è > V[indice dx]
            H[i] = V[indexR++];
        }
    }

    // Riscrivo il vettore originale
    for (int i = l; i <= r; ++i) {
        V[i] = H[i];
    }
}
```
