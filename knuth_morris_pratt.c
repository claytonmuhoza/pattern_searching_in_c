
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "knuth_morris_pratt.h"

// Fonction pour calculer le tableau des préfixes
// x: le motif
// m: la longueur du motif
// kmpNext: tableau des préfixes
void meilPref(char *x, int m, int kmpNext[]) {
   int i, j;

   i = 0;
   j = kmpNext[0] = -1;
   while (i < m) {
      while (j > -1 && x[i] != x[j])
         j = kmpNext[j];
      i++;
      j++;
      if (x[i] == x[j])
         kmpNext[i] = kmpNext[j];
      else
         kmpNext[i] = j;
   }
}

// Fonction pour effectuer la recherche de Knuth-Morris-Pratt
int knuth_morris_pratt(char *texte, char *mot) {
   int i, j, m, n, count = 0;

   m = strlen(mot); // longueur du motif
   n = strlen(texte); // longueur du texte
   int kmpNext[m+1];
   /* Prétraitement */
   meilPref(mot, m, kmpNext);

   /* Recherche */
   i = j = 0;
   while (j < n) {
      while (i > -1 && mot[i] != texte[j])
         i = kmpNext[i];
      i++;
      j++;
      if (i >= m) {
         count++;
         i = kmpNext[i];
      }
   }

   return count;
}
