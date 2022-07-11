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

## Esercizio 3
Dato un BST crescente, farlo diventare decrescente.
```c
typedef struct bst_s *BST;

typedef struct node_s *Node;

struct bst_s {
    Node root;
};

struct node_s {
    Item item;

    Node left;
    Node right;
};

void NODEreverse(Node root) {
    if (root == NULL) {
        return;
    }

    Node tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    NODEreverse(root->left);
    NODEreverse(root->right);
}

void BSTinvertOrder(BST bst) {
    if (bst == NULL) {
        return;
    }

    NODEreverse(bst->root);
}
```

## Esercizio 4
Dato un BST, implementare l'inserimento in radice.
```c
typedef struct bst_s *BST;

typedef struct node_s *Node;

struct bst_s {
    Node root;
};

struct node_s {
    Item item;

    Node left;
    Node right;
};

BST BSTnew(Node root) {
    BST bst = malloc(sizeof(struct bst_s));
    bst->root = root;
    return bst;
}

Node NODEnew(int key, Node left, Node right) {
    Node node = malloc(sizeof(struct node_s));
    node->key = key;
    node->left = left;
    node->right = right;
    return node;
}

Node rotateLeft(Node root) {
    // Salvo il figlio destro
    Node y = root->right;

    // Il vecchio padre punta al figlio sinistro del figlio
    root->right = y->left;

    // Il figlio destro punta al padre
    y->left = root;

    // Il vecchio figlio destro diventa il padre
    return y;
}

Node rotateRight(Node root) {
    // Salvo il figlio sinistro
    Node y = root->left;

    // Il vecchio padre punta al figlio destro del figlio
    root->left = y->right;

    // Il figlio sinistro punta al padre
    y->right = root;

    // Il vecchio figlio sinistro diventa il padre
    return y;
}

Node NODEinsertAt(Node root, Key key) {
    if (root == NULL) {
        return NODEnew(key, NULL, NULL);
    }

    int compare = KEYcompare(key, root->key);
    if (compare == 0) {
        // panic, la chiave è già presente.
        return NULL;
    } else if (compare < 0) {
        // Si trova a sinistra
        if (root->left == NULL) {
            // Se non esiste il figlio sinistro lo creo
            root->left = NODEnew(key, NULL, NULL);
        } else {
            // Altrimenti continuo la ricerca a sinistra
            Node tmp = NODEinsertAt(root->left, key);
            if (tmp == NULL) {
                // panic
                return NULL;
            }

            root->left = tmp;
        }

        // Poi roteo per farlo scambiare con questa radice
        return NODErotateRight(root);
    } else {
        // Si trova a destra
        if (root->right == NULL) {
            // Se non esiste il figlio destro lo creo
            root->right = NODEnew(key, NULL, NULL);
        } else {
            // Altrimenti continuo la ricerca a destra
            Node tmp = NODEinsertAt(root->right, key);
            if (tmp == NULL) {
                // panic
                return NULL;
            }

            root->right = tmp;
        }

        // Poi roteo per farlo scambiare con questa radice
        return NODErotateLeft(root);
    }
}

void BSTinsertRoot(BST bst, Key key) {
    Node tmp = NODEinsertAt(bst->root, key);
    if (tmp == NULL) {
        // panic
        return;
    }

    bst->root = tmp;
}
```
