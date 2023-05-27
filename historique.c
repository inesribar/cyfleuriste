#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "historique.h"

int afficher_historique(Client client){
  char nom_fichier[30];
  
  FILE *fichier_client;
  sprintf(nom_fichier, "%s_%s.txt", client.nom , client.prenom);
  fichier_client = fopen(nom_fichier, "r");

  if (fichier_client == NULL){
    printf("Impossible d'ouvrir le fichier %s\n", nom_fichier);
    return -1;
  }

  // Compter le nombre de lignes présentes dans le fichier
  int nb_lignes = 0;
  char c;
  while ((c = fgetc(fichier_client)) != EOF){
    if (c == '\n'){
      nb_lignes++ ;
    }
  }
  //replacer le curseur
  rewind(fichier_client);

  //retourner aux lignes que nous voulons afficher
  int ancien_historique = (nb_lignes >= 12) ? nb_lignes - 12 : 0 ;

  for (int i = 0; i < ancien_historique; i++){
    while ((c = fgetc(fichier_client)) != '\n' && c != EOF);
  }

  //afficher les lignes
  char ligne[1000];
  while (fgets(ligne,1000,fichier_client) != NULL){
    printf("%s", ligne);
  }

  fclose(fichier_client);
  return 0 ;
}

int enregistrer_historique(Produit fleur,Client client) {
  
  char nom_fichier[30];
  // Ouvrir le fichier du client en mode "a" pour ajouter à la fin du fichier
  sprintf(nom_fichier, "%s_%s.txt", client.nom,client.prenom);
  FILE *fichier_client = fopen(nom_fichier, "a");
    
  if (fichier_client == NULL) {
    printf("Impossible d'ouvrir le fichier %s\n", nom_fichier);
    return 1;
  }

  // Écrire l'information d'achat dans le fichier du client
  fprintf(fichier_client, "Produit : %s\n", fleur.nom);
  fprintf(fichier_client, "Quantité : %d\n", fleur.quantite);
  fprintf(fichier_client, "Référence : %d\n", fleur.reference);
  fprintf(fichier_client, "Prix : %.2f\n", fleur.prix);

  // Fermer le fichier du client
  fclose(fichier_client);

  printf("achat enregistré\n\n");
  return 0 ;

}