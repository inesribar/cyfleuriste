
#ifndef MODEC_H
#define MODEC_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Client{
char nom[20];
char prenom[20];
char historique1[20];
int nb_achat;
}Client;

int creer_compte();
int modec() ;
int supprimer_compte() ;
int menuclient() ;

#endif