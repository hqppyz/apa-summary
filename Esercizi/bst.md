## Esercizio 1
Dato un BST i cui nodi hanno memorizzato anche il puntatore al padre, contare partendo da un nodo, quanti nodi allo stesso livello hanno in comune il padre del padre.

```c
int contaFigliDiLivello(Node node, int livello) {
    if (node == NULL) {
        return 0;
    }

    if (livello == 0) {
        return 1;
    }

    return contaFigliDiLivello(node->left, livello - 1)
        + contaFigliDiLivello(node->right, livello - 1);
}

int contaCugini(Node node) {
    // Prima mi assicuro che esista il nonno, così semplifico le funzioni a venire
    if (node == NULL || node->parent == NULL || node->parent->parent == NULL) {
        return -1;
    }

    // Risalgo al nonno, e conto quanti figli ha dello stesso livello
    return contaFigliDiLivello(node->parent->parent, 2);
}
```

## Esercizio 2
Trovare il figlio con chiave k e portarlo in radice del BST.
Poi rendere tutto il BST come figlio destro della nuova radice.
```c
Node rotateLeft(Node root) {
    Node y = root->left;
    root->left = y->right;
    y->right = root;
    return y;
}

Node rotateRight(Node root) {
    Node y = root->right;
    root->right = y->left;
    y->left = root;
    return y;
}

int TREEsize(Node node) {
    if (node == NULL) {
        return 0;
    }

    return 1 + TREEsize(node->left) + TREEsize(node->right);
}

Node partitionR(Node node, int rank) {
    if (node == NULL) {
        // Rank non trovato
        return NULL;
    }

    int leftSize = TREEsize(node);
    if (rank == leftSize) {
        // Rank trovato
        return node;
    } else if (rank < leftSize) {
        node->left = partitionR(node->left, rank);
        return rotateRight(node);
    } else {
        node->right = partitionR(node->right, rank - leftSize - 1);
        return rotateLeft(node);
    }
}

void esercizio(BST bst, int k) {
    bst->root = partitionR(bst->root, k);
}
```
