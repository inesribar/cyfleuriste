Notre projet est CY-SHOP.
Nous avons décidé de créer une boutique de fleurs.

Le code démarre par le menu principal : main.c
Celui ci permettra  à la personne qui exécute le code de choisir si il est client ou employé et de s'identifier.

Notre code ce divise donc en deux :

Partie client de notre code :
- Un mode client : modec.c et modec.h
Fonctionalité: 
Permet de s'identifier dans la base de donnée et de créer un fichier avec l'historique d'achat.
Permet de créer un compte.
- Un menu client: menuclient.c
Fonctionalité: 
- Permet de consulté le stock
- Permet d'acheté un produit 

- Historique d'achat du client : historique.c et historique.h
Fonctionalité : 
-Enrengistre les achats.

Partie employé:
Un mode gestion : modegestion.c et modegestion.h
Fonctionnalité :
Affiche avec un message d'alerte les produits en manque d'apprivisionnement.
Permet de consulté les fleurs dans l'odre croissant des quantités.
Permet de supprimer les fleurs recherchés.
Permet d'ajouter une fleur.
