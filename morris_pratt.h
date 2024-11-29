#ifndef morris_pratt_H
#define morris_pratt_H
//fonction qui retourne le tableau des bons prefixes d'un mot
int *bon_pref(char *x);
//fonction qui retourne le nombre d'occurence d'un mot dans un texte
int morris_pratt(char *texte, char *mot); 
#endif