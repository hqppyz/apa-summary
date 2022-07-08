# QuickUnion

## Complessità
| Funzione | Complessità |
| -------- | :---------: |
| Inizializzazione | $\theta(N)$ |
| Ricerca | $O(N)$ |
| Unione | $O(1)$ |

Complessivamente: #Coppie * Lunghezza catena
<br>La lunghezza della catena è l'altezza dell'albero.

---

`Struttura`
```c
typedef struct uf_s *uf;

struct uf_s {
    int n;
    int *ids;
};
```

`Inizializzazione`
<br>Inizializza il vettore di id per ogni indice.
<br>Costo: $\theta(N)$
```c
uf UFnew(int n) {
    uf u = malloc(sizeof(struct uf_s));
    u->n = n;
    u->ids = malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        u->ids[i] = i;
    }
    return u;
}
```

`Find`
<br>Risalgo a cascata gli id finché uno non rappresenta sé stesso.
<br>Costo: $O(N)$
```c
int UFfind(uf u, int index) {
    while (index != u->ids[index]) {
        index = u->ids[index];
    }

    return index;
}
```

`Union`
<br>Assegno al padre di p il padre di q, se diversi.
<br>Costo della ricerca: $O(N)$
<br>Costo dell'unione: $O(1)$
<br>*una volta trovati i padri*
```c
void UFunion(uf u, int p, int q) {
    int p = UFfind(u, p);
    int q = UFfind(u, q);
    if (p == q) {
        // Già connessi, non connetterli
        return;
    }

    u->ids[p] = q;
}
```
