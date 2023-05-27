// Projet  de course CY-Shop
// Ines Ribar Kanto Andriambololo-Nivo Berlyse

#include <stdio.h>
#include <stdlib.h>
#include "modec.h"
#include "modegestion.h"

/*void vide_buffer(){
  while(getchar() != '\n'){
    printf("\n mauvais choix");
    
  }
}*/
//Accueil choix du mode client ou Employé
int main(void) {
  int choix;
	
	printf("\033[31m"); // Texte en rouge
  printf("\n\n Bonjour et bienvenue chez CY Fleuriste \n\n");
	printf("\033[0m"); // couleur noir
  printf("Identifiez vous : \n");
  printf("Client tapez 1 ||||| Employé tapez 2 : \n");

  scanf("%d", &choix);

  if (choix == 1) {
    printf("\n\nVous êtes dans le mode client\n");
		modec();
    


  } else if (choix == 2) {
    printf("\n\nVous êtes dans le mode employé\n");
		modegestion();
   
  } else {
    
    printf("Vous n'avez pas choisi de mode valide\n");
  
  }

  return 0;
}
