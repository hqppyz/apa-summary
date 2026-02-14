# Insieme delle Parti
L'insieme delle parti *(o Powerset)*, è l'insieme dei sottoinsiemi di $S$.

Esempio:
<br>$S = {0, 1, 2}$
<br>$\mathcal{P}(S) = \{$
<br>$\space\space\space\space\{\}$ `// k = 0`
<br>$\space\space\space\space\{0\}, \{1\}, \{2\}$ `// k = 1`
<br>$\space\space\space\space\{0, 1\}, \{0, 2\}, \{1, 2\}$ `// k = 2`
<br>$\space\space\space\space\{0, 1, 2\}$ `// k = 3`
<br>$\}$

I Powerset possono essere implementati tramite diversi approcci.

## 1. Divide et impera
Ad ogni iterazione:
1. Chiude l'insieme dei valori scelti fino ad ora.
2. Continua l'esplorazione partendo dall'ultimo valore della soluzione.

`Wrapper`
```c
void powerset(int *valori, int n) {
    int *soluzione = calloc(n, sizeof(int));

    powersetR(0, valori, soluzione, n, 0);

    free(soluzione);
}
```

`Ricorsiva`
```c
void powersetR(int livello, int *valori, int *soluzione, int n, int start) {
    // [[ PRINT ]] da 0 a livello, escluso

    for (int i = start; i < n; ++i) {
        soluzione[livello] = i;
        powersetR(livello + 1, valori, soluzione, n, i + 1);
    }
}
```

## 2. Disposizioni con Ripetizioni
Ad ogni livello, assegno una visibilità di 0 o 1.
<br>Per ogni insieme che raggiunge la terminazione (l'ultimo livello), prendo in considerazione solo l'i-esimo elemento se la i-esima soluzione è 1, altrimenti lo ignoro.

`Wrapper`
```c
void powersetDISP(int *valori, int n) {
    int *soluzione = calloc(n, sizeof(int));

    // Due visibilità possibili: appartenente (1) o non appartenente (0)
    dispRipR(0, valori, soluzione, n: 2, k: n);

    free(soluzione);
}
```

`Ricorsiva`
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

## 3. Combinazioni Ripetute
`Wrapper`
```c
void powersetCOMBSEMP(int *valori, int n) {
    int *soluzione = calloc(n, sizeof(int));

    for (int k = 0; k <= n; ++k) {
        combSempR(0, valori, soluzione, n, k, 0);
    }

    free(soluzione);
}
```

```c
void combSempR(int livello, int *valori, int *soluzione, int n, int k, int start) {
    if (livello >= k) {
        // [[ PRINT ]] da 0 a k
        return;
    }

    for (int i = start; i < n; ++i) {
        soluzione[livello] = valori[i];
        combSempR(livello + 1, valori, soluzione, n, k, i + 1);
    }
}
```

---

# Partizioni di un insieme
Partizionare un insieme $S$ significa dividerne gli elementi in blocchi.

## Disposizioni con Ripetizioni
Per ottenere una partizione in $k$ blocchi, si possono usare delle disposizioni con ripetizione, simili a quelle del Powerset.
<br>La differenza è che invece del powerset, non si rappresentano i diversi stadi di ogni elemento *(appartenente o non appartenente)*, ma si rappresenta a quale blocco $m$ appartiene.

`Wrapper
```c
void partizioniDISPRIP(int *valori, int n, int k) {
    int *soluzione = calloc(n, sizeof(int));

    dispRipR(0, valori, soluzione, n: k, k: n);

    free(soluzione);
}
```

`Ricorsiva`
```c
void dispRipR(int livello, const int *valori, int *soluzione, int n, int k) {
    if (livello >= k) {
        // Backtrack
        for (int m = 0; m < n; ++m) {
            int used = 0;
            for (int i = 0; i < k; ++i) {
                if (soluzione[i] = m) {
                    used = 1;
                    break;
                }
            }

            if (!used) return;
        }

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

## Algoritmo di Er
L'algoritmo di Er trova tutte le possibili partizioni di $S$ in un numero variante $k$ di blocchi,
<br>$1 \le k \le n$

Si divide in 2 ricorsioni:
1. L'elemento corrente viene attribuito ad ogni blocco esistente $[0, m]$.
<br>Si ricorre al prossimo elemento *(ogni volta)*.
2. L'elemento corrente viene attribuito ad un nuovo blocco $m + 1$.
<br>Si ricorre sul prossimo elemento, questa volta passando il nuovo blocco $m + 1$.

`Wrapper`
```c
void er(int *valori, int n) {
    int *soluzione = calloc(n, sizeof(int));

    erR(0, valori, soluzione, n, 0);

    free(soluzione);
}
```

`Ricorsiva`
```c
void erR(int livello, int *valori, int *soluzione, int n, int m) {
    if (livello >= n) {
        // [[ PRINT ]] da 0 a n elementi ognuno nel blocco soluzione[i]

        return;
    }

    for (int i = 0; i < m; ++i) {
        soluzione[livello] = i;
        erR(livello + 1, valori, soluzione, n, m);
    }

    soluzione[livello] = m;
    erR(livello + 1, valori, soluzione, n, m + 1);
}
```

Una versione più specifica è quando sappiamo già in quanti blocchi vogliamo partizionare $S$, e si implementa nello stesso identico modo, ma controllando nella terminazione che gli $m$ blocchi della soluzione attuale siano $k$.

`Wrapper`
```c
void erSpecific(int *valori, int n, int k) {
    int *soluzione = calloc(n, sizeof(int));

    erR(0, valori, soluzione, n, k, 0);

    free(soluzione);
}
```

`Ricorsiva`
```c
void erSpecificR(int livello, int *valori, int *soluzione, int n, int k, int m) {
    if (livello >= n) {
        // [[ PRINT ]] da 0 a n elementi ognuno nel blocco soluzione[i]

        return;
    }

    for (int i = 0; i < m; ++i) {
        soluzione[livello] = i;
        erR(livello + 1, valori, soluzione, n, m);
    }

    soluzione[livello] = m;
    erR(livello + 1, valori, soluzione, n, m + 1);
}
```
