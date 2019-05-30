#include <stdio.h>
#include <stdlib.h>
#include "get_entier.h"
#include "../structures/utilisateur.h"
#include "../constantes.h"

int menu_dossier(utilisateur util) {
    int i, choix;

    printf("\nDossiers:\n\n");

    //dossiers personnailsés
    for (i = 0; i < util.num_dossiers; i++) {
        printf("%i. %s\n", i + 1, util.dossiers[i].nom);
    }

    //outils dossiers
    if (util.num_dossiers < MAX_DOSSIERS) {
        printf("%d. Creer un dossier\n", util.num_dossiers + 1);
    }
    if (util.num_dossiers > 3) {
        printf("%d. Supprimer un dossier\n", util.num_dossiers + 2 - util.num_dossiers/MAX_DOSSIERS);
    }
    printf("%d. Retour\n\n", util.num_dossiers + 2 + (util.num_dossiers > 3 && util.num_dossiers < MAX_DOSSIERS));

    //choix
    printf("Veuillez entrer votre choix: ");
    choix = get_entier();

    while (choix < 1 || choix > util.num_dossiers + 2 + (util.num_dossiers > 3 && util.num_dossiers < MAX_DOSSIERS)) {
        printf("\nChoix invalide\n");
        printf("Veuillez entrer votre choix: ");
        choix = get_entier();
    }

    return choix;
}

