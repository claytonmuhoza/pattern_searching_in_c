#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "algorithme_recherche_naif.h"
// fonction de recherche naive avec boucle interne sans boucle rapide et sans sentinelle
int recherche_naive_boucle_interne_sans_boucle_rapide_sans_sentinelle(char *texte, char *mot) {
    int len_texte = strlen((const char*)texte);
    int len_mot = strlen((const char*)mot);
    int n_occurence =  0;
    int i = 0;
    while(i <= len_texte - len_mot) {
        int j=0;
        while(j<len_mot && texte[i+j]==mot[j])
        {
            j++;
        }
        if (j == len_mot) {
            n_occurence+=1;
        }
        i++;
    }
    return n_occurence;
}
// fonction de recherche naive avec boucle rapide sans sans sentinelle
int recherche_naive_boucle_rapide_sans_sentinelle(char *texte, char *mot) {
    int len_texte = strlen(texte);
    int len_mot = strlen(mot);
    int n_occurence = 0;
    int i = 0;

    while (i <= len_texte - len_mot) {
        int j = 0;

        // Vérification du mot dans le texte
        while (j < len_mot && texte[i + j] == mot[j]) {
            j++;
        }

        if (j == len_mot) {
            n_occurence++; // Mot trouvé

            // Recherche du prochain point d'avancement en examinant les caractères suivants
            int next_possible = 1; // Par défaut, avancer d'un caractère
            for (int k = 1; k < len_mot; k++) {
                if (texte[i + len_mot - k] == mot[0]) {
                    next_possible = len_mot - k;
                    break;
                }
            }
            i += next_possible;
        } else {
            i++; // Si pas de correspondance, avancer d'un caractère
        }
    }
    return n_occurence;
}

// fonction de recherche naive avec boucle interne, boucle r et boucle rapide
int recherche_naive_boucle_rapide_sentinelle(char *texte, char *mot) {
    int len_texte = strlen(texte);
    int len_mot = strlen(mot);
    int n_occurence = 0;

    // Ajouter une sentinelle à la fin
    char *texte_sentinelle = malloc((len_texte + len_mot + 1) * sizeof(char));
    strcpy(texte_sentinelle, texte);
    strcat(texte_sentinelle, mot);

    int i = 0;
    while (i <= len_texte) {
        int j = 0;

        // Comparer les caractères du mot avec ceux du texte
        while (texte_sentinelle[i + j] == mot[j]) {
            j++;
            if (j == len_mot) { // Mot trouvé
                n_occurence++;
                break;
            }
        }

        if (j == len_mot) {
            // Recherche du prochain point d'avancement
            int next_possible = 1; // Par défaut, avancer d'un caractère
            for (int k = 1; k < len_mot; k++) {
                if (texte_sentinelle[i + len_mot - k] == mot[0]) {
                    next_possible = len_mot - k;
                    break;
                }
            }
            i += next_possible;
        } else {
            i++; // Si pas de correspondance, avancer d'un caractère
        }
    }

    free(texte_sentinelle);
    //comme le mot rechercher est placé à la fin du texte, on doit enlever une occurence
    return n_occurence - 1;
}


// fonction de recherche naive avec la fonction strncmp sans boucle rapide et sans sentinelle
int recherche_naive_strncmp(char *texte, char *mot) {
    int len_texte = strlen(texte);
    int len_mot = strlen(mot);
    int n_occurence = 0;

    for (int i = 0; i <= len_texte - len_mot; i++) {
        if (strncmp(&texte[i], mot, len_mot) == 0) {
            n_occurence++;
        }
    }
    return n_occurence;
}
// fonction de recherche naive avec la fonction strncmp avec boucle rapide et sans sentinelle
int recherche_naive_strncmp_rapide(char *texte, char *mot) {
    int len_texte = strlen(texte);
    int len_mot = strlen(mot);
    int n_occurence = 0;

    for (int i = 0; i <= len_texte - len_mot;) {
        if (strncmp(&texte[i], mot, len_mot) == 0) {
            n_occurence++;
            i += len_mot; // Boucle rapide
        } else {
            i++;
        }
    }
    return n_occurence;
}
// fonction de recherche naive avec la fonction strncmp avec boucle rapide et avec sentinelle
int recherche_naive_strncmp_sentinelle(char *texte, char *mot) {
    int len_texte = strlen(texte);
    int len_mot = strlen(mot);
    int n_occurence = 0;

    // Ajouter une sentinelle
    char *texte_sentinelle = malloc((len_texte + len_mot + 1) * sizeof(char));
    strcpy(texte_sentinelle, texte);
    strcat(texte_sentinelle, mot);

    int i = 0;
    while (i <= len_texte) {
        if (strncmp(&texte_sentinelle[i], mot, len_mot) == 0) {
            n_occurence++;
            i += len_mot; // Boucle rapide
        } else {
            i++;
        }
    }

    free(texte_sentinelle);
    return n_occurence;
}
