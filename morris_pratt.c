#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "morris_pratt.h"

// Fonction pour construire le tableau des bons préfixes
void tabBonPref(char *x, int m, int mpNext[]) {
    int i, j;

    i = 0;
    j = mpNext[0] = -1; // Initialisation
    while (i < m) {
        while (j > -1 && x[i] != x[j]) // Trouver le plus long préfixe qui est aussi un suffixe
            j = mpNext[j];
        mpNext[++i] = ++j; // Mettre à jour le tableau mpNext
    }
}

// Fonction pour l'algorithme de recherche de Morris-Pratt
int morris_pratt(char *texte, char *mot) {
     int i, j, m, n, mpNext[256];
     int occurence = 0;

     m = strlen(mot); // Longueur du motif
     n = strlen(texte); // Longueur du texte

     // Prétraitement
     tabBonPref(mot, m, mpNext);

     // Recherche
     i = j = 0;
     while (j < n) {
          while (i > -1 && mot[i] != texte[j]) // Comparer les caractères du motif et du texte
                i = mpNext[i];
          i++;
          j++;
          if (i >= m) { // Motif trouvé
                occurence++;
                i = mpNext[i]; // Continuer la recherche
          }
     }
     return occurence; // Retourner le nombre d'occurrences trouvées
}