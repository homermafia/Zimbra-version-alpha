#include <stdio.h>
#include <stdlib.h>
#include "creer_compte.h"

void menu_demarrer(void) {
    int choix;

    printf("Zimbra version alpha\n");

    printf("1. Se connecter\n");
    printf("2. Creer un compte\n");
    printf("3. Quitter\n\n");

    printf("Veuillez entrer votre choix: ");
    scanf("%d", &choix);

    while (choix < 1 || choix > 3) {
        printf("\nChoix invalide\n");
        printf("Veuillez entrer votre choix: ");
        scanf("%d", &choix);
    }

    /* vier le buffer ici */

    switch (choix) {
        case 1: printf("Se connecter a ete choisi\n");
        break;
        case 2: creer_compte();
        break;
        default: printf("A bientot !\n");
    }
}
