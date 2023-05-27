#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "modec.h"

int supprimer_compte() {
  Client client;
  char nom_fichier[45];
    printf("rappelez votre nom :");
    scanf("%s", client.nom);
    printf ("\n votre prenom : ");
    scanf("%s", client.prenom);

    //suprrimer le fichier après lui avoir donné son nom
    sprintf(nom_fichier, "%s_%s.txt", client.nom, client.prenom);
    remove(nom_fichier);
    printf("compte supprimé avec succès");
  return 0;
}



