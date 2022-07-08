# Heap
L'heap è una struttura dati con due particolari proprietà:
1. **Strutturale**:
<br>È un albero binario *quasi completo*.
<br>Tutti i livelli tranne quelli delle foglie devono essere completi.
<br>Si riempiono da sinistra a destra. 
2. **Funzionale**:
<br>$k(\text{radice}) > k(\text{figlio sx})$ $\And\And$ $k(\text{radice}) > k(\text{figlio dx})$

## Complessità

| Funzione | Complessità |
| -------- | ----------- |
| **HEAPify** | $T(n) = O(log_{2}{n})$ |
| **HEAPbuild** | $T(n) = O(n)$ |
| **HEAPsort** | $T(n) = O(nlog_2{n})$ |

---

`Struttura`
```c
#define LEFT(i) 2 * i + 1
#define RIGHT(i) 2 * i + 2
#define PARENT(i) (i - 1) / 2;

typedef struct heap_s *heap;

struct heap_s {
    int maxItems;
    int length;
    Item *items;
};

heap HEAPnew(int maxItems) {
    heap h = malloc(sizeof(struct heap_s));
    h->maxItems = maxItems;
    h->length = 0;
    h->items = malloc(maxItems * sizeof(struct item_s));
    return h;
}

void HEAPfree(heap h) {
    if (h == NULL) {
        return;
    }

    for (int i = 0; i < h->length; ++i) {
        ITEMfree(h->items[i]);
    }
    free(h->items);
}
```

---

## HEAPify
`Implementazione`
```c
// Ritorna falso (zero) se non è stato fatto nessuno scambio.
// Se c'è stato uno scambio, ritorna vero (nonzero).
int HEAPify(heap h, int i) {
    int biggest = i;

    int l = LEFT(i);
    if (l < h->length && h->items[biggest] < h->items[l]) {
        biggest = l;
    }

    int r = RIGHT(i);
    if (r < h->length && h->items[biggest] < h->items[r]) {
        biggest = r;
    }

    if (biggest != i) {
        swap(h->items, i, biggest);
        HEAPify(h, biggest);
        return 1;
    }

    return 0;
}
```

**Analisi di Complessità**
<br>Nel caso peggiore ad ogni operazione scende in uno dei due sottoalberi, grandi $\frac{n}{2}$.

| Equazione | Condizione |
| --------- | ---------: |
| $T(1) = 1$ | $se$ $n = 1$ |
| $T(n) = 1 + T(\frac{n}{2})$ | $se$ $n > 1$ |

Sostituendo i vari passi, ci accorgiamo che al k-esimo passo:
<br>$T(n) = \sum_{i = 0}^{k}{1} + T(\frac{n}{2^k})$
<br><br>Che termina quando:
<br>$T(\frac{n}{2^k}) = 1$
<br>Ovvero:
<br>$\frac{n}{2^k} = 1 \rightarrow k = log_{2}{n}$

Sostituendo $k$ con $log_{2}{n}$:
<br>$T(n) = \sum_{i = 0}^{log_{2}{n}}{1} = log_{2}{n}$

Otteniamo:
<br>$T(n) = O(log_{2}{n})$

---

## HEAPbuild
Trasforma un vettore in un heap, applicando l'HEAPify dal padre dell'ultima foglia fino alla radice.

`Implementazione`
```c
heap HEAPbuild(int maxItems, Item *items, int length) {
    heap h = HEAPnew(maxItems);
    for (int i = 0; i < length; ++i) {
        h->items[i] = items[i];
    }

    for (int i = PARENT(length - 1); i >= 0; ++i) {
        HEAPify(h, i);
    }

    return h;
}
```

**Analisi di Complessità**
<br>Intuitivamente verrebbe in mente che ad ogni passo ($n$) si esegue la HEAPify($log_2{n}$), il che renderebbe la HEAPbuild $T(n) = O(nlog_2{n})$, ma in realtà è impreciso.

<br>Lo vediamo al contrario rispetto all'algoritmo.
<br>Ad ogni passo, facciamo l'HEAPify ($i.e.$ $T(n)=O(log_2{n})$) e poi continuiamo l'algoritmo verso i due sottoalberi (i figli sx e dx).

| Equazione | Condizione |
| --------- | ---------: |
| $T(1) = 1$ | $se$ $n = 1$ |
| $T(n) = log_2{n} + 2T(\frac{n}{2})$ | $se$ $n > 1$ |

Sostituendo i vari passi, ci accorgiamo che al k-esimo passo:
<br>$T(n) = \sum_{i = 0}^{k}{(2^ilog_2{\frac{n}{2^k}})} + 2^kT(\frac{n}{2^k})$
<br><br>Che termina quando:
<br>$T(\frac{n}{2^k}) = 1$
<br>Ovvero:
<br>$\frac{n}{2^k} = 1 \rightarrow k = log_2{n}$

Sostituendo $k$ con $log_2{n}$:
<br>$T(n) = \sum_{i = 0}^{log_2{n}}{2^ilog_2{\frac{n}{2^i}}}$

Poi applico la proprietà del rapporto di un logaritmo:
<br>$T(n) = \sum_{i = 0}^{log_2{n}}{2^ilog_2{\frac{n}{2^i}}} \Rightarrow \sum_{i = 0}^{log_2{n}}{2^i(log_2{n} - log_2{2^i})}$
<br>...quindi sostituisco $log_2{2^i}$ con $i$...
<br>$T(n) = \sum_{i = 0}^{log_2{n}}{2^i(log_2{n} - i)}$
<br>...e applico la proprietà dissociativa della sommatoria:
<br>$T(n) = \sum_{i = 0}^{log_2{n}}{2^i(log_2{n} - i)} \Rightarrow \sum_{i = 0}^{log_2{n}}{2^ilog_2{n}} - \sum_{i = 0}^{log_2{n}}{i2^i}$
<br>...continuo portando $log_2{n}$ fuori dalla prima sommatoria, ottenendo:
<br>$T(n) = log_2{n}\sum_{i = 0}^{log_2{n}}{2^i} - \sum_{i = 0}^{log_2{n}}{i2^i}$

Applico al termine di sinistra una normale progressione geometrica, e al termine di destra una serie finita $ix^i$.
<br>Dopo aver risolto tutto ottengo:
<br>$T(n) = 2n - log_2{n}-2$

Che equivale a:
<br>$T(n) = O(n)$

---

## HEAPsort
1. Trasforma un vettore in un heap con la `HEAPbuild`.
<br>Costo: $O(n)$
2. Per ogni elemento:
    1. Scambia il primo elemento con l'ultimo.
    2. Ripristina l'heap con l'`HEAPify`.
    <br>Costo: $O(log_2{n})$

È in loco.
<br>**Non** è stabile.


`Implementazione`
```c
Item *HEAPsort(int maxItems, Item *items, int length) {
    // Trasformo il vettore in un heap
    heap h = HEAPbuild(maxItems, items, length);
    // [Opzionale]
    // Libero il vettore, non gli item singoli, che saranno
    // stati inseriti nell'heap 
    free(items);

    // Finché non esaurisco l'heap
    while ((h->heapSize)-- > 0) {
        // Scambio il primo con l'ultimo
        // (ho già fatto heapSize-- quindi è heapSize l'ultimo)
        swap(h->items, 0, h->heapSize);
        
        // Ripristino la proprietà di heap a partire dal primo elemento
        HEAPify(h, 0);
    }

    // Libero l'heap, ma non i suoi item, che invece ritorno
    Item *result = h->items;
    free(h);
    return result;
}
```

**Analisi di Complessità**
<br>Intuitivamente, per prima cosa si fa l'`HEAPbuild` che costa $O(n)$,
<br>poi, si svolge la `HEAPify` da costo $O(log_2{n})$ per ogni elemento, quindi $n$ volte.
<br>Intuitivamente viene $T(n) = O(nlog_2{n})$.

Per sicurezza, controlliamo la parte ricorsiva con l'equazione alle ricorrenze:

| Equazione | Condizione |
| --------- | ---------: |
| $T(1) = 1$ | $se$ $n = 1$ |
| $T(n) = log_2{n} + T(n - 1)$ | $se$ $n > 1$ |

Sostituendo i vari passi, ci accorgiamo che al k-esimo passo:
<br>$T(n) = log_2{n}\sum_{i = 0}^{k}{1} + T(n - k)$
<br><br>Che termina quando:
<br>$T(n - k) = 1$
<br>Ovvero:
<br>$n - k = 1 \rightarrow k = n - 1$

Sostituendo $k$ con $n - 1$:
<br>$T(n) = log_2{n}\sum_{i = 0}^{n - 1}{1}$

Che diventa:
<br>$T(n) = nlog_2{n}$

Otteniamo:
<br>$T(n) = O(nlog_2{n})$
<br>$O(nlog_2{n})$ è maggiore del primo passo con la `HEAPbuild` ($i.e. O(n)$), quindi resta $O(nlog_2{n})$.
