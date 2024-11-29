#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int *dern_occurance(char *mot) {
    int m = strlen(mot);
    int *dern_occurance = (int *)malloc(256 * sizeof(int));
    for (int i = 0; i < 256; i++) {
        dern_occurance[i] = -1;
    }
    for (int i = 0; i < m -1; i++) {
        dern_occurance[mot[i]] = m - 1- i;
    }
    return dern_occurance;
}
int horspool(char *texte, char *mot) {
    int n = strlen(texte);
    int m = strlen(mot);
    int *dern_occurance_mot = dern_occurance(mot);
    int i = 0;
    int n_occurence = 0;
    while (i <= n - m) {
        int j = m - 1;
        while (j >= 0 && texte[i + j] == mot[j]) {
            j--;
        }
        if (j == -1) {
            n_occurence++;
            i++;
        } else {
            i += dern_occurance_mot[texte[i + m - 1]];
        }
    }
    free(dern_occurance_mot);
    return n_occurence;
}
void main()
{
    char text[] = "babbababbabbababbababbabbababbabbababbababbabbababbababbabbababbabbababbababbabbababbabbababbababbabbababbababbabbababbabbababbababbabbababbababbabbababbabbababbababbabbababbabbababbababbabbababbababb";
    char word[] = "ab";
    //afficher dern occurance
    int *dern_occurance_mot = dern_occurance(word);
    for (int i = 0; i < 256; i++) {
        if (dern_occurance_mot[i] != -1) {
            printf("dern occurance de %c est %d\n", i, dern_occurance_mot[i]);
        }
    }
    printf("occurence %d\n", horspool(text, word));
}