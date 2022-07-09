#include "es3.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

int es3main(int argc, char **argv) {
    int len = 5;
    char **stringhe = malloc(len * sizeof(char *));
    stringhe[0] = "atest1";
    stringhe[1] = "btest2";
    stringhe[2] = "ctest3";
    stringhe[3] = "etest4";
    stringhe[4] = "dtest5";

    printf("Stringhe:\n");
    for (int i = 0; i < len; ++i) {
        printf("%d[%ld]: '%s'\n", i, strlen(stringhe[i]), stringhe[i]);
    }

    char **stringheVocali;
    char **stringheConsonanti;
    int vocali = dividiStringhe(stringhe, len, &stringheVocali, &stringheConsonanti);
    int consonanti = len - vocali;

    printf("Vocali[%d]:\n", vocali);
    for (int i = 0; i < vocali; ++i) {
        printf("%d: '%s'\n", i, stringheVocali[i]);
    }

    printf("Consonanti[%d]:\n", consonanti);
    for (int i = 0; i < consonanti; ++i) {
        printf("%d: '%s'\n", i, stringheConsonanti[i]);
    }

    free(stringheVocali);
    free(stringheConsonanti);
	free(stringhe); // le stringhe non sono allocate dinamicamente

    return 0;
}
