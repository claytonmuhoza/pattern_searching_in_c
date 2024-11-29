#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int* suff(const char *mot) {
    int f, g, i;
    int m = strlen(mot);
    int *suff = (int *)malloc(m * sizeof(int));
    suff[m - 1] = m;
    g = m - 1;
    for (i = m - 2; i >= 0; --i) {
        if (i > g && suff[i + m - 1 - f] < i - g) {
            suff[i] = suff[i + m - 1 - f];
        } else {
            if (i < g) {
                g = i;
            }
            f = i;
            while (g >= 0 && mot[g] == mot[g + m - 1 - f]) {
                --g;
            }
            suff[i] = f - g;
        }
    }
    return suff;
}

int *bon_suff(const char *mot) {
    int i, j;
    int m = strlen(mot);
    int *bon_suff = (int *)malloc(m * sizeof(int));
    int *tab_suff = (int *)malloc(m * sizeof(int));

    tab_suff = suff(mot);

    for (i = 0; i < m; ++i) {
        bon_suff[i] = m;
    }

    j = 0;
    for (i = m - 1; i >= 0; --i) {
        if (tab_suff[i] == i + 1) {
            for (; j < m - 1 - i; ++j) {
                if (bon_suff[j] == m) {
                    bon_suff[j] = m - 1 - i;
                }
            }
        }
    }

    for (i = 0; i <= m - 2; ++i) {
        bon_suff[m - 1 - tab_suff[i]] = m - 1 - i;
    }

    free(tab_suff);
    return bon_suff;

}
int boyer_moore(char *texte, char *mot) {
    int n = strlen(texte);
    int m = strlen(mot);
    int *bon_suffix = bon_suff(mot);
    int i, j, shift = 0, occurences = 0;

    while (shift <= n - m) {
        j = m - 1;

        while (j >= 0 && mot[j] == texte[shift + j]) {
            --j;
        }

        if (j < 0) {
            occurences++;
            shift += bon_suffix[0];
        } else {
            shift += bon_suffix[j];
        }
    }

    free(bon_suffix);
    return occurences;
}
int main() {
    char texte [] = "babbababbabbababbababbabbababbabbababbababbabbababbababbabbababbabbababbababbabbababbabbababbababbabbababbababbabbababbabbababbababbabbababbababbabbababbabbababbababbabbababbabbababbababbabbababbababb";
    char *mot = "ab";
    int m = strlen(mot);
    int * tab_suff = suff(mot);
    printf("Suffix table:\n");
    for (int i = 0; i < m; ++i) {
        printf("%d\t", tab_suff[i]);
    }
    printf("\n");
    int *tab_bon_suff = bon_suff(mot);

    printf("Good suffix table:\n");
    for (int i = 0; i < m; ++i) {
        printf("%d\t", tab_bon_suff[i]);
    }
    printf("\n");
    printf("Nombre d'occurence %d\n", boyer_moore(texte, mot));
    return 0;
}