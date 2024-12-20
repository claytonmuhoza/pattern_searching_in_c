#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "algorithme_recherche_naif.h"
#include "boyer_moore.h"
#include "knuth_morris_pratt.h"
#include "morris_pratt.h"
#include "quick_search.h"
#include "horspool.h"
void record_search_time(const char *pattern_file, const char *text_file, const char *search_algo_name) {
    // Ouvrir les fichiers
    FILE *pattern_fp = fopen(pattern_file, "r");
    FILE *text_fp = fopen(text_file, "r");
    if (!pattern_fp || !text_fp) {
        perror("Error opening file");
        return;
    }

    // Lire tout le texte dans un buffer
    fseek(text_fp, 0, SEEK_END);
    long text_length = ftell(text_fp);
    fseek(text_fp, 0, SEEK_SET);

    char *text = (char *)malloc(text_length + 1);
    if (!text) {
        perror("Error allocating memory for text");
        fclose(pattern_fp);
        fclose(text_fp);
        return;
    }

    fread(text, 1, text_length, text_fp);
    text[text_length] = '\0';
    fclose(text_fp);

    // Construire le nom du fichier CSV
    char csv_filename[256];
    snprintf(csv_filename, sizeof(csv_filename), "results/resultat%s.csv", pattern_file + strlen("textes_mot_test/mots_"));
    char *txt_pos = strstr(csv_filename, ".txt.csv");
    if (txt_pos) {
        memmove(txt_pos, txt_pos + 4, strlen(txt_pos + 4) + 1);
    }

    FILE *csv_fp = fopen(csv_filename, "a");
    if (!csv_fp) {
        perror("Error opening CSV file");
        free(text);
        fclose(pattern_fp);
        return;
    }

    // Allouer dynamiquement pour le motif
    size_t pattern_size = 1024; // Taille initiale
    char *pattern = (char *)malloc(pattern_size);
    if (!pattern) {
        perror("Error allocating memory for pattern");
        fclose(csv_fp);
        free(text);
        fclose(pattern_fp);
        return;
    }

    while (fgets(pattern, pattern_size, pattern_fp)) {
        size_t len = strlen(pattern);
        while (len > 0 && pattern[len - 1] == '\n') { // Supprimer les retours à la ligne
            pattern[--len] = '\0';
        }

        clock_t start_time = clock();
        int occurrences = 0;

        // Appeler l'algorithme correspondant
        if(strcmp(search_algo_name, "recherche_naive_boucle_interne_sans_boucle_rapide_sans_sentinelle") == 0) {
            occurrences = recherche_naive_boucle_interne_sans_boucle_rapide_sans_sentinelle(text, pattern);
        } else if(strcmp(search_algo_name, "recherche_naive_boucle_rapide_sans_sentinelle") == 0) {
            occurrences = recherche_naive_boucle_rapide_sans_sentinelle(text, pattern);
        } else if(strcmp(search_algo_name, "recherche_naive_boucle_rapide_sentinelle") == 0) {
            occurrences = recherche_naive_boucle_rapide_sentinelle(text, pattern);
        } else if(strcmp(search_algo_name, "recherche_naive_strncmp") == 0) {
            occurrences = recherche_naive_strncmp(text, pattern);
        } else if(strcmp(search_algo_name, "recherche_naive_strncmp_rapide") == 0) {
            occurrences = recherche_naive_strncmp_rapide(text, pattern);
        } else if(strcmp(search_algo_name, "recherche_naive_strncmp_sentinelle") == 0) {
            occurrences = recherche_naive_strncmp_sentinelle(text, pattern);
        }else if(strcmp(search_algo_name, "horspool") == 0) {
            occurrences = horspool(text, pattern);
        }else if(strcmp(search_algo_name, "morris_pratt") == 0) {
            occurrences = morris_pratt(text, pattern);
        } else if(strcmp(search_algo_name, "knuth_morris_pratt") == 0) {
            occurrences = knuth_morris_pratt(text, pattern);
        } else if(strcmp(search_algo_name, "boyer_moore") == 0) {
            occurrences = boyer_moore(text, pattern);
        } else if(strcmp(search_algo_name, "quick_search") == 0) {
            occurrences = quick_search(text, pattern);
        
        } else {
            fprintf(stderr, "Algorithme inconnu : %s\n", search_algo_name);
            continue;
        }
      

        clock_t end_time = clock();
        double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        fprintf(csv_fp, "%s,%.6f,%d\n", search_algo_name, time_spent, occurrences);
    }

    fclose(csv_fp);
    fclose(pattern_fp);
    free(pattern);
    free(text);
}


int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Utilisation : %s <fichier_mots> <fichier_texte> <nom_algorithme>\n", argv[0]);
        return 1;
    }

    // Créer le dossier "results" s'il n'existe pas
    system("mkdir -p results");

    record_search_time(argv[1], argv[2], argv[3]);

    return 0;
}
