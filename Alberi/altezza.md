# Altezza
L'altezza di un nodo rappresenta la quantità totale di livelli massimi.
<br>È più facile mostrarlo che spiegarlo...

---

## Limiti
Il limite inferiore dell'altezza è $log_2(N)$.
<br>Ovvero quando sono perfettamente distribuiti, ogni livello è completo (ogni nodo ha 2 o 0 figli).

Il limite superiore dell'altezza è $N$.
<br>Ovvero quando ci sono N elementi consecutivi crescenti, ad esempio.

---

## Implementazione

`Wrapper`
```c
int TREEheight(BST bst) {
    return heightR(bst->root);
}
```

`Ricorsiva`
```c
int heightR(node root) {
    if (root == NULL) {
        return 0;
    }

    int heightL = heightR(root->left);
    int heightR = heightR(root->right);
    return 1 + max(heightL, heightR);
}
```

# Profondità
Spesso confusa con l'altezza, o equivalente, ma si può dare una definizione diversa.
<br>La profondità di un albero è la sua vicinanza con la radice, che avrà profondità 0.
<br>I figli della radice hanno profondità 1, e così via.

## BST
`Wrapper`
```c
int BSTdepth(BST bst, Key key) {
    return depthR(0, bst->root, key);
}
```

`Ricorsiva`
```c
int depthR(int level, node root, Key key) {
    if (root == NULL) {
        // Chiave non trovata
        return -1;
    }

    int compare = KEYcompare(root->key, key);
    if (compare == 0) {
        return level;
    }

    return depthR(level + 1, compare > 0 ? root->right : root->left, key);
}
```

## Tree
Negli alberi normali, non possiamo ricercare il valore dicotomicamente, quindi siamo costretti a cercarlo prima a sx, e se presente, riproviamo a dx.

`Wrapper`
```c
int TREEdepth(Tree tree, Key key) {
    return depthR(0, tree->root, key);
}
```

`Ricorsiva`
```c
int depthR(int level, node root, Key key) {
    if (root == NULL) {
        // La chiave è in questo ramo
        return -1;
    }

    if (KEYcompare(root->key, key) == 0) {
        // Chiave trovata
        return level;
    }

    // Cerco prima nel sottoalbero sinistro
    int depth = depthR(level + 1, root->left, key);
    if (depth == -1) {
        // Se non c'è, provo nel destro
        depth = depthR(level + 1, root->right, key);
    }
    // Se è stata trovata in un sottoalbero sono felice, altrimenti ritorno comunque -1
    return depth;
}
```

---

## Ampiezza
L'ampiezza di un nodo è quanti nodi sono presenti in quel livello.

---

## Bilanciamento
Un albero si dice bilanciato quando tutti i cammini dalla radice alle foglie hanno la stessa lunghezza.

Oppure, quando il livello delle foglie è uguale all'altezza dell'albero.
<br>*oppure all'altezza - 1*

Il bilanciamento su richiesta partiziona il BST attorno la chiave mediana inferiore, per rendere mediamente più performante la ricerca.

Conta dello sbilanciamento:
<br>profondità max - profondità min
<br>*oppure altezza max - altezza min*
