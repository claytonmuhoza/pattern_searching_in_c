# ALGORITHME DE RECHERCHE

La commande `make` permet de compiler deux exécutables :

```bash
make
```

1. **Un générateur de texte**, qui peut être utilisé à travers deux scripts bash :
   ```bash
   # Script pour générer des textes de 500 000 caractères sur différents alphabets (2, 4, 20, 70)
   ./script_bash_generateur_500k.bash
   
   # Script pour générer des mots de tailles différentes sur des alphabets de tailles variées
   ./script_bash_generateur_mots_test.bash
   ```

2. **Un programme de recherche** (`programme_recherche`), permettant de chercher l'ensemble des mots contenus dans un fichier. Ce programme peut être appelé via un script bash :
   ```bash
   ./script_bash_test_fonctions.bash
   ```
   Ce script effectue des recherches de mots en utilisant différents algorithmes et stocke les résultats dans des fichiers CSV dans le dossier `results`.

Pour rendre les scripts bash executable, on fait:
```
    make chmod_scripts

```

## Analyse des tests

Les graphiques représentant les tests des différents algorithmes sont stockés dans deux dossiers :
1. **`results_graphique_analyse`** : Ce dossier montre l'évolution de chaque algorithme en fonction de la taille des mots et de celle de l'alphabet.
2. **`results_graphique_moyenne`** : Ce dossier présente, en fonction de la taille de l'alphabet et de la longueur des mots, les performances moyennes de chaque algorithme.

Ces graphiques sont générés par deux programmes Python :
```bash
# Pour le premier dossier
python3 generate_analyse_finale.py

# Pour le second dossier
python3 generate_moyenne.py
```

### Bibliothèques nécessaires
Pour exécuter ces programmes Python, installez les bibliothèques suivantes :
```bash
pip install matplotlib pandas seaborn
```

## Organisation des fichiers

1. Tous les **algorithmes naïfs** sont regroupés dans un seul fichier.
2. Les autres algorithmes sont stockés dans des fichiers indépendants.
3. Les textes de **500 000 caractères** utilisés pour les recherches sont enregistrés dans le dossier `textes_500k`.
4. Les fichiers contenant les mots à rechercher dans les textes se trouvent dans le dossier `textes_mots_test`.
