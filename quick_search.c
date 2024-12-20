#include <string.h>
#include <stdio.h>
// Fonction pour créer le tableau des mauvais caractères
int* bad_char(char *mot, int m) {
    static int Bc[256]; // Tableau pour stocker les décalages des mauvais caractères
    int i;

    // Initialiser tous les décalages à m + 1
    for (i = 0; i < 256; ++i)
        Bc[i] = m + 1;
    // Mettre à jour les décalages pour les caractères présents dans le mot
    for (i = 0; i < m; ++i)
        Bc[(unsigned char)mot[i]] = m - i;

    return Bc; // Retourner le tableau des mauvais caractères
}

// Fonction de recherche rapide
int quick_search(char *texte, char *mot) {
    int m = strlen(mot); // Longueur du mot
    int n = strlen(texte); // Longueur du texte
    int j, *Bc;
    int count = 0; // Compteur pour le nombre d'occurrences trouvées

    // Obtenir le tableau des mauvais caractères pour le mot
    Bc = bad_char(mot, m);

    // Recherche dans le texte
    j = 0;
    while (j <= n - m) {
        // Comparer le mot avec la sous-chaîne du texte
        if (memcmp(mot, texte + j, m) == 0) {
            count++; // Incrémenter le compteur si une occurrence est trouvée
        }
        // Déplacement dans le texte en utilisant le tableau des mauvais caractères
        j += Bc[(unsigned char)texte[j + m]];
    }

    return count; // Retourner le nombre d'occurrences trouvées
}