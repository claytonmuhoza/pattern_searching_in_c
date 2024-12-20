#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "horspool.h"

// Fonction pour calculer la dernière occurrence des caractères
void dern_occ(char *x, int m, int bmBc[]) {
    int i;
 
    // Initialisation du tableau avec la longueur du motif
    for (i = 0; i < 256; ++i)
        bmBc[i] = m;
    // Mise à jour des positions des caractères du motif
    for (i = 0; i < m - 1; ++i)
        bmBc[(unsigned char)x[i]] = m - i - 1;
}

// Fonction de recherche utilisant l'algorithme de Horspool
int horspool(char *x, char *y) {
     int m = strlen(y); // Longueur du motif
     int n = strlen(x); // Longueur du texte
     int j, bmBc[256];
     char c;
     int count = 0;

     // Prétraitement
     dern_occ(y, m, bmBc);

     // Recherche
     j = 0;
     while (j <= n - m) {
          c = x[j + m - 1];
          // Vérification du caractère et comparaison du motif
          if (y[m - 1] == c && memcmp(y, x + j, m) == 0)
                count++;
          // Calcul du décalage
          j += bmBc[(unsigned char)c];
     }

     return count; // Retourne le nombre de correspondances trouvées
}