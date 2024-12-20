import os
import pandas as pd
import matplotlib.pyplot as plt

# Chemins des dossiers
input_dir = "results"
output_dir = "results_graphique_moyenne"

# Créer le dossier des graphiques s'il n'existe pas
os.makedirs(output_dir, exist_ok=True)

# Fonction pour générer le graphique pour un fichier CSV donné
def generate_graph(input_file, output_file, taille_mot, taille_alphabet):
    # Lecture du fichier CSV sans en-têtes
    df = pd.read_csv(input_file, header=None, names=["nom_algorithme", "temps", "nb_occurence"])
    
    # Agrégation des données : temps moyen pour chaque algorithme
    grouped = df.groupby("nom_algorithme")["temps"].mean().reset_index()
    
    # Trier les données pour un affichage ordonné (du plus lent au plus rapide)
    grouped = grouped.sort_values(by="temps", ascending=True)
    
    # Création du graphique
    plt.figure(figsize=(10, 6))
    plt.barh(grouped["nom_algorithme"], grouped["temps"], color="steelblue", edgecolor="black")
    
    # Titres et labels
    plt.title(f"Comparaison des temps moyens par algorithme\n(Taille mot: {taille_mot}, Taille alphabet: {taille_alphabet})", fontsize=16)
    plt.xlabel("Temps moyen (ms)", fontsize=14)
    plt.ylabel("Nom de l'algorithme", fontsize=14)
    
    # Ajouter les valeurs exactes au bout des barres
    for index, value in enumerate(grouped["temps"]):
        plt.text(value, index, f"{value:.2f} ms", va="center", ha="left", fontsize=10)

    # Ajout d'une grille discrète
    plt.grid(axis="x", linestyle="--", alpha=0.7)

    # Sauvegarder le graphique
    plt.tight_layout()  # Ajuster la disposition pour éviter les chevauchements
    plt.savefig(output_file)
    plt.close()

# Parcourir tous les fichiers CSV dans le dossier `results`
for file_name in os.listdir(input_dir):
    if file_name.endswith(".csv") and file_name.startswith("resultat_"):
        # Extraire taille_mot et taille_alphabet du nom du fichier
        parts = file_name.split("_")
        if len(parts) == 3:
            taille_mot, taille_alphabet = parts[1], parts[2].split(".")[0]
            output_file = os.path.join(output_dir, f"result_{taille_mot}_{taille_alphabet}.png")
            
            # Générer le graphique
            input_file = os.path.join(input_dir, file_name)
            generate_graph(input_file, output_file, taille_mot, taille_alphabet)
