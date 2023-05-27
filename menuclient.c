#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "historique.h"
#include "modegestion.h"
#include "modec.h"


#define MAX_PRODUCTS 1000


void tri_selection_affichage(Produit produits[], int taille) {
  int i, j, min_index;
  Produit temp;

  for (i = 0; i < taille - 1; i++) {
    min_index = i;

    for (j = i + 1; j < taille; j++) {
      if (produits[j].quantite < produits[min_index].quantite) {
        min_index = j;
      }
    }

    // Échange des produits
    temp = produits[i];
    produits[i] = produits[min_index];
    produits[min_index] = temp;
  }

  // Affichage des produits triés
  printf("/n");

  for (i = 0; i < taille; i++) {
    printf("Produit : %s\n", produits[i].nom);
    printf("Quantité: %d\n", produits[i].quantite);
    printf("Référence : %d\n", produits[i].reference);
    printf("Prix : %f\n\n", produits[i].prix);
  }
}


int achatfleurref(Client client){
  int achatref;
  printf("reference de la fleur :\n ");
  scanf("%d", &achatref);

  FILE *fichier = fopen("stock.txt", "r");
  if (fichier == NULL) {
    printf("Impossible d'ouvrir le fichier stock.txt. \n");
  }

  int found = 0;
  Produit fleur;

  char ligne[200];
  while (fgets(ligne, sizeof(ligne), fichier)) {
    if (strncmp(ligne, "reference du produit:", 15) == 0) { 
      fleur.reference = atoi(ligne + 16);

      fgets(ligne, sizeof(ligne), fichier); // Lire la quantité
      sscanf(ligne + 10, "%d", &fleur.quantite);
      fleur.quantite=fleur.quantite-1;
      fgets(ligne, sizeof(ligne), fichier); // Lire la référence
      sscanf(ligne + 12, "%d", &fleur.reference);
      fgets(ligne, sizeof(ligne), fichier); // Lire la référence
      sscanf(ligne + 12, "%s", fleur.taille);
      fgets(ligne, sizeof(ligne), fichier); // Lire le prix
      sscanf(ligne + 10, "%f", &fleur.prix);

      if (fleur.reference == achatref) {
	       printf("vous avez acheté : %s\n", fleur.nom);
	       printf("Quantité : %d\n", fleur.quantite);
	       printf("Référence : %d\n", fleur.reference);
	       printf("Prix : %.2f\n", fleur.prix);
         //enregistrer_historique(fleur, client);
	       found = 1;
	       break;
      }
    }
  }
  

  if (!found) {
    printf("Fleur introuvable.\n");
  }

  fclose(fichier);
  return 0;
  
}
  

int achatfleurnom (Client client){
  char achatnom[20];
  int quantité;
  printf("nom de la fleur :\n ");
  scanf("%s", achatnom);
  printf("quantité de  :\n ");
  scanf("%d", &quantité);

  FILE *fichier = fopen("stock.txt", "r");
  if (fichier == NULL) {
    printf("Impossible d'ouvrir le fichier stock.txt.\n");
    
  }

  int found = 0;
  Produit fleur;

  char ligne[200];
  while (fgets(ligne, sizeof(ligne), fichier)) {
    if (strncmp(ligne, "nom du produit:", 15) == 0) { 
      sscanf(ligne + 16, "%[^\n]", fleur.nom);

      fgets(ligne, sizeof(ligne), fichier); // Lire la quantité
      sscanf(ligne + 10, "%d", &fleur.quantite);
      
     // fleur.quantite=fleur.quantite;
      fgets(ligne, sizeof(ligne), fichier); // Lire la référence
      sscanf(ligne + 12, "%d", &fleur.reference);
      fgets(ligne, sizeof(ligne), fichier); // Lire la taille
      sscanf(ligne + 12, "%s", fleur.taille);
      fgets(ligne, sizeof(ligne), fichier); // Lire le prix
      sscanf(ligne + 11, "%f", &fleur.prix);

      if (strcmp(fleur.nom, achatnom) == 0) {
       
	     printf("vous voulez achéter: %s\n", fleur.nom);
	      printf("Quantité : %d\n", quantité);
	      printf("Référence : %d\n", fleur.reference);
	      printf("Prix : %.2f\n", fleur.prix);
        
        //enregistrer_historique(fleur, client);
        found = 1;
        int choix;
        printf("souhaiter vous valider l'achat?");
        printf("taper 1 pour oui || 2 pour non");
        scanf("\n%d",&choix);
      if (choix==1){
         int q=fleur.quantite-quantité;
          if(q<0){
            printf("desolé la quantité en  stock est insufisant");
            break;
          }
          else{
          char nom[20];
            char prenom[20];
          printf("achat enrégistré,Merci d'etre passé!!");
            //historique();
        
          break;
      }
      }
        else{
          printf("annulation de l'achat");
        }
      
    
      }
       
    
    }

  }

  if (!found) {
    printf("Fleur introuvable.\n");
    return 1;
  
  }

  fclose(fichier);
  return 0;
}
  
int menuclient() {
  Client client ;
  int choix;
  Produit produits[MAX_PRODUCTS];
  int nbProduits = 0;

  
  printf("\033[31m"); // 
  printf("\n********** menu client ********** \n\n\n");
	printf("\033[0m"); 

  afficher_historique(client);
  
  printf("    > afficher le catalogue : 1\n ");
  printf("    > acheter une fleur : 2\n");
  printf("    > supprimer son compte : 3\n");
  scanf("%d", &choix);

  if (choix == 1) {
    // Ouvrir le fichier de stock pour lire les données
    FILE *fichier = fopen("stock.txt", "r");
    if (fichier == NULL) {
      printf("Erreur lors de l'ouverture du fichier de stock.\n");
    }

    // lire et stocker les données du fichier
    char ligne[50];
    while (fgets(ligne, sizeof(ligne), fichier)) {
      if (strncmp(ligne, "nom du produit:", 15) == 0) {
        sscanf(ligne + 16, "%s", produits[nbProduits].nom);

        fgets(ligne, sizeof(ligne), fichier); // Lire la quantité
        sscanf(ligne + 10, "%d", &produits[nbProduits].quantite);

        fgets(ligne, sizeof(ligne), fichier); // Lire la référence
        sscanf(ligne + 11, "%d", &produits[nbProduits].reference);

        fgets(ligne, sizeof(ligne), fichier); // Lire le prix
        sscanf(ligne + 17, "%f", &produits[nbProduits].prix);

        fgets(ligne, sizeof(ligne), fichier); // Lire la taille
        sscanf(ligne + 17, "%s", produits[nbProduits].taille);
        nbProduits++;
      }
    }
    fclose(fichier);

    // Appeler la fonction tri_selection_et_affichage pour trier les produits
    tri_selection_affichage(produits, nbProduits);
    menuclient();
    
  } 
  
  else if (choix == 2) {
    int option;
    printf("  > rechercher la fleur par le nom : 1 \n");
    printf("  > rechercher la fleur par la référence : 2\n");
    scanf("%d", &option);

    if (option == 1) {
      achatfleurnom(client);
    } else if (option == 2) {
      achatfleurref(client);
    } else {
      printf("mauvaise saisie");
      return 1;
    }
    
    afficher_historique(client);
    
  } 
  
  else if (choix == 3) {
    supprimer_compte();
  }
else if (choix == 4) {
   return 0;
// Retourner au menu principal
  } 

  else {
    printf("Mauvaise saisie.\n");
  }

  return 0; // Continuer à exécuter la fonction
}
