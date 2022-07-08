# Massimo (ricorsivo) di un Vettore

Complessità
-
$T(n) = O(n)$

---

`Wrapper`
```c
int max(int *V, int n) {
    return maxR(V, 0, n - 1);
}
```

`Ricorsiva`
```c
int maxR(int *V, int l, int r) {
    if (l > r) {
        // Terminazione (vettore vuoto)
        return -1;
    }
    if (l == r) {
        // Terminazione (vettore unitario)
        return l;
    }

    int q = (l + r) / 2; // D(n) = Θ(1)
    int maxLeft = maxR(V, l, q); // T(n/2)
    int maxRight = maxR(V, q + 1, r); // T(n/2)

    // C(n) = Θ(1)
    return max(maxLeft, maxRight); // Ritorna il massimo oppure -1
}
```

---

Analisi di Complessità
-
| Equazione | Condizione |
| --------- | ---------: |
| $T(0) = T(1) = 1$ | $se$ $n \leq 1$ |
| $T(n) = 1 + 2T(\frac{n}{2})$ | $se$ $n > 1$ |

Sostituendo i vari passi, ci accorgiamo che al k-esimo passo:
<br>$T(n) = \sum_{i = 0}^{k}{2^i} + 2^kT(\frac{n}{2^k})$
<br><br>Che termina quando:
<br>$T(\frac{n}{2^k}) = 1$
<br>Ovvero:
<br>$\frac{n}{2^k} = 1 \rightarrow k = log_2{n}$

Sostituendo $k$ con $log_2{n}$:
<br>$T(n) = \sum_{i = 0}^{log_2{n}}{2^i}$

Che, con la progressione geometrica diventa:
<br>$T(n) = \frac{2^{log_2{n} + 1} - 1}{2 - 1} = 2n - 1$

Otteniamo:
<br>$T(n) = O(n)$
