# Rimozione BST
Per rimuovere un nodo in un BST:
1. Scendo dalla radice finché non trovo la chiave desiderata.
2. Trovato il nodo, scelgo arbitrariamente uno dei due figli (se non sono entrambi nulli).
3. Partiziono il figlio scelto per poter liberare il suo figlio opposto.
<br>Se ho scelto il figlio destro devo partizionare attorno la chiave più piccola (0) perché così libero il suo figlio sinistro che diventerà l'opposto del figlio scelto (ergo il sinistro).
<br>Se ho scelto il figlio sinistro, devo partizionarlo attorno la chiave più grande, per poter liberare il suo figlio destro che diventerà l'opposto del figlio scelto (ergo il destro).
4. A questo punto il figlio scelto diventa il padre.

Per non complicare troppo, si possono seguire sempre questi passaggi:
1. *Scendo dalla radice finché non trovo la chiave desiderata.*
2. Se il figlio destro è nullo, allora sostituisco al padre il figlio sinistro, altrimenti scelgo il figlio destro.
<br>*Posso evitare di fare qualsiasi partizionamento se entrambi sono nulli, ma tanto funziona lo stesso*
3. Scelto il figlio destro, lo partiziono attorno al nodo di rango 0, liberando il figlio sinistro, che diventerà il vecchio figlio sinistro del padre.
4. A questo punto il figlio destro diventa il padre.

`Wrapper`
```c
```

`Ricorsiva`
```c
node deleteR(node root, Key key) {
    if (root == NULL) {
        // Chiave non trovata
        return NULL;
    }

    int compare = KEYcompare(root->key, key);
    if (compare == 0) {
        // Chiave trovata, rimuovo...

        left = root->left;
        right = root->right;
        free(root);

        // Se non esiste il figlio destro mi fermo
        if (right == NULL) {
            return left;
        }

        // Partiziono il figlio destro attorno il rango 0
        right = partitionR(right, 0);
        
        // Ho liberato quindi la posizione sx del figlio destro
        right->left = left;

        // Ritorno il figlio destro, che diventa il nuovo padre
        return right;
    } else if (compare < 0) {
        // Continuo a sinistra...
        root->left = deleteR(root->left, key);
        // Senza cambiare il nodo attuale
        return root;
    } else {
        // Continuo a destra...
        root->right = deleteR(root->right, key);
        // Senza cambiare il nodo attuale che non c'entra poveretto non ha fatto niente non ve la prendete con lui era solo un ragazzo salutava sempre
        return root;
    }
}
```