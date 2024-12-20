#!/bin/bash

mkdir -p textes_mots_test

# Génération des textes de taille donnée
for length in 4 5 6 7 8 9 10 15 20 30 40 50; do
# Génération des textes d'alphabet donné
    for alphabet_size in 2 4 20 70; do

        ./generateur_mots "textes_mots_test/mots_${length}_${alphabet_size}.txt" 100 $length $alphabet_size
    done
done

