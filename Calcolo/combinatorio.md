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
    int *soluzione = calloc(k, sizeof(int));
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
        if (mark[i] != 0) continue;

        mark[i] = 1;
        soluzione[level] = valori[i];
        dispSempR(level + 1, valori, soluzione, mark, n, k);
        mark[i] = 0;
    }
}
```

## Disposizioni con Ripetizioni

`Wrapper`
```c
void dispRip(int *valori, int n, int k) {
    int *soluzione = calloc(k, sizeof(int));

    dispRipR(0, valori, soluzione, n, k);

    free(soluzione);
}
```

`Implementazione`
```c
void dispRipR(int livello, const int *valori, int *soluzione, int n, int k) {
    if (livello >= k) {
        // Terminazione
        // [[ PRINT ]]
        return;
    }

    for (int i = 0; i < n; ++i) {
        soluzione[livello] = i;
        dispRipR(livello + 1, valori, soluzione, n, k);
    }
}
```

## Permutazioni Semplici

`Wrapper`
```c
void permSemp(int *valori, int n) {
    int *soluzione = calloc(n, sizeof(int));
    int *mark = calloc(n, sizeof(int));

    permSempR(0, valori, soluzione, mark, n);

    free(soluzione);
    free(mark)
}
```

`Implementazione`
```c
void permSempR(int livello, const int *valori, int *soluzione, int *mark, int n) {
    if (livello >= n) {
        // Terminazione
        // [[ PRINT ]]
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (mark[i] != 0) continue:

        mark[i] = 1;
        soluzione[livello] = i;
        permSemp(livello + 1, valori, soluzione, mark, n);
        mark[i] = 0;
    }
}
```

## Permutazioni con Ripetizioni

`Wrapper`
```c
// valori = { 1, 1, 2, 3, 4, 5 }
// n = 6
void permRip(int *valori, int n) {
    int distValori[] = [...]; // Trovo i valori distinti
    int distN = [...]; // Trovo la quantita di valori distinti
    int mark[] = [...]; // Calcolo le occorrenze per ogni valore distinto

    // distValori = { 1, 2, 3, 4, 5 }
    // distN = 5
    // mark = { 2, 1, 1, 1, 1 }

    int *soluzione = calloc(n, sizeof(int));

    permRipR(0, distValori, soluzione, mark, n, distN);

    free(soluzione);
}
```

`Implementazione`
```c
void permRipR(int livello, int *distValori, int *soluzione, int *mark, int n, int distN) {
    if (livello >= n) {
        // Terminazione
        // [[ PRINT ]]
        return;
    }

    for (int i = 0; i < distN; ++i) {
        if (mark[i] <= 0) continue;

        --mark[i];
        soluzione[livello] = i;
        permConRip(livello + 1, distValori, soluzione, mark, n, distN);
        ++mark[i];
    }
}
```

## Combinazioni Semplici

`Wrapper`
```c
void combSemp(int *valori, int n, int k) {
    int *soluzione = calloc(k, sizeof(int));

    combSempR(0, valori, soluzione, n, k, 0);

    free(soluzione);
}
```

`Implementazione`
```c
void combSempR(int livello, const int *valori, int *soluzione, int n, int k, int start) {
    if (livello >= k) {
        // Terminazione
        // [[ PRINT ]]
        return;
    }

    for (int i = start; i < n; ++i) {
        soluzione[livello] = i;
        combSempR(livello + 1, valori, soluzione, n, k, i + 1);
    }
}
```

## Combinazioni con Ripetizioni

`Wrapper`
```c
void combRip(int *valori, int n, int k) {
    int *soluzione = calloc(k, sizeof(int));

    combRipR(0, valori, soluzione, n, k, 0);

    free(soluzione);
}
```

`Implementazione`
```c
void combRipR(int livello, const int *valori, int *soluzione, int n, int k, int start) {
    if (livello >= k) {
        // Terminazione
        // [[ PRINT ]]
        return;
    }

    for (int i = start; i < n; ++i) {
        soluzione[livello] = i;
        combRipR(livello + 1, valori, soluzione, n, k, i);
    }
}
```
