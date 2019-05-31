#include <stdio.h>
#include <stdlib.h>
#include "get_entier.h"
#include "menu_dossier.h"
#include "../structures/utilisateur.h"

int menu_messagerie(utilisateur *util) {
    int choix;
    printf("\n1. Consulter vos messages\n2. Envoyer un message\n3. Se deconnecter\n\n");

    //choix
    printf("Veuillez entrer votre choix: ");
    choix = get_entier();

    while (choix < 1 || choix > 3) {
        printf("\nChoix invalide\n");
        printf("Veuillez entrer votre choix: ");
        choix = get_entier();
    }

    switch (choix) {
        case 1: {
            do {
                choix = menu_dossier(util);
            }
            while (choix == 1);
            return 1;
        }
        break;
        case 2: {
            /*evoyer*/
            return 1;
        }
        break;
        case 3: return 0;
        break;
    }

    return choix;
}
