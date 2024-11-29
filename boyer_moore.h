#ifndef boyer_moore_H
#define boyer_moore_H
//fonction qui retourne le tableau des bons suffixes d'un mot
int *bon_suff(char *x);
int boyer_moore(char *texte, char *mot);
#endif