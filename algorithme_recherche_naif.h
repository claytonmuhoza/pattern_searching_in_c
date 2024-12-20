#ifndef ALGORITHME_RECHERCHE_NAIF_H
#define ALGORITHME_RECHERCHE_NAIF_H
// recherche naive avec boucle interne sans boucle rapide et sans sentinelle
int recherche_naive_boucle_interne_sans_boucle_rapide_sans_sentinelle(char *texte, char *mot);
// recherche naive avec boucle rapide et sans sentinelle
int recherche_naive_boucle_rapide_sans_sentinelle(char *texte, char *mot);
//recherche naive avec boucle rapide et sentinelle
int recherche_naive_boucle_rapide_sentinelle(char *texte, char *mot);
//recherche naive avec strncmp sans boucle rapide et sans sentinelle
int recherche_naive_boucle_rapide_sans_sentinelle(char *texte, char *mot);
// fonction de recherche naive avec boucle interne, boucle r et boucle rapide
int recherche_naive_boucle_rapide_sentinelle(char *texte, char *mot);
// fonction de recherche naive avec la fonction strncmp sans boucle rapide et sans sentinelle
int recherche_naive_strncmp(char *texte, char *mot);
// fonction de recherche naive avec la fonction strncmp avec boucle rapide et sans sentinelle
int recherche_naive_strncmp_rapide(char *texte, char *mot);
// fonction de recherche naive avec la fonction strncmp avec boucle rapide et avec sentinelle
int recherche_naive_strncmp_sentinelle(char *texte, char *mot);

#endif