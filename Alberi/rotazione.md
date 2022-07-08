# Rotazione BST
La rotazione è il processo di invertire un nodo col proprio figlio destro o sinistro, a seconda del tipo di rotazione.

# Rotazione a Sinistra
Per roteare a sinistra:
1. Si sposta il padre al posto del suo figlio sinistro, e il suo figlio destro al posto del padre.
2. Si sposta il figlio sinistro del vecchio figlio destro, come figlio destro del vecchio padre.

`Wrapper`
```c
void BSTrotateLeft(node *parent) {
    *parent = rotateLeft(*parent);
}
```

`Implementazione`
```c
node rotateLeft(node parent) {
    // Salvo il figlio destro
    node y = parent->right;

    // Il figlio destro del padre diventa il figlio sinistro del figlio da roteare
    parent->right = y->left;

    // Il figlio sinistro del nuovo padre
    y->left = parent;

    // Il nuovo parent diventa il figlio roteato
    return y;
}
```

# Rotazione a Destra
Per roteare a destra:
1. Si sposta il padre al posto del suo figlio destro, e il suo figlio sinistro al posto del padre.
2. Si sposta il figlio destro del vecchio figlio sinistro, come figlio sinistro del vecchio padre.

`Wrapper`
```c
void BSTrotateRight(node *parent) {
    *parent = rotateRight(*parent);
}
```

`Implementazione`
```c
node rotateRight(node parent) {
    // Salvo il figlio sinistro, da roteare
    node y = parent->left;

    // Il figlio destro del figlio da roteare diventa il figlio sinistro del vecchio padre
    parent->left = y->right;

    // Il vecchio padre diventa il figlio destro del figlio da roteare
    y->right = parent;

    // Il nuovo parent diventa il figlio roteato
    return y;
}
```
