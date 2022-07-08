# Rango BST
Il rango di un determinato nodo, rappresenta quanti valori minori di lui esistono nell'albero.

In un albero rappresentato come:
```
     10
     / \
    /   \
   /     \
  5      15
 / \     / \
3   7   13 19
```
Il nodo 5 ha rango 1, perché c'è solamente 1 valore minore di lui (3).
<br>Il nodo 10 ha rango 3, perché minori di lui ci sono 5, 3 e 7.
<br>Il nodo 15 ha rango 4, perché minori di lui c'è il padre e i suoi figli sx (10, che conta rango 3), e 10 stesso (da cui nasce il +1);

`Wrapper`
```c
int BSTrank(BST bst, Key key) {
    return rankR(bst->root, key);
}
```

`Ricorsiva`
```c
int rankR(node root, Key key) {
    if (root == NULL) {
        // Chiave non trovata
        return -1;
    }

    int compare = KEYcompare(root->key, key);
    if (compare == 0) {
        // Se abbiamo trovato la chiave, allora il rango
        // di questo nodo è quanti nodi minori di lui esistono
        return TREEsize(node->left);
    } else if (compare < 0) {
        // Se la chiave che cerchiamo è minore del nodo
        // in cui ci troviamo, allora dobbiamo continuare la
        // ricerca verso sinistra
        return rankR(node->left, key);
    } else {
        // Se la chiave che cerchiamo è maggiore del nodo
        // in cui ci troviamo, allora sommo tutti i nodi attuali,
        // ovvero il corrente (1) + tutti i suoi figli sinistri,
        // e continuo la ricerca verso destra
        return 1 + TREEsize(node->left) + rankR(root->right, key);
    }
}
```

`TREEsize`
```c
int TREEsize(node root) {
    if (root == NULL) {
        return 0;
    }

    return 1 + TREEsize(root->left) + TREEsize(root->right);
}
```

# Selezione BST
La selezione è un'operazione di un BST che seleziona il nodo a partire dal suo rango.

`Wrapper`
```c
node BSTselect(BST bst, int rank) {
    return selectR(bst->root, rank);
}
```

`Ricorsiva`
```c
node selectR(node root, int rank) {
    if (root == NULL) {
        // Il rango non è presente nell'albero
        return NULL;
    }

    // root->left->N;
    int leftSize = TREEsize(root->left);

    if (rank == leftSize) {
        // Se il rank attuale è uguale alla grandezza delle chiavi
        // minori del vertice corrente, allora abbiamo trovato
        // il vertice con il rank richiesto
        return root;
    } else if (rank < leftSize) {
        // Se il rank è minore dei vertici minori del corrente,
        // allora dobbiamo continuare la ricerca a sinistra
        return selectR(node->left, rank);
    } else {
        // Se il rank è maggiore dei vertici minori del corrente,
        // allora dobbiamo continuare a destra, rimuovendo tutti
        // i vertici già inclusi, ovvero il corrente (1)
        // e tutti i suoi minori (leftSize)
        return selectR(node->right, rank - leftSize - 1);
    }
}
```
