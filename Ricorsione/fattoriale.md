# Fattoriale

Complessità:
-
$T(n) = O(n)$

---

`Implementazione`
```c
int fact(int n) {
    if (n <= 0) {
        return 1;
    }

    return n * fact(n - 1);
}
```

---

Analisi di Complessità
-
| Equazione | Condizione |
| --------- | ---------: |
| $T(n) = 1 + T(n - 1)$ | $se$ $n > 1$ |
| $T(1) = 1$ | $se$ $n = 1$ |

Sostituendo i vari passi, ci accorgiamo che all'k-esimo passo:
<br>$T(n) = \sum_{i = 0}^{k}{1} + T(n - k)$
<br><br>Che termina quando:
<br>$T(n - k) = 1$
<br>Ovvero:
<br>$n - k = 1 \rightarrow k = n - 1$

Sostituendo $k$ con $n - 1$:
<br>$T(n) = \sum_{i = 0}^{n - 1}{1} = n$

Otteniamo:
<br>$T(n) = O(n)$