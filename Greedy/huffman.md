# Huffman
I codici di huffman associano ad ogni stringa di bit un simbolo $s \in S$.
<br>Possono essere:
1. A lunghezza variabile.
2. A lunghezza fissa.

Operazioni:
1. Codifica
<br>*da simbolo $s$ a codice*
2. Decodifica
<br>*da codice a simbolo $s$*

---

## Codici a lunghezza fissa
Sono possibili $n!$ parole da $sup(log_2{|S|}) \in \N$ bit.
<br>Si usano per simboli **isofrequenti**, dove la possibilità di trovare simboli è uniforme.
<br>*c'è la stessa possibilità di trovare un simbolo piuttosto che un altro*
<br>Sono **più facili da decodificare**.

## Codici a lunghezza variabile
Ogni parola ha lunghezza variabile.
<br>Sono **più difficili da decodificare**, ma possono essere usati per la compressione di informazioni, assegnando meno bit ai simboli più frequenti.
<br>Quindi i simboli sono **non isofrequenti**.

---

## Esempio codice morse:

| Simbolo              | a   | b   | c   | d   | e    | f    |
| -------------------- | --: | --: | --: | --: | ---: | ---: |
| **Frequenza**        | 45  | 13  | 12  | 16  | 9    | 5    |
| **Codice fisso**     | 000 | 001 | 010 | 011 | 100  | 101  |
| **Codice variabile** | 0   | 101 | 100 | 111 | 1101 | 1100 |

$|S| = 6$

Ipotizzando un file da **$\boldsymbol{100.000}$ caratteri**:

**Codice fisso**:
<br>$n = \sup(log_2{|S|}) = \sup(2.58) = 3$ bit
<br>Peso: $n * 100.000 = \boldsymbol{300.000}$ **bit**

**Codice variabile**:
| Simbolo       | a  | b   | c   | d   | e    | f    |
| ------------- | -: | --: | --: | --: | ---: | ---: |
| **Frequenza** | 45 | 13  | 12  | 16  | 9    | 5    |
| **Codice**    | 0  | 101 | 100 | 111 | 1101 | 1100 |
| **Lunghezza** | 1  | 3   | 3   | 3   | 4    | 4    |

<br>Peso: $(45 * 1) + (13 * 3) + (12 * 3) + (16 * 3) + (9 * 4) + (5 * 4) * \frac{100.000}{100}$
<br>Peso: $224 * 1000 = \boldsymbol{224.000}$ **bit**

<details>
<summary>Rabbit hole</summary>
224 (freq (%) * lunghezza (bit))
<br>100.000 caratteri (no unità) / 100 freq (%) = 1/freq
<br>(freq (%) * lunghezza (bit)) / freq ($)
<br>lunghezza (bit)

224 * 100.000 / 100 = 224 * 1000
<br>224 : x = 100 : 100.000
<br>x : 224 = 100.000 : 100
</details>

---

## Codici liberi da Prefisso
Nessuna parola di codice valida è un prefisso di un'altra parola di codice.

Codifica: giustapposizione di stringhe. $\boldsymbol{???}$
<br>Decodifica: percorrimento di albero binario.

## Implementazione
## `Node`

`Header`
```c
typedef struct node_s *Node;
typedef int Key;

Node NODEcreateTree(Node left, Node right);

Node NODEcreateItem(Key frequency, char letter);

void NODEfree(Node node);

int NODEcompare(Node n1, Node n2);
```

`Implementazione`
```c
struct node_s {
    Key frequency;
    int type; // 0 se rappresenta un item. 1 se rappresenta un albero

    // Item
    char letter;

    // Albero
    Node left;
    Node right;
};

Node NODEnew(Key frequency, int type) {
    Node node = malloc(sizeof(struct node_s));
    node->frequency = frequency;
    node->type = type;

    // Item
    node->letter = '\0';

    // Albero
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node NODEcreateTree(Node left, Node right) {
    Key frequency = 0;
    if (left != NULL) {
        frequency += left->frequency;
    }
    if (right != NULL) {
        frequency += right->frequency;
    }

    Node node = NODEnew(frequency, 1);
    node->left = left;
    node->right = right;
    return node;
}

Node NODEcreateItem(Key frequency, char letter) {
    Node node = NODEnew(frequency, 0);
    node->letter = letter;
    return node;
}

void NODEfree(Node node) {
    if (node == NULL) {
        return;
    }

    NODEfree(node->left);
    NODEfree(node->right);
    free(node);
}

int NODEcompare(Node n1, Node n2) {
    return n1->frequency - n2->frequency;
}
```

## `PQ`
`Header`
```c
typedef struct pq_s *PQ;

PQ PQfromVector(Node *nodes, int length);

void PQfree(PQ pq);

int PQsize(PQ pq);

void PQinsert(PQ pq, Node node);

Node PQextractMin(PQ pq);
```

`Implementazione`
```c
#define LEFT(i) 2 * i + 1
#define RIGHT(i) 2 * i + 2
#define PARENT(i) (i - 1) / 2

struct pq_s {
    int maxLength;
    Node *nodes;
    int length;
};

// Helper
int compare(PQ pq, int i, int j) {
    return NODEcompare(pq->nodes[i], pq->nodes[j]);
}

void HEAPify(PQ pq, int parent) {
    int lowest = parent;
    
    int left = LEFT(parent);
    if (left < pq->length && compare(pq, left, lowest) < 0) {
        lowest = left;
    }
    
    int right = RIGHT(parent);
    if (right < pq->length && compare(pq, right, lowest) < 0) {
        lowest = right;
    }

    if (lowest == parent) {
        return;
    }

    // Swap
    Node tmp = pq->nodes[parent];
    pq->nodes[parent] = pq->nodes[lowest];
    pq->nodes[lowest] = tmp;

    // HEAPify
    HEAPify(pq, lowest);
}

// HEAPbuild
PQ PQfromVector(Node *nodes, int length) {
    PQ pq = malloc(sizeof(struct pq_s));
    pq->maxLength = length;
    pq->nodes = nodes;
    pq->length = length;

    // A partire dal padre dal padre dell'ultimo figlio, ripristina la proprietà dello heap
    for (int i = PARENT(length - 1); i >= 0; --i) {
        HEAPify(pq, i);
    }

    return pq;
}

void PQfree(PQ pq) {
    if (pq == NULL) {
        return;
    }

    for (int i = 0; i < pq->length; ++i) {
        NODEfree(pq->nodes[i]);
    }
    free(pq->nodes);

    free(pq);
}

int PQsize(PQ pq) {
    return pq->length;
}

void PQinsert(PQ pq, Node node) {
    if (pq->length >= pq->maxLength) {
        // ERRORE: Heap pieno
        return;
    }

    int i = (pq->length)++;
    while (i >= 1) {
        int p = PARENT(i);
        if (compare(pq, i, p) >= 0) {
            // Quando sono maggiore (o uguale) a mio padre, mi interrompo
            break;
        }

        pq->nodes[i] = pq->nodes[p];
        i = p;
    }

    pq->nodes[i] = node;
}

Node PQextractMin(PQ pq) {
    if (pq->length == 0) {
        // Prevengo la riduzione dell'heap se vuoto
        return NULL;
    }

    Node min = pq->nodes[0];

    pq->nodes[0] = pq->nodes[--(pq->length)];
    HEAPify(pq, 0);

    return min;
}
```

## `Algoritmo`
`main.c`
```c
int main() {
    char letters[10] = {    'D', 'C', 'E', 'A', 'F', 'H', 'G', 'B' };
    Key frequencies[10] = {  3 ,  2,   5 ,  1 ,  8 ,  21,  11,  1  };
    int length = sizeof(letters) / sizeof(letters[0]);

    Node *nodes = malloc(length * sizeof(struct node_s));
    for (int i = 0; i < length; ++i) {
        nodes[i] = NODEcreateItem(frequencies[i], letters[i]);
    }

    PQ pq = PQfromVector(nodes, length);

    while (PQsize(pq) > 1) {
        Node left = PQextractMin(pq);
        Node right = PQextractMin(pq);

        PQinsert(pq, NODEcreateTree(left, right));
    }

    printf("Huffman's code:\n");
    // TODO print

    PQfree(pq);
    free(nodes);
    free(tree);

    return 0;
}
```

## Complessità
1. Creo la PQ con `HEAPbuild`: $O(n)$
2. Finché la coda non si svuota (nel caso peggiore $N$)
    1. Estraggo il primo elemento con `PQextractMin`: $O(log_2{n})$
    2. Estraggo il secondo elemento con `PQextractMin`: $O(log_2{n})$
    3. Li ricombino, e li reinserisco con `PQinsert`: $O(log_2{n})$
