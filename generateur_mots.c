#include <stdio.h>
#include <stdlib.h>

// Fonction pour générer des mots aléatoires et les écrire dans un fichier
void generateursMots(const char *fichier, int nb_mots, int longueur_mot, int taille_alphabet) {
    FILE *fp = fopen(fichier, "w");
    for (int i = 0; i < nb_mots; i++) {
        for (int j = 0; j < longueur_mot; j++) {
            char c = '0' + (rand() % taille_alphabet);
            fputc(c, fp);
        }
        if (i != 1)
            fputc('\n', fp);
    }
    fclose(fp);
}

int main(int argc, char *argv[]) {
    // Vérification du nombre d'arguments
    if (argc != 5) {
        fprintf(stderr, "Utilisation: %s <nom_fichier> <nombre_de_mot> <longueur> <taille_alphabet>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Récupération des arguments
    const char *filename = argv[1];
    int nb_mots = atoi(argv[2]); // Convertir en entier
    int length = atoi(argv[3]); // Convertir en entier
    int alphabet_size = atoi(argv[4]); // Convertir en entier

    // Vérification des valeurs valides
    if (length <= 0 || alphabet_size <= 0) {
        fprintf(stderr, "Erreur : longueur et taille_alphabet doivent être des entiers positifs. Taille_alphabet max = 26.\n");
        return EXIT_FAILURE;
    }

    // Appel à la fonction pour générer le texte
    generateursMots(filename, nb_mots, length, alphabet_size);
    printf("Texte de %d caractères généré dans le fichier '%s' avec un alphabet de taille %d.\n",
           length, filename, alphabet_size);

    return EXIT_SUCCESS;
}