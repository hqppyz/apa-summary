#include <stdio.h>
#include <stdlib.h>

#define len(v) sizeof(v) / sizeof(v[0])

void printCombSempPOWER(const int *valori, const int *soluzione, int k) {
    printf("{");
    for (int i = 0; i < k; ++i) {
        if (i != 0) {
            printf(", ");
        }
        printf("%d", valori[soluzione[i]]);
    }
    printf("}\n");
}

void combSempPOWER(int livello, const int *valori, int *soluzione, int n, int k, int start) {
    if (livello >= k) {
        printCombSempPOWER(valori, soluzione, k);
        return;
    }

    for (int i = start; i < n; ++i) {
        soluzione[livello] = i;
        combSempPOWER(livello + 1, valori, soluzione, n, k, i + 1);
    }
}

/**
 * Genera da 0 a n combinazioni semplici dei valori, prendendo ogni volta 1 elemento in più.
 * In questo modo, la prima volta calcola combSemp(valori, k: 0), ottenendo {}
 * Poi, combSemp(valori, k: 1), ottenendo {0}, {1} e {2}
 * E così via...
 */
void powersetCOMB(const int *valori, int n) {
    int *soluzione = malloc(n * sizeof(int)); // lunga n
    for (int i = 0; i <= n; ++i) {
        combSempPOWER(0, valori, soluzione, n, i, 0);
    }
}

int mainPowersetCOMB() {
    int S[] = {0, 1, 2};
    int n = len(S);

    powersetCOMB(S, n);

    return 0;
}

void printPowersetDISP(const int *valori, const int *soluzione, int n) {
//    printf("{");
//    for (int i = 0; i < n; ++i) {
//        if (i != 0) {
//            printf(", ");
//        }
//        printf("%d", soluzione[i]);
//    }
//    printf("}\n");
    printf("{");
    int first = 1;
    for (int i = 0; i < n; ++i) {
        if (soluzione[i]) {
            if (!first) {
                printf(", ");
            }
            printf("%d", valori[i]);
            first = 0;
        }
    }
    printf("}\n");
}

/**
 * Ad ogni livello assegno una visibilità di 0 o 1 attraverso una disposizione con ripetizione.
 * Per ogni insieme che raggiunge la terminazione (livello >= n), prendo in considerazione
 * il k-esimo elemento solo se la k-esima soluzione è 1, altrimenti lo ignoro.
 */
void powersetDISP(int livello, const int *valori, int *soluzione, int n) {
    if (livello >= n) {
        printPowersetDISP(valori, soluzione, n);
        return;
    }

    for (int i = 0; i <= 1; ++i) {
        soluzione[livello] = i;
        powersetDISP(livello + 1, valori, soluzione, n);
    }
}

int mainPowersetDISP() {
    int S[] = {0, 1, 2};
    int n = len(S);

    int *soluzione = malloc(n * sizeof(int)); // lungo n (sempre)
    powersetDISP(0, S, soluzione, n);
    free(soluzione);

    return 0;
}

void printPowersetR(const int *valori, const int *soluzione, int livello) {
    printf("{");
    for (int i = 0; i < livello; ++i) {
        if (i != 0) {
            printf(", ");
        }
        printf("%d", valori[soluzione[i]]);
    }
    printf("}\n");
}

/**
 * Funzione ricorsiva che ad ogni iterazione:
 *      - Chiude l'insieme dei valori scelti fino ad ora (caso iniziale livello 0 => {})
 *      - Continua l'esplorazione partendo dall'ultimo valore della soluzione
 */
void powersetR(int livello, const int *valori, int *soluzione, int n, int start) {
    printPowersetR(valori, soluzione, livello); // [ PRINT ] [0, livello)

    for (int i = start; i < n; ++i) {
        soluzione[livello] = i;
        powersetR(livello + 1, valori, soluzione, n, i + 1);
    }
}

int mainPowersetR() {
    int S[] = {0, 1, 2};
    int n = len(S);

    int *soluzione = malloc(n * sizeof(int)); // lungo massimo n (da 0 a n)
    powersetR(0, S, soluzione, n, 0);
}

void printCombConRip(const int *valori, const int *soluzione, int k) {
    printf("[");
    for (int i = 0; i < k; ++i) {
        if (i != 0) {
            printf(", ");
        }
        printf("%d", valori[soluzione[i]]);
    }
    printf("]\n");
}

void combConRip(int livello, const int *valori, int *soluzione, int n, int k, int start) {
    if (livello >= k) {
        printCombConRip(valori, soluzione, k); // [ PRINT ]
        return;
    }

    for (int i = start; i < n; ++i) {
        soluzione[livello] = i;
        combConRip(livello + 1, valori, soluzione, n, k, i);
    }
}

int mainCombConRip() {
    int I[] = {0, 1, 2};
    int n = len(I);
    int k = 2;

    int *soluzione = malloc(k * sizeof(int)); // lungo k
    combConRip(0, I, soluzione, n, k, 0);

    return 0;
}

void printCombSemp(const int *valori, const int *soluzione, int k) {
    printf("[");
    for (int i = 0; i < k; ++i) {
        if (i != 0) {
            printf(", ");
        }
        printf("%d", valori[soluzione[i]]);
    }
    printf("]\n");
}

void combSemp(int livello, const int *valori, int *soluzione, int n, int k, int start) {
    if (livello >= k) {
        printCombSemp(valori, soluzione, k); // [ PRINT ]
        return;
    }

    for (int i = start; i < n; ++i) {
        soluzione[livello] = i;
        combSemp(livello + 1, valori, soluzione, n, k, i + 1);
    }
}

int mainCombSemp() {
    int I[] = {0, 1, 2};
    int n = len(I);
    int k = 2;

    int *soluzione = malloc(k * sizeof(int)); // lungo k
    combSemp(0, I, soluzione, n, k, 0);
    // Cn,k = Dn,k/Pk = coeff bin n su k = n!/(k!(n-k)!) = 3!/2! = 3

    return 0;
}

void printPermConRip(const int *distValori, const int *soluzione, int n) {
    printf("[");
    for (int i = 0; i < n; ++i) {
        if (i != 0) {
            printf(", ");
        }
        printf("%c", distValori[soluzione[i]]);
    }
    printf("]\n");
}

/**
 * Bisogna ottenere i valori distinti:
 *  Ordinandoli con un algoritmo O(nlogn) (quick sort o merge sort)
 *  Eliminando i duplicati, salvandoli nel vettore occorrenze mark
 *
 */
void permConRip(int livello, const int *distValori, int *soluzione, int *mark, int n, int distN) {
    // n per iterare su soluzione
    if (livello >= n) {
        printPermConRip(distValori, soluzione, n); // [ PRINT ]
        return;
    }

    // distN per iterare su distValori
    for (int i = 0; i < distN; ++i) {
        if (mark[i] > 0) {
            --mark[i];
            soluzione[livello] = i;
            permConRip(livello + 1, distValori, soluzione, mark, n, distN);
            ++mark[i];
        }
    }
}

int mainPermConRip() {
    int I[] = {'o', 'r', 'o'};
    int n = len(I);

    int distI[] = {'o', 'r'}; // Trovare i valori distinti di I
    int distN = len(distI); // Qty valori distinti di I
    int mark[] = {2, 1}; // Occorrenze dei valori di I, lungo distN

    int *soluzione = malloc(n * sizeof(int)); // lungo n
    permConRip(0, distI, soluzione, mark, n, distN);
    // Totale = Pn(a, b,...0) = P3(2, 1) = (3!)/(2!) = 3

    return 0;
}

void printPermSemp(const int *valori, const int *soluzione, int k) {
    printf("[");
    for (int i = 0; i < k; ++i) {
        if (i != 0) {
            printf(", ");
        }
        printf("%c", valori[soluzione[i]]);
    }
    printf("]\n");
}

void permSemp(int livello, const int *valori, int *soluzione, int *mark, int n) {
    if (livello >= n) {
        printPermSemp(valori, soluzione, n); // [ PRINT ]
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (mark[i] == 0) {
            mark[i] = 1;
            soluzione[livello] = i;
            permSemp(livello + 1, valori, soluzione, mark, n);
            mark[i] = 0;
        }
    }
}

int mainPermSemp() {
    // Disposizione semplice di tutti gli elementi, ogni elemento capiterà con ogni altro elemento in ogni altra posizione
    int I[] = {'a', 'b', 'c'};
//    int I[] = {0, 1, 2};
    int n = sizeof(I) / sizeof(I[0]);

    int *soluzione = malloc(n * sizeof(int));
    int *mark = calloc(n, sizeof(int));
    permSemp(0, I, soluzione, mark, n);

    return 0;
}

void printDispConRip(const int *valori, const int *soluzione, int k) {
    printf("[");
    for (int i = 0; i < k; ++i) {
        if (i != 0) {
            printf(", ");
        }
        printf("%d", valori[soluzione[i]]);
    }
    printf("]\n");
}

void dispConRip(int livello, const int *valori, int *soluzione, int n, int k) {
    if (livello >= k) {
        printDispConRip(valori, soluzione, k); // [ PRINT ]
        return;
    }

    for (int i = 0; i < n; ++i) {
        soluzione[livello] = i;
        dispConRip(livello + 1, valori, soluzione, n, k);
    }
}

int mainDispConRip() {
    int I[] = {0, 1, 2};
    int n = sizeof(I) / sizeof(I[0]);
    int k = 2;

    int *soluzione = malloc(k * sizeof(int));
    dispConRip(0, I, soluzione, n, k);
    // totale = 9 = D'(3, 2) = 3^2 = 9

    return 0;
}

typedef struct {
    int numOptions;
    int *options;
} Level;

void printMolt(Level *levels, const int *soluzione, int n) {
    printf("[");
    for (int i = 0; i < n; ++i) {
        if (i != 0) {
            printf(", ");
        }
//        printf("%d:%d", i, levels[i].options[soluzione[i]]);
        printf("%c", levels[i].options[soluzione[i]]);
    }
    printf("]\n");
}

void molt(int livello, Level *levels, int *soluzione, int n) {
    if (livello >= n) {
        printMolt(levels, soluzione, n); // [ PRINT ]
        return;
    }

    for (int i = 0; i < levels[livello].numOptions; ++i) {
        soluzione[livello] = i;
        molt(livello + 1, levels, soluzione, n);
    }
}

int mainMolt() {
    int level1[] = {'a', 'b', 'c'};
    int level2[] = {'x', 'y'};
//    int level1[] = {0, 1, 2}; // 3 primi
//    int level2[] = {0, 1}; // 2 secondi
//    int level3[] = {0, 1, 2}; // 3 dolci
    Level levels[] = {
            {len(level1), level1},
            {len(level2), level2},
//            {len(level3), level3}
    };
    int n = len(levels);

    int *soluzione = malloc(n * sizeof(int));
    molt(0, levels, soluzione, n);

    return 0;
}

void printDispSemp(const int *valori, const int *soluzione, int k) {
    printf("[");
    for (int i = 0; i < k; ++i) {
        if (i != 0) {
            printf(", ");
        }
        printf("%d", valori[soluzione[i]]);
    }
    printf("]\n");
}

void dispSemp(int livello, const int *valori, int *soluzione, int *mark, int n, int k) {
    if (livello >= k) {
        printDispSemp(valori, soluzione, k);
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (mark[i] == 0) {
            mark[i] = 1;
            soluzione[livello] = i;
            dispSemp(livello + 1, valori, soluzione, mark, n, k);
            mark[i] = 0;
        }
    }
}

int mainDispSemp() {
    int I[] = {0, 1, 2};
    int n = sizeof(I) / sizeof(I[0]);
    int k = 2;

    int *soluzione = malloc(k * sizeof(int));
    int *mark = calloc(n, sizeof(int));
    dispSemp(0, I, soluzione, mark, n, k);

    return 0;
}

int main() {
//    return mainMolt();
//    return mainDispSemp();
//    return mainDispConRip();
//    return mainPermSemp();
//    return mainPermConRip();
//    return mainCombSemp();
//    return mainCombConRip();
//    return mainPowersetR();
    return mainPowersetDISP();
//    return mainPowersetCOMB();
}
