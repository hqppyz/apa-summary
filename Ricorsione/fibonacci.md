# Fibonacci

Complessità
-
$T(n) = O(2^n)$

---

`Implementazione`
```c
int fib(int n) {
    if (n <= 1) {
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}
```

---

Analisi di Complessità
-
| Equazione | Condizione |
| --------- | ---------: |
| $T(0) = 1$ | $se$ $n = 0$ |
| $T(1) = 1$ | $se$ $n = 1$ |
| $T(n) = 1 + T(n - 1) + T(n - 2)$ | $se$ $n > 1$ |

Visto che $T(n - 2) \leq T(n - 1)$, allora approssimo $T(n - 2)$ come $T(n - 1)$, e le equazioni diventano:

| Equazione | Condizione |
| --------- | ---------: |
| $T(0) = 1$ | $se$ $n = 0$ |
| $T(1) = 1$ | $se$ $n = 1$ |
| $T(n) = 1 + 2T(n - 1)$ | $se$ $n > 1$ |

Sostituendo i vari passi, ci accorgiamo che al k-esimo passo:
<br>$T(n) = \sum_{i = 0}^{k}{2^i} + 2^kT(n-k)$
<br><br>Che termina quando:
<br>$T(n - k) = 1$
<br>Ovvero:
<br>$n - k = 1 \rightarrow k = n - 1$

Sostituendo $k$ con $n - 1$:
<br>$T(n) = \sum_{i = 0}^{n - 1}{2^i}$

Che, con la progressione geometrica diventa:
<br>$T(n) = \frac{2^{n - 1 + 1} - 1}{2 - 1}$

Otteniamo:
<br>$T(n) = O(2^n)$
