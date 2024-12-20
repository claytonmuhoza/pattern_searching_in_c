#!/bin/bash

rm -rf results
mkdir -p results

# Génération des textes de taille donnée
for length in 4 5 6 7 8 9 10 15 20 30 40 50; do
# Génération des textes d'alphabet donné
    for alphabet_size in 2 4 20 70; do

        ./programme_recherche "textes_mots_test/mots_${length}_${alphabet_size}.txt" textes_500k/texte_500k_${alphabet_size}.txt  "recherche_naive_boucle_interne_sans_boucle_rapide_sans_sentinelle" 
        ./programme_recherche "textes_mots_test/mots_${length}_${alphabet_size}.txt" textes_500k/texte_500k_${alphabet_size}.txt  "recherche_naive_boucle_rapide_sans_sentinelle" 
        ./programme_recherche "textes_mots_test/mots_${length}_${alphabet_size}.txt" textes_500k/texte_500k_${alphabet_size}.txt  "recherche_naive_boucle_rapide_sentinelle" 
        ./programme_recherche "textes_mots_test/mots_${length}_${alphabet_size}.txt" textes_500k/texte_500k_${alphabet_size}.txt  "recherche_naive_strncmp" 
        ./programme_recherche "textes_mots_test/mots_${length}_${alphabet_size}.txt" textes_500k/texte_500k_${alphabet_size}.txt  "recherche_naive_strncmp_rapide" 
        ./programme_recherche "textes_mots_test/mots_${length}_${alphabet_size}.txt" textes_500k/texte_500k_${alphabet_size}.txt  "recherche_naive_strncmp_sentinelle" 
        ./programme_recherche "textes_mots_test/mots_${length}_${alphabet_size}.txt" textes_500k/texte_500k_${alphabet_size}.txt  "horspool"
        ./programme_recherche "textes_mots_test/mots_${length}_${alphabet_size}.txt" textes_500k/texte_500k_${alphabet_size}.txt  "morris_pratt" 
        ./programme_recherche "textes_mots_test/mots_${length}_${alphabet_size}.txt" textes_500k/texte_500k_${alphabet_size}.txt  "knuth_morris_pratt" 
        ./programme_recherche "textes_mots_test/mots_${length}_${alphabet_size}.txt" textes_500k/texte_500k_${alphabet_size}.txt  "boyer_moore"
        ./programme_recherche "textes_mots_test/mots_${length}_${alphabet_size}.txt" textes_500k/texte_500k_${alphabet_size}.txt  "quick_search" 

    done
done