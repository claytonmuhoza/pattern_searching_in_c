#include <stdio.h>
#include <time.h>

void MesurerExporter(const char *texte, const char *mot, int (*recherche)(const char *, const char *), 
                         const char *algorithme, int taille_alphabet, int longueur_mot, const char *fichier_csv) {
    clock_t start = clock();
    int resultat = recherche(texte, mot);
    clock_t end = clock();
    double temps_execution = (double)(end - start) / CLOCKS_PER_SEC;
    //on ecrit le resultat dans le fichier csv
    ecrire_resultats_csv(fichier_csv, algorithme, taille_alphabet, longueur_mot, temps_execution);
    //affichage sur la console
    printf("Algorithme: %s | Nombre occurence %d  trouvees en %.6f secondes.\n", algorithme, resultat, temps_execution);

}
