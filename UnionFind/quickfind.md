# QuickFind

## Complessità
| Funzione | Complessità |
| -------- | :---------: |
| Inizializzazione | $\theta(N)$ |
| Ricerca | $\theta(1)$ |
| Unione | $\theta(N)$ |

Complessivamente: #Coppie * Dimensione del vettore

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
<br>Ad ogni id è assegnato un padre.
<br>Costo: $\theta(1)$
```c
int UFfind(uf u, int index) {
    return u->ids[index];
}
```

`Union`
<br>Assegno al gruppo di p l'id di q
<br>Costo: $\theta(N)$
```c
void UFunion(uf u, int p, int q) {
    int p = UFfind(u, p);
    int q = UFfind(u, q);
    for (int i = 0; i < u->n; ++i) {
        if (u->ids[i] == p) {
            u->ids[i] = q;
        }
    }
}
```
