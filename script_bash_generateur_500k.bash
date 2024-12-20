#!/bin/bash
mkdir -p textes_500k

# Génération des textes de longeur 500000
for alphabet_size in 2 4 20 70; do
    ./generateur_mots "textes_500k/texte_500k_${alphabet_size}.txt" 1 500000 $alphabet_size
done

