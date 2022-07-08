# BubbleSort
Il bubble sort (*o exchange sort*) è un algoritmo iterativo esponenziale.

È in loco. $\checkmark$
<br>È stabile. $\checkmark$

**Complessità**:
<br>$T(n) = O(n^2)$
<br>*esponenziale*

## `Implementazione`
Da chiamare con `bubbleSort(V, 0, n - 1)`.
```c
void bubbleSort(int *V, int l, int r) {
    // Dal primo elemento al penultimo
    for (int i = l; i < r; ++i) {
        // Dal primo al penultimo elemento meno quanti elementi ho già analizzato
        // r - #Iterazioni
        // #Iterazioni = i - l (perché i parte da l)
        // Alla i-esima iterazione, ho spostato ogni volta il più grande elemento alla fine del vettore, quindi possiamo fermarci prima
        for (int j = l; j < r - (i - l); ++j) {
            // Se l'elemento j è maggiore del successivo...
            if (V[j] > V[j + 1]) {
                // ...invertili
                swap(V, j, j + 1);
            }
        }
    }
}
```

Questa implementazione scambia n volte tutti gli elementi (riducendo il ciclo interno ogni volta di 1).
<br>Possiamo però terminare ancora prima quando in uno dei cicli interni gli elementi sono già del tutto ordinati, invece di proseguire e confrontarli tutti.
<br>Per farlo, possiamo salvare in un flag quando il ciclo esegue uno scambio, e al termine del ciclo, uscire se non sono stati fatti scambi.
<br>Usando questo flag, possiamo evitare di scrivere il ciclo esterno con un for, ma sostituendolo con un ciclo che si interrompe quando il flag non è stato modificato.
<br>Al peggio, questo sarà l'ultimo ciclo (se il vettore originario era in ordine inverso), altrimenti potrebbe fermarsi già dopo il primo ciclo.

`Versione alternativa`
```c
void bubbleSort(int *V, int l, int r) {
    int ordered;
    do {
        ordered = 1;

        for (int i = l; i < r - (i - l); ++i) {
            if (V[i] > V[i + 1]) {
                swap(V, i, i + 1);
                ordered = 0;
            }
        }
    } while (!ordered);
}
```

## Analisi di Complessità
Ci sono 2 cicli annidati.
<br>L'esterno verrà eseguito n volte.
<br>L'interno verrà eseguito ad ogni passo una volta in meno. Partendo da n.

$T(n) = (n - 1) + (n - 2) + (n - 3) + ... + 2 + 1$
<br>Si tratta di una progressione aritmetica.
<br>$T(n) = \sum_{i = 0}^{n}{i} = \frac{n(n - 1)}{2} = \frac{n^2 - n}{2}$

$T(n) = O(n^2)$
