# Priority Queue

## Tipi di implementazioni

| Implementazione | PQinsert | PQshowMax | PQextract |
| --------------- | :------: | :-------: | :-------: |
| *Lista Ordinata* | $O(N)$ | $\theta(1)$ | $\theta(1)$ |
| *Vettore Ordinato* | $\theta(N)$ | $\theta(1)$ | $\theta(1)$ |
| *Lista **non** Ordinata* | $\theta(1)$ | $\theta(N)$ | $\theta(N)$ |
| *Vettore **non** Ordinato* | $\theta(1)$ | $\theta(N)$ | $\theta(N)$ |
| Heap | $O(log_2(N))$ | $\theta(1)$ | $O(log_2(N))$ |

## PQ con Heap
`Struttura`
```c
typedef struct pq_s *pq;

struct pq_s {
    int maxItems;
    Item *heap;
    int heapSize;
};

pq PQnew(int maxItems) {
    pq q = malloc(sizeof(struct pq_s));
    q->maxItems = maxItems;
    q->heap = malloc(maxItems * sizeof(Item));
    q->heapSize = 0;
    return q;
}

void PQfree(pq q) {
    if (q == NULL) {
        return;
    }

    free(q->heap);
    free(q);
}
```

`Parent and Children`
```c
#define LEFT(i) 2 * i + 1;
#define RIGHT(i) 2 * i + 2;
#define PARENT(i) (i - 1) / 2
```

`HEAPify`
```c
int HEAPify(Item *heap, int p) {
    int biggest = p;

    int left = LEFT(p);
    int right = RIGHT(p);

    if (left < q->heapSize && q->heap[biggest] < p->heap[left]) {
        biggest = left;
    }
    if (right < q->heapSize && q->heap[biggest] < q->heap[right]) {
        biggest = right;
    }

    if (biggest != p) {
        swap(q->heap, p, biggest);
        HEAPify(q->heap, biggest);
        return 1;
    }

    return 0;
}
```

`PQinsert`
```c
void PQinsert(pq q, Item item) {
    if (q->heapSize >= q->maxItems) {
        // ERRORE: Heap pieno
        return;
    }

    int i = heapSize++;
    while (i >= 1) {
        int p = PARENT(i);
        if (ITEMcompare(q->heap[i], q->heap[p]) <= 0) {
            // Quando non sono maggiore di mio padre, mi interrompo
            break;
        }

        p->heap[i] = p->heap[p];
        i = p;
    }

    pq->q->heap[i] = item;
}
```

`PQshowMax`
```c
Item PQshowMax(pq q) {
    if (heapSize == 0) {
        // ERRORE: Heap vuoto
        return NULL;
    }

    return pq->heap[0];
}
```

`PQextractMax`
```c
Item PQextractMax(pq q) {
    if (heapSize == 0) {
        // Prevengo la riduzione dell'heap se vuoto
        return NULL;
    }

    Item max = q->heap[0];

    swap(q->heap, 0, --heapSize);
    HEAPify(q->heap, 0);

    return max;
}
```
