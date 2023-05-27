#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modegestion.h"
#define MAX_PRODUCTS 1000


// fonctions

void tri_selection_et_affichage(Produit produits[], int taille) {
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
printf("Produits triés dans l'ordre croissant selon leur quantité :\n");

for (i = 0; i < taille; i++) {
printf("Produit : %s\n", produits[i].nom);
printf("Quantité: %d\n", produits[i].quantite);
printf("Référence : %d\n", produits[i].reference);
printf("Prix : %f\n\n", produits[i].prix);
}
}


// tri stock à 0
int tri() {
FILE *fichier = fopen("stock.txt", "r+");
if (fichier == NULL) {
printf("Erreur lors de l'ouverture du fichier de stock.\n");
return 1;
}

char ligne[100];
char nom[50];
int quantite;
int reference;
float prix;

printf("Produits avec stock à 0 :\n");
while (fgets(ligne, sizeof(ligne), fichier)) {
if (strncmp(ligne, "nom du produit: ", 1) == 0) {
sscanf(ligne + 16, "%s", nom);

fgets(ligne, sizeof(ligne), fichier);
sscanf(ligne + 10, "%d", &quantite);

fgets(ligne, sizeof(ligne), fichier);
sscanf(ligne + 11, "%d", &reference);

fgets(ligne, sizeof(ligne), fichier);
sscanf(ligne + 17, "%f",&prix);

if (quantite == 0) {
printf("- %s\n", nom);
}
}
}

fclose(fichier);
return 0;
}


// fonction supprimer

/*Produit flowers;
int supprimer( Produit flowers[], char flowerName[]) {
int i, j, found = 0;


for (i = 0; i < MAX_PRODUCTS; i++){
//on compare le nom de la fleur chercher et celui du catalogue 
if (strcmp(flowers[i].nom, flowerName) == 0) {
found = 1;
break;
}
}

if(!found) {
printf("Flower not found.\n");
return 0;
}

for (j = i; j < MAX_PRODUCTS - 1; j++) {
strcpy(flowers[j].nom, flowers[j+1].nom);
strcpy(flowers[j].reference, flowers[j+1].reference);
flowers[j].quantite= flowers[j+1].quantite;
flowers[j].prix=flowers[j+1].prix;
//flowers[j].taille=flowers[j+1].taille;
}

printf("Flower %s deleted.\n", flowerName);
return 1;
}*/



//-----------------------------------------
//-----------------------------------------
//-----------------------------------------

int modegestion() {
int choix;
Produit produits[MAX_PRODUCTS];
int nbProduits = 0;

printf("*********CY-Fleuriste- Employé  ************\n");
printf("\n-------------- Etat magasin --------------\n");
printf("\n--------------     Menu     --------------\n");

printf("\033[31m"); // Texte en rouge
printf("Alerte approvisionnement de ces produits :\n\n");
printf("\033[0m"); // Réinitialisation des attributs d'affichage
tri();

printf("------------------------------------\n \n");

printf("\n. Consulter le stock : tapez 1\n");
printf(". Voir liste des clients : tapez 2\n");
printf(". Ajouter le stock d'un produit : tapez 3\n");
printf(". Rechercher une fleur : tapez 4\n");
printf(". Supprimer un produit : tapez 5\n");
printf("--> Que voulez-vous faire ? : ");
scanf("%d", &choix);

if (choix == 1) {
// Ouvrir le fichier de stock pour lire les données
FILE *fichier = fopen("stock.txt", "r");
if (fichier == NULL) {
printf("Erreur lors de l'ouverture du fichier de stock.\n");
return 1;
}
// lire et stock tab
char ligne[50];
while (fgets(ligne, sizeof(ligne), fichier)) {
if (strncmp(ligne, "nom du produit:", 15) == 0) {
sscanf(ligne + 16, "%s", produits[nbProduits].nom);

//fgets(ligne, sizeof(ligne), fichier); // Lire la ligne vide

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


// Fermer le fichier de stock
fclose(fichier);

// Appeler la fonction tri_selection_et_affichage pour trier les produits
tri_selection_et_affichage(produits, nbProduits);
}

else if (choix == 2) {
FILE *fichier = fopen("client.txt", "r");
if (fichier == NULL) {
printf("Erreur lors de l'ouverture du fichier client.\n");
return 1;
}

char ligne[100];
printf("\nContenu du fichier de client :\n");
while (fgets(ligne, sizeof(ligne), fichier)) {
printf("%s", ligne);
}

fclose(fichier);
}
else if (choix == 3) {
printf("Vous avez choisi d'ajouter un nouveau produit.\n");
printf("Entrez le nom du produit : ");
scanf("%s", produits[nbProduits].nom);

printf("Entrez la quantité disponible : ");
scanf("%d", &produits[nbProduits].quantite);

printf("Entrez la référence : ");
scanf("%d", &produits[nbProduits].reference);

printf("Entrez le prix du produit : ");
scanf("%f", &produits[nbProduits].prix);
	
	printf("Entrez la taille du produit : ");
scanf("%s", produits[nbProduits].taille);

// Ouvrir le fichier de stock en mode append pour ajouter le nouveau produit
FILE *fichier = fopen("stock.txt", "a");
if (fichier == NULL) {
printf("Erreur lors de l'ouverture du fichier de stock.\n");
return 1;
}

fprintf(fichier, "nom du produit: %s\n", produits[nbProduits].nom);
fprintf(fichier, "quantite: %d\n", produits[nbProduits].quantite);
fprintf(fichier, "reference: %d\n", produits[nbProduits].reference);
fprintf(fichier, "prix du produit : %.2f \n", produits[nbProduits].prix);
fprintf(fichier, "taille : %s\n", produits[nbProduits].taille);

// Incrémenter le nombre de produits
nbProduits++;

// Fermer le fichier de stock
fclose(fichier);
}
else if (choix == 4) {
char search_name[20];

printf("Quelle est la fleur que vous recherchez ? ");
scanf("%s", search_name);

FILE *fichier = fopen("stock.txt", "r");
if (fichier == NULL) {
printf("Impossible d'ouvrir le fichier stock.txt.\n");
return 1;
}

int found = 0;
Produit f;

char ligne[100];
while (fgets(ligne, sizeof(ligne), fichier)) {
if (strncmp(ligne, "nom du produit:", 15) == 0) { // 1 nom 2 quantité 3 ref 4prix prendre une marge pour les calculs. essaie avec 16 ne fonctionne que avec 4 produits
sscanf(ligne + 16, "%[^\n]", f.nom);

fgets(ligne, sizeof(ligne), fichier); // Lire la quantité
sscanf(ligne + 10, "%d", &f.quantite);
fgets(ligne, sizeof(ligne), fichier); // Lire la référence
sscanf(ligne + 11, "%d", &f.reference);
fgets(ligne, sizeof(ligne), fichier); // Lire la référence
sscanf(ligne + 7, "%s", f.taille);

fgets(ligne, sizeof(ligne), fichier); // Lire le prix
sscanf(ligne + 17, "%f", &f.prix);

if (strcmp(f.nom, search_name) == 0) {
printf("Fleur trouvée : %s\n", f.nom);
printf("Quantité : %d\n", f.quantite);
printf("Référence : %d\n", f.reference);
printf("Prix : %.2f\n", f.prix);
found = 1;
break;
}
}
}

if (!found) {
printf("Fleur introuvable.\n");
}

fclose(fichier);
}

else if(choix==5){
  char fleur[20];
FILE* fichier=fopen("stock.txt","r""w");
printf("quel fleur voulez vous supprimer");
scanf("%s\n",fleur);
if (fichier == NULL) {
printf("Impossible d'ouvrir le fichier stock.txt.\n");
return 1;
}

int found = 0;
Produit f;

char ligne[100];
while (fgets(ligne, sizeof(ligne), fichier)) {
if (strncmp(ligne, "nom du produit:", 15) == 0) { 
sscanf(ligne + 16, "%[^\n]", f.nom);

fgets(ligne, sizeof(ligne), fichier); // Lire la quantité
sscanf(ligne + 10, "%d", &f.quantite);
fgets(ligne, sizeof(ligne), fichier); // Lire la référence
sscanf(ligne + 11, "%d", &f.reference);
fgets(ligne, sizeof(ligne), fichier); // Lire la référence
sscanf(ligne + 7, "%s", f.taille);

fgets(ligne, sizeof(ligne), fichier); // Lire le prix
sscanf(ligne + 17, "%f", &f.prix);

if (strcmp(f.nom, fleur) == 0) {
printf("Fleur trouvée : %s\n", f.nom);
printf("Quantité : %d\n", f.quantite);
printf("Référence : %d\n", f.reference);
printf("Prix : %.2f\n", f.prix);
found = 1;
break;
}
}
int option;
printf("etes vous sur de vouloir supprimer? 1 pour oui 2 pour annuler\n ");
scanf("%d",&option);
  
switch(option){
case 1:
 /*
 
 */

break;
case 2:
printf("suppression annulée");
  break;
  default:
  return 0;
  break;
}
}

if (!found) {
printf("Fleur introuvable.\n");
}


}
	
	else {
printf("Choix invalide. Veuillez choisir une option valide.\n");
return 1;
}
return 0;
}
