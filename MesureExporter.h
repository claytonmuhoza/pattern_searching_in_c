#ifndef MESURE_EXPORTER_H
#define MESURE_EXPORTER_H
//fonction qui mesure le temps d'execution de l'algorithme passer en parametre et l'insert dans un fichier csv
void MesurerExporter(const char *texte, const char *mot, int (*recherche)(const char *, const char *), 
                         const char *algorithme, int taille_alphabet, int longueur_mot, const char *fichier_csv);    
#endif