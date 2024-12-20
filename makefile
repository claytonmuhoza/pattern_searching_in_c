# Variables
CC = gcc
CFLAGS = -Wall -Wextra -g
OBJ = main.o algorithme_recherche_naif.o morris_pratt.o knuth_morris_pratt.o boyer_moore.o horspool.o quick_search.o
TARGET = programme_recherche
Generateur = generateur_mots
# Règle par défaut
all: $(TARGET) $(Generateur)
# Compilation du programme
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)
# Compilation du generateur de mots
$(Generateur): generateur_mots.o
	$(CC) $(CFLAGS) -o $(Generateur) generateur_mots.o
# Compilation des fichiers objets du generateur de mon
generateur_mots.o: generateur_mots.c generateur_mots.h
	$(CC) $(CFLAGS) -c generateur_mots.c
# Compilation des fichiers objets de main
main.o: main.c algorithme_recherche_naif.h
	$(CC) $(CFLAGS) -c main.c 
morris_pratt.o: morris_pratt.c morris_pratt.h
	$(CC) $(CFLAGS) -c morris_pratt.c
algorithme_recherche_naif.o: algorithme_recherche_naif.c algorithme_recherche_naif.h
	$(CC) $(CFLAGS) -c algorithme_recherche_naif.c
knuth_morris_pratt.o: knuth_morris_pratt.c knuth_morris_pratt.h
	$(CC) $(CFLAGS) -c knuth_morris_pratt.c
boyer_moore.o: boyer_moore.c boyer_moore.h
	$(CC) $(CFLAGS) -c boyer_moore.c
horspool.o: horspool.c horspool.h
	$(CC) $(CFLAGS) -c horspool.c
quick_search.o: quick_search.c quick_search.h
	$(CC) $(CFLAGS) -c quick_search.c
# Nettoyage des fichiers objets et exécutables
clean:
	rm -f $(OBJ) $(TARGET) $(Generateur)

# Règle pour nettoyer tout
distclean: clean
	rm -f $(TARGET)
# Rendre les fichiers script_bash_generateur_500k exécutables
chmod_scripts:
	chmod +x script_bash_generateur_500k.bash
	chmod +x script_bash_generateur_mots_test.bash
	chmod +x script_bash_test_fonctions.bash