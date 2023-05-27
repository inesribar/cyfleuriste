#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "historique.h"
#include "modec.h"
#include "modegestion.h"

// Fonction pour créer un nouveau compte utilisateur
int creer_compte() {
  Client client;
  char nom_fichier[45]; // +5 pour ajouter ".txt" et le caractère null
    
  // Saisie des informations utilisateur
  printf("\nNom : ");
  scanf("%s", client.nom);
  printf("Prénom : ");
  scanf("%s", client.prenom);
    
  // Création du nom de fichier en concatenant nom et prénom de l'utilisateur
  sprintf(nom_fichier, "%s_%s.txt", client.nom, client.prenom);
    
  // Ouverture du fichier en écriture
  FILE* fichier = fopen(nom_fichier, "w");

  if (fichier == NULL) {
    printf("Erreur lors de l'ouverture du fichier %s\n", nom_fichier);
  }
    
  // Fermeture du fichier
  fclose(fichier);
    
  printf("\nCompte créé avec succès.\n\n\n");

  menuclient() ;
  
  return 0;

}