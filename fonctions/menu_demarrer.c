#include <stdio.h>
#include <stdlib.h>
#include "get_entier.h"
#include "menu_messagerie.h"
#include "connexion.h"
#include "creer_compte.h"
#include "../structures/utilisateur.h"
#include "../constantes.h"

int menu_demarrer(void) {
    int choix;

    printf("\n1. Se connecter\n");
    printf("2. Creer un compte\n");
    printf("3. Quitter\n\n");

    printf("Veuillez entrer votre choix: ");
    choix = get_entier();

    while (choix < 1 || choix > 3) {
        printf("\nChoix invalide\n");
        printf("Veuillez entrer votre choix: ");
        choix = get_entier();
    }

    switch (choix) {
        case 1: {
            utilisateur util = connexion();
            choix = menu_messagerie(util);
            while (choix == 1) {
                choix = menu_messagerie(util);
            }
            return 1;
        };
        break;
        case 2: {
            creer_compte();
            return 1;
        };
        break;
        default: return 0;
    }
}
