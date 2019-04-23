#include <stdio.h>
#include <stdlib.h>

int menu(void) {
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

    return choix;
}
