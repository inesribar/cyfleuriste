#ifndef MODEGESTION_H
#define MODEGESTION_H
#include <stdio.h>

// Structure pour représenter un produit
typedef struct {
    char nom[100];
    int quantite;
    int reference;
    float prix;
char taille[10];
} Produit;

// Déclaration de la fonction de tri et d'affichage
void tri_selection_et_affichage(Produit produits[], int taille);
int tri();
int modegestion() ;
int menuclient();

#endif
