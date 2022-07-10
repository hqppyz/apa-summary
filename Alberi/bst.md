# Operazioni BST

**Altezza**: $\alpha(log_2{n}) \le h \le \alpha(n)$


**Sbilanciamento**: $altezza$ $max - altezza$ $min$

| Operazione | | Complessità | Equazione |
|-|-:|-|-|
| **Costanti**<br>*rotazione,*<br>*inserzione in radice* || $O(1)$
| **Ricorsive**<br>*ricerca,*<br>*inserzione in foglia,*<br>*rango,*<br>*selezione,*<br>*partizione,*<br>*rimozione* | <br>Bilanciato<br>Sbilanciato | $O(h)$<br>$O(log_2{n})$<br>$O(n)$ | <br>$T(n) = 1 + T(\frac{n}{2})$<br>$T(n) = 1 + T(n - 1)$ |
