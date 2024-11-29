#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "knuth_morris_pratt.h"

int *bon_pref(char *x){
    int m = strlen(x);
    int *bon_pref = (int *)malloc(m * sizeof(int));
    //bon pref de x[0] est -1
    bon_pref[0] = -1;
    int i = 0;
    int j = -1;
    //bon pref de x[i] est egale a la longueur du plus long prefixe de x[0..i-1] qui est aussi un suffixe de x[0..i-1]
    while (i < m){
        //on cherche le plus long prefixe de x[0..i-1] qui est aussi un suffixe de x[0..i-1]
        while (j > -1 && x[i] != x[j]){
            j = bon_pref[j];
        }
        i++;
        j++;
        bon_pref[i] = j;
    }
    return bon_pref;
}
int *meil_pref(char *x){
    int m = strlen(x);
    int *meil_pref = (int *)malloc(m * sizeof(int));
    //bon pref de x[0] est -1
    meil_pref[0] = -1;
    int i = 0;
    int j = -1;
    //bon pref de x[i] est egale a la longueur du plus long prefixe de x[0..i-1] qui est aussi un suffixe de x[0..i-1]
    while (i < m){
        //on cherche le plus long prefixe de x[0..i-1] qui est aussi un suffixe de x[0..i-1]
        while (j > -1 && x[i] != x[j]){
            j = meil_pref[j];
        }
        i++;
        j++;
        if (x[i] == x[j]){
            meil_pref[i] = meil_pref[j];
        }else{
            meil_pref[i] = j;
        }
    }
    return meil_pref;
}
int knuth_morris_pratt(char *texte, char *mot){
    int n = strlen(texte);
    int m = strlen(mot);
    int *meil_pref_mot = meil_pref(mot);
    int i = 0;
    int j = 0;
    int n_occurence = 0;
    while (i < n){
        while (j > -1 && texte[i] != mot[j]){
            j = meil_pref_mot[j];
        }
        i++;
        j++;
        if (j == m){
            n_occurence++;
            j = meil_pref_mot[j];
        }
    }
    free(meil_pref_mot);
    return n_occurence;
}

