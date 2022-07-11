## Esercizio 1
```c
int isVowel(char *string) {
    char s = tolower(string[0]); // Either \0 or the actual first char
    return s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u';
}

int dividiStringhe(char **stringhe, int len, char ***vocali, char ***consonanti) {
    int types[len];
    int vos = 0;
    int cons = 0;
    for (int i = 0; i < len; ++i) {
        if (isVowel(stringhe[i])) {
            ++vos;
            types[i] = 1;
        } else {
            ++cons;
            types[i] = 0;
        }
    }

    *vocali = malloc(vos * sizeof(char *));
    int vIndex = 0;
    *consonanti = malloc(cons * sizeof(char *));
    int cIndex = 0;
    for (int i = 0; i < len; ++i) {
        if (types[i]) {
            (*vocali)[vIndex++] = stringhe[i];
        } else {
            (*consonanti)[cIndex++] = stringhe[i];
        }
    }

    return vos;
}
```

## Esercizio 2
Data una stringa di $n$ caratteri, e un carattere separatore, dividere la stringa in sottostringhe ogni volta che viene incontrato il separatore, e separarle in nodi.

```c
typedef struct list_s *List;

typedef struct link_s *Link;

struct list_s {
    Link head;
    Link tail;
};

struct link_s {
    char *string;
    int n;
    Link next;
};

List LISTnew() {
    List list = malloc(sizeof(struct list_s));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

Link LINKnew(char *string, int n, Link next) {
    Link link = malloc(sizeof(struct link_s));
    link->string = string;
    link->n = n;
    link->next = next;
    return link;
}

void LISTinsertTail(List list, char *string, int n) {
    if (list->head == NULL) {
        list->head = LINKnew(string, n, NULL);
        list->tail = list->head;
        return;
    }

    list->tail->next = LINKnew(list, string, n, NULL);
    list->tail = list->tail->next;
}

int indexOf(char *string, int len, char delimiter) {
    for (int i = 0; i < len; ++i) {
        if (string[i] == delimiter) {
            return i;
        }
    }

    return -1;
}

List LISTdividiStringa(char *string, int n, int delimiter) {
    List result = LISTnew();

    while (1) {
        int indexOfDelimiter = indexOf(string, s);
        if (indexOfDelimiter == -1) {
            break;
        }

        LISTinsertTail(result, string, indexOfDelimiter);
        string += indexOfDelimiter + 1;
        n -= indexOfDelimiter - 1;
    }

    return result;
}
```
