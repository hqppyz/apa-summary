# Albero Ricoprente Minimo
Dato un grafo non orientato, pesato e connesso, il suo albero ricoprente minimo è un grafo aciclico e che minimizza il costo per percorrere i vertici al suo interno.

L'aciclicità e la connessione lo rendono un albero.
<br>È unico solo se tutti i pesi degli archi sono diversi, altrimenti sono possibili più soluzioni ottime.

È composto da $V$- $1$ archi.
<br>*altrimenti sarebbe ciclico*

Per trovare l'MST di un grafo, si possono utilizzare 2 approcci:

## Approccio Completo
Si provano tutti i modi in cui è possibile raggruppare i vertici $V$ in $V$- $1$ archi.
<br>L'ordina non conta, è una combinazione.
<br>È esponenziale.

## Approccio Greedy
Ad ogni passo, si sceglie la soluzione localmente ottima.
<br>Questa potrebbe non essere globalmente ottima, ma con qualche accortezza lo sarà sempre *(ordinandoli)*.

Ad ogni passo:
1. Si ipotizza che la soluzione corrente sia un sottoinsieme della soluzione ottima.
2. Si aggiunge un arco alla soluzione corrente, e si verifica se rimane corretta *(si aggiunge un arco sicuro)*.
<br>Un arco si dice sicuro se, aggiungendolo ad un MST, questo resta un MST *(no cicli)*.

## Teorema degli Alberi Ricoprenti Minimi

