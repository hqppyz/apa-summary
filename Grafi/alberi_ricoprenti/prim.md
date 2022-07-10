# Algoritmo di Prim
L'algoritmo di Prim utilizza l'approccio greedy degli alberi ricoprenti minimi.

1. Definisco un taglio inizialmente vuoto.
2. Per ogni arco che attraversa il vertice, scelgo quello minimo e lo aggiungo alla soluzione.

**Complessità**:
<br>Dipende tanto come si gestisce l'ordinamento degli archi.
<br>Usare una PQ heap renderebbe il costo di ogni passo $log_|E|$, ipoteticamente.
<br>$O(|E| \space log_2{|E|})$ e quindi $O(|E| \space log_2{|V|})$

*Guarda [kruskal.md](/Grafi/alberi_ricoprenti/kruskal.md#analisi-di-complessità) per la dimostrazione.*

---

## `Implementazione`
Sinceramente non mi interessa :)
<br>Kruskal mi ha già insegnato tutto quello che c'è da sapere, e se me la chiedono la invento :)))
