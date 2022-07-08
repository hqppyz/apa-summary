# Partizione BST
La partizione riordina l'albero attorno ad una chiave di un dato rango.
Si scende a partire dalla radice nei vari rami fino a trovare la chiave con il rango richiesto, e a quel punto si torna indietro roteando a sinistra o destra a seconda di dove si è scesi.

Una buona partizione può rendere molto più efficiente un BST.
Di solito, una buona partizione è quella fatta attorno al rango mediano.
<br>Ovvero $\frac{N}{2}$.

`Wrapper`
```c
void BSTpartition(BST bst, int rank) {
    bst->root = partitionR(bst->root, rank);
}
```

`Ricorsiva`
```c
node partitionR(node root, int rank) {
    if (root == NULL) {
        // ERRORE: Rango inesistente.
        // Tanti problemi, andrebbe controllato a priori.
        return NULL;
    }

    // Scendiamo finché non troviamo il rango richiesto

    int leftSize = TREEsize(root->left);
    if (rank == leftSize) {
        // Siamo arrivati al rango
        return root;
    } else if (rank < leftSize) {
        // Il rango si trova a sinistra

        // Scendo in quello di sinistra...
        root->left = partitionR(root->left, rank);

        // Il figlio sinistro diventa il nuovo padre
        return roteateRight(root);
    } else {
        // Il rango si trova a destra

        // Scendo in quello di destra (- il rango attuale)...
        root->right = partitionR(root->right, rank - leftSize - 1);

        // Il figlio destro diventa il nuovo padre
        return roteateLeft(root);
    }
}
```