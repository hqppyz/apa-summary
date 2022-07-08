# Inserimento in Radice BST
Per inserire un figlio in radice:
1. Si inserisce il figlio nella prima foglia corretta libera.
2. Si rotea con il padre seguendo l'ordine che si è seguito per la ricerca della prima foglia libera.

`Wrapper`
```c
void BSTinsertRoot(BST bst, Item item) {
    if (bst->root == NULL) {
        // La funzione insertRootR non supporta nodi nulli perché ha bisogno di analizzare i figli e rotearli
        bst->root = NODEnew(item);
    } else {
        bst->root = insertRootR(bst->root, item);
    }
}
```

`Ricorsiva`
```c
// Il nodo NON può essere nullo
node insertRootR(node root, Item item) {
    int compare = ITEMcompare(root->item, item);
    if (compare == 0) {
        // ERRORE: Inserimento chiave duplicata.
        // Tanti ma tanti danni... Non deve capitare e basta.
        // In una vera produzione andrebbe fatto un controllo a
        // priori, o ancora meglio, riscritta questa funzione
        // per gestire il ritorno di nulli dalla chiamata
        // ricorsiva, prevenendo la rotazione.
        return NULL;
    }

    if (compare < 0) {
        // Continuo a sinistra...
        if (root->left == NULL) {
            // Non esiste una foglia sinistra, posso inserire
            root->left = NODEnew(item);
        } else {
            // La foglia esiste, quindi continuo la ricerca a sinistra...
            root->left = insertRootR(root->left, item);
        }

        // Roteo verso destra per sostituirlo al padre
        return rotateRight(root);
    } else {
        // Continuo a destra...
        if (rotate->right == NULL) {
            // Non esiste una foglia destra, posso inserire
            root->right = NODEnew(item);
        } else {
            // La foglia esiste, continuo la ricerca a sinistra...
            root->right = insertRootR(root->right, item);
        }

        return rotateLeft(root);
    }
}
```
