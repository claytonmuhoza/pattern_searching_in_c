#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "boyer_moore.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Fonction pour calculer le décalage de dern occurrence
void dern_occ_shift(char *x, int m, int bmBc[]) {
    int i;
 
    // Initialiser toutes les valeurs à la longueur du motif
    for (i = 0; i < 256; ++i)
        bmBc[i] = m;
    // Mettre à jour les valeurs pour les caractères présents dans le motif
    for (i = 0; i < m - 1; ++i)
        bmBc[(unsigned char)x[i]] = m - i - 1;
}
 
// Fonction pour calculer les suffixes
void suffixes(char *x, int m, int *suff) {
    int f, g, i;
 
    suff[m - 1] = m;
    g = m - 1;
    for (i = m - 2; i >= 0; --i) {
        if (i > g && suff[i + m - 1 - f] < i - g)
            suff[i] = suff[i + m - 1 - f];
        else {
            if (i < g)
                g = i;
            f = i;
            while (g >= 0 && x[g] == x[g + m - 1 - f])
                --g;
            suff[i] = f - g;
        }
    }
}
 
// Fonction pour calculer le décalage des bons suffixes
void bon_suff(char *x, int m, int bmGs[]) {
     int x_len = strlen(x);
    int i, j, suff[x_len];
 
    suffixes(x, m, suff);
 
    // Initialiser toutes les valeurs à la longueur du motif
    for (i = 0; i < m; ++i)
        bmGs[i] = m;
    j = 0;
    // Mettre à jour les valeurs pour les suffixes
    for (i = m - 1; i >= 0; --i)
        if (suff[i] == i + 1)
            for (; j < m - 1 - i; ++j)
                if (bmGs[j] == m)
                    bmGs[j] = m - 1 - i;
    for (i = 0; i <= m - 2; ++i)
        bmGs[m - 1 - suff[i]] = m - 1 - i;
}
 
// Fonction principale de l'algorithme de Boyer-Moore
int boyer_moore(char *texte, char *mot) {
     int n = strlen(texte);
     int m = strlen(mot);
    int i, j, bmGs[m], bmBc[n];
     int occurence = 0;
    // Prétraitement
    bon_suff(mot, m, bmGs);
    dern_occ_shift(mot, m, bmBc);
 
    // Recherche
    j = 0;
    while (j <= n - m) {
        for (i = m - 1; i >= 0 && mot[i] == texte[i + j]; --i);
        if (i < 0) {
            occurence++;
            j += bmGs[0];
        }
        else
            j += MAX(bmGs[i], bmBc[(unsigned char)texte[i + j]] - m + 1 + i);
    }
    return occurence;
}
