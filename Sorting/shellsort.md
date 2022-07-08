# ShellSort
Lo shell sort è un algoritmo di ordinamento iterativo basato sull'insertion sort.

È in loco. $\checkmark$
<br>**Non** è stabile. $✗$ *Sebbene l'insertion sort sia stabile, lo shell sort scambia elementi distanti h tra di loro, che potrebbero scavalcare elementi simili.*

Il limite dell'insertion sort è che il confronto (e di conseguenza lo scambio) avviene solo tra elementi adiacenti.
<br>Nel peggiore dei casi quindi un elemento dovrà viaggiare (confrontandosi e scambiandosi) con ogni altro elemento del vettore, che porta alla complessità esponenziale.

Lo shell sort cerca di risolvere questo problema, confrontando (e in caso scambiando) elementi ben distanti tra di loro, in modo tale da ridurre le operazioni totali.

La scelta della distanza iniziale nella quale partizionare il vettore definirà la complessità dell'algoritmo.

| Sequenza | Passo | Complessità |
| - | - | - |
| **Knuth** | $\frac{3^k - 1}{2} \le \lceil\frac{n}{3}\rceil$ | $\theta(n^{\frac{3}{2}})$ |
| **Sedgewick** | $\begin{cases}9(2^k-2^{\frac{k}{2}}) + 1 & \text{k pari,} \\8 \cdot 2^k - 6 \cdot 2^{\frac{k + 1}{2}} + 1 &\text{k dispari} \\\end{cases}$ | $O(n^\frac{4}{3})$ |

## `Implementazione`
```c
void shellSort(int *V, int n) {
    // Sequenza di Knuth
    int h = 1;
    while (h <= n / 3) {
        h = 3 * h + 1;
    }

    // Dalla distanza massima, finché non diventa 1
    for (; h >= 1; h = h / 3) {
        // Applico l'insertion sort con salti lunghi h
        insertionSort(V, 0, n - 1, h);
    }
}
```

`InsertionSort di passo h`
```c
void insertionSort(int *V, int l, int r, int h) {
    // Dal secondo all'ultimo, saltando di h
    for (int i = l + h; i <= r; i += h) {
        // L'elemento i-esimo diventa il pivot
        int x = V[i];

        // Dall'elemento precedente ad i, fino al primo
        int j = i - h;
        while (j >= l && V[j] > x) {
            V[j + h] = V[j];

            // Risalgo al primo
            j -= h;
        }

        // L'elemento dopo l'ultimo elemento minore diventa il pivot
        V[j + h] = x;
    }
}
```

Il k-esimo passo della sequenza di Knuth si può calcolare come:
<br>$f(k) = 3*f(k) + 1$
<details>
<summary>Dimostrazione</summary>

Partiamo da
$f(k) = \frac{3^k - 1}{2}$
<br>Aggiungo $3$ e tolgo $3$ al numeratore.
<br>$f(k) = \frac{3^k - 1 + 3 - 3}{2} = \frac{3^k - 3 + 2}{2} = \frac{3^k - 3}{2} + 1$
<br>Metto in evidenza $3$.
<br>$f(k) = 3\frac{3^{k - 1} - 1}{2} + 1$
<br>$\frac{3^{k - 1} - 1}{2}$ è uguale a $f(k - 1)$
<br>$f(k) = 3f(k - 1) + 1$

</details>
