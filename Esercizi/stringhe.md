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