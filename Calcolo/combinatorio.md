# Calcolo Combinatorio

| Calcolo | Distinto | Ordinato | Semplice | Formula | Equazione |
| - | :-: | :-: | :-: | - | - |
|| *è un insieme* | *l'ordine degli*<br>*elementi conta* | *senza ripetizioni* |
| **Disposizioni**<br>**Semplici** | $\checkmark$ | $\checkmark$ | $\checkmark$ | $D_{n, k} = \frac{n!}{(n - k)!}$ | $T(n) = 1 + nT(n - 1)$ |
| **Disposizioni**<br>**con Ripetizioni** | $\checkmark$ | $\checkmark$ | $✗$ | $D'_{n, k} = n^k$ | $TODO$ |
| **Permutazioni**<br>**Semplici** | $\checkmark$ | $\checkmark$ | $\checkmark$ | $P_n = D_{n, n} = n!$ | $TODO$ |
| **Permutazioni**<br>**con Ripetizioni** | $\checkmark$<br>*è un multi-insieme* | $\checkmark$ | $✗$ | $P_n^{\alpha, \space\beta, \space\dots} = \frac{n!}{\alpha! \space\beta! \space\dots}$ | $TODO$ |
| **Combinazioni**<br>**Semplici** | $\checkmark$ | $✗$ | $\checkmark$ | $C_{n, k} = \frac{D_{n, k}}{P_k} = \frac{n!}{k!(n - k)!}$ | $TODO$ |
| **Combinazioni**<br>**con Ripetizioni** | $\checkmark$ | $✗$ | $✗$ | $C'_{n, k} = \frac{(n - 1 + k)!}{k!(n - 1)!}$ | $TODO$ |

---

## Disposizioni Semplici

`Wrapper`
```c
void dispSemp(int *valori, int n, int k) {
    int *soluzione = malloc(k * sizeof(int));
    int *mark = calloc(n, sizeof(int));

    dispSempR(0, valori, soluzione, mark, n, k);

    free(soluzione);
    free(mark);
}
```

`Implementazione`
```c
void dispSempR(int level, int *valori, int *soluzione, int *mark, int n, int k) {
    if (level >= k) {
        // Terminazione
        // [[ PRINT ]]
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (mark[i] == 0) {
            mark[i] = 1;
            soluzione[level] = valori[i];
            dispSempR(level + 1, valori, soluzione, mark, n, k);
            mark[i] = 0;
        }
    }
}
```

