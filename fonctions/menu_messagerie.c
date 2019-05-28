#include <stdio.h>
#include <stdlib.h>
#include "../fonctions/menu_dossier.h"
#include "../fonctions/menu_demarrer.h"
#include "../structures/utilisateur.h"

void menu_messagerie(utilisateur util) {
    int choix;
    printf("1. Consulter vos messages\n2. Envoyer un message\n3. Se deconnecter\n\n");
    //choix
    printf("Veuillez entrer votre choix: ");
    scanf("%d", &choix);

    while (choix < 1 || choix > 3) {
        printf("\nChoix invalide\n");
        printf("Veuillez entrer votre choix: ");
        scanf("%d", &choix);
    }
    switch(choix){
        case 1: menu_dossier(util);
        break;
        case 2: /*evoyer*/;
        break;
        case 3: menu_demarrer();
        break;
    }


}
