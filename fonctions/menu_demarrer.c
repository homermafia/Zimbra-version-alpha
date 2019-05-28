#include <stdio.h>
#include <stdlib.h>
#include "creer_compte.h"
#include "connexion.h"
#include "menu_messagerie.h"
#include "get_entier.h"

void menu_demarrer(void) {
    int choix, succes;

    printf("Zimbra version alpha\n");

    printf("1. Se connecter\n");
    printf("2. Creer un compte\n");
    printf("3. Quitter\n\n");

    printf("Veuillez entrer votre choix: ");
    succes = get_entier(&choix);

    while (succes == 0 || choix < 1 || choix > 3) {
        printf("\nChoix invalide\n");
        printf("Veuillez entrer votre choix: ");
        succes = get_entier(&choix);
    }

    switch (choix) {
        case 1: {
            menu_messagerie(connexion());
        };
        break;
        case 2: {
            creer_compte();
            menu_demarrer();
        };
        break;
        default: printf("A bientot !\n");
    }
}
