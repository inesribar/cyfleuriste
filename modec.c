#include <stdio.h>
#include <stdlib.h>
#define MAX_CLIENTS 100
#include "modec.h"
#include <string.h>

// Mode client : choix de créer un compte ou de s'identifier si il est déja client

int modec() {
  Client client;
	FILE *fichier;
	fichier = fopen("client.txt", "a+");

  if (fichier == NULL) {
    printf("Impossible d'ouvrir le fichier.\n");
    exit(1);
  }


	// problème d'identification à revoir //

  Client clients[MAX_CLIENTS];
  int nb_clients = 0;
  int choix;
  int reponse;
  char nom[50];
  char prenom[50];

	// creation d'un attribut client
	Client vraiclient;
  printf("\033[31m");
  printf("********** CY-Fleuriste Client **********\n\n");
  printf("\033[0m");
	
  printf("    > se connecter : 1\n");
  printf("    > créer un compte : 2\n");
  printf("    > ");
  scanf("%d", &reponse);

if (reponse == 1) {
int found = 0;
char search_name[100];
char search_firstname[100];

char ligne[100];

printf("Quel est votre nom : ");
scanf("%s",search_name );
printf("Quel est votre prénom : ");
scanf("%s", search_firstname);

FILE *fichier = fopen("client.txt", "r");
if (fichier == NULL) {
printf("Impossible d'ouvrir le fichier looool \n");
return 1;
}

while (fgets(ligne, sizeof(ligne), fichier)) {
if (strncmp(ligne, "Nom :", 5) == 0) {
sscanf(ligne + 6, "%[^\n]", vraiclient.nom); // lire le nom
fgets(ligne, sizeof(ligne), fichier); // Lire la ligne suivante (prénom)
sscanf(ligne + 10, "%s", vraiclient.prenom); // lire le prénom

if (strcmp(search_name, vraiclient.nom) == 0 && strcmp(search_firstname, vraiclient.prenom) == 0) {
	printf("Nom : %s\n", vraiclient.nom);
	printf("Prénom : %s\n", vraiclient.prenom);
	found = 1;
    //lire_historique (client.nom_client.prenom);
		menuclient();
	break;
}

}	

}

if (!found) {
printf("Erreur : client introuvable!-veuillez creer un compte !!  \n");
	 Client nouveau_client;
 
    printf("\n>Nom : ");
    scanf("%s", nouveau_client.nom);

    printf(">Prénom : ");
    scanf("%s", nouveau_client.prenom);

    clients[nb_clients] = nouveau_client;
    nb_clients++;
	
    fprintf(fichier, "Nom : %s\n", nouveau_client.nom);
    fprintf(fichier, "Prénom : %s\n", nouveau_client.prenom);

   // fclose(fichier);
    creer_compte() ;
	//creer_compte();
	
}

fclose(fichier);

}
else if (reponse == 2) {
  	 Client nouveau_client;
	
    printf("\n>Nom : ");
    scanf("%s", nouveau_client.nom);

    printf(">Prénom : ");
    scanf("%s", nouveau_client.prenom);

    clients[nb_clients] = nouveau_client;
    nb_clients++;
	
    fprintf(fichier, "Nom : %s\n", nouveau_client.nom);
    fprintf(fichier, "Prénom : %s\n", nouveau_client.prenom);

    fclose(fichier);
    creer_compte() ;
  
  }

 

return 0;
}
