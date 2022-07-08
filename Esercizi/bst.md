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
