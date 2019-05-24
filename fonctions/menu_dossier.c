#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../structures/utilisateur.h"

void menu_dossier(utilisateur util)
{   int i, choix;

    //dossiers
    for (i = 0; i <= util.num_dossiers - 1; i++){
        printf("%i. %s\n", i + 1, util.dossiers[i].nom);
    }

    //outils dossiers
    if (util.num_dossiers < 8){
        printf("%i. Creer un dossier\n", i + 1);
    }
    if (i > 3){
        printf("%i. Supprimer un dossier\n", i + 2);
    }

    printf("%i. Retour", i + 3);

    //choix
    printf("Veuillez entrer votre choix: ");
    scanf("%d", &choix);

    while (choix < 1 || choix > 3) {
        printf("\nChoix invalide\n");
        printf("Veuillez entrer votre choix: ");
        scanf("%d", &choix);
    }

    //vidage du buffer
    gets("");

    switch (choix) {
        //dossiers par défaut
        case 1 ... 3: ;
        break;

        // dossiers personnalisés, ou fin
        case 4: ;
        break;
        case 5: ;
        break;
        case 6: ;
        break;
        case 7: ;
        break;
        case 8: ;
        break;
        case 9: ;
        break;
        case 10: ;
        break;
        case 11: ;
        break;
    }
}
