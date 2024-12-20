# Importation des bibliothèques
import os
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# Chemins des dossiers
input_dir = "results"
output_dir = "results_graphique_analyse"

# Créer le dossier des graphiques s'il n'existe pas
os.makedirs(output_dir, exist_ok=True)

# Fonction pour analyser les fichiers CSV et générer des conclusions
def analyze_csv_files():
    all_data = []

    # Parcourir tous les fichiers CSV dans le dossier `results`
    for file_name in os.listdir(input_dir):
        if file_name.endswith(".csv") and file_name.startswith("resultat_"):
            # Extraire taille_mot et taille_alphabet du nom du fichier
            parts = file_name.split("_")
            if len(parts) == 3:
                taille_mot, taille_alphabet = parts[1], parts[2].split(".")[0]
                input_file = os.path.join(input_dir, file_name)
                
                # Lecture du fichier CSV sans en-têtes
                df = pd.read_csv(input_file, header=None, names=["nom_algorithme", "temps", "nb_occurence"])
                df["taille_mot"] = int(taille_mot)
                df["taille_alphabet"] = int(taille_alphabet)
                all_data.append(df)
    
    # Combiner toutes les données en un seul DataFrame
    combined_df = pd.concat(all_data, ignore_index=True)
    
    # Multiplier le temps par 1000 pour qu'il soit plus visible
    combined_df["temps"] = combined_df["temps"] 
    
    # Agrégation des données : temps moyen pour chaque algorithme, taille de mot et taille d'alphabet
    grouped = combined_df.groupby(["nom_algorithme", "taille_mot", "taille_alphabet"])["temps"].mean().reset_index()
    
    # Générer un graphique pour chaque algorithme
    for algorithme, group in grouped.groupby("nom_algorithme"):
        plt.figure(figsize=(12, 8))
        
        # Graphique en ligne
        sns.lineplot(
            data=group,
            x="taille_mot",
            y="temps",
            hue="taille_alphabet",
            palette="viridis",
            marker="o",
        )
        
        # Titres et labels
        plt.title(f"Performance de l'algorithme {algorithme}", fontsize=16)
        plt.xlabel("Taille du mot", fontsize=14)
        plt.ylabel("Temps moyen (ms)", fontsize=14)
        plt.legend(title="Taille de l'alphabet", fontsize=12, title_fontsize=14, loc="upper left")
        
        # Sauvegarder le graphique
        output_file = os.path.join(output_dir, f"analyse_{algorithme}.png")
        plt.tight_layout()  # Ajuster la disposition pour éviter les chevauchements
        plt.savefig(output_file)
        plt.close()

   

# Appeler la fonction d'analyse
analyze_csv_files()
