#include <stdlib.h>
#include <stdio.h>
#include "algorithme_recherche_naif.h"
#include "morris_pratt.h"
int main()
{
    char text[] = "babbababbabbababbababbabbababbabbababbababbabbababbababbabbababbabbababbababbabbababbabbababbababbabbababbababbabbababbabbababbababbabbababbababbabbababbabbababbababbabbababbabbababbababbabbababbababb";
    char word[] = "abab";
    printf("occurence %d\n",recherche_naive_boucle_interne_sans_boucle_rapide_sans_sentinelle(text, word));
    printf("occurence avec fonction naif avec boucle rapide est : %d\n",recherche_naive_boucle_rapide_sans_sentinelle(text, word));
    printf("occurence avec fonction naif avec boucle rapide et sentinelle est : %d\n",recherche_naive_boucle_rapide_sentinelle(text, word));
    //printf("occurence avec fonction naif avec strncmp est : %d\n",recherche_naive_strncmp(text, word));
    printf("Occurence avec fonction Morris Pratt  est : %d\n",morris_pratt(text, word));
    return 0;
}