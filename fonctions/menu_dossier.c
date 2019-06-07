#include <stdio.h>
#include <stdlib.h>
#include "get_entier.h"
#include "creer_dossier.h"
#include "supprimer_dossier.h"
#include "../structures/utilisateur.h"
#include "../structures/dossier.h"
#include "../constantes.h"
#include "affiche_messages.h"

int menu_dossier(utilisateur *util) {
    int i, choix, page;

    //affichage des dossiers
    printf("\nDossiers:\n\n");
    for (i = 0; i < (*util).num_dossiers; i++) {
        printf("%i. %s\n", i + 1, (*util).dossiers[i].nom);
    }

    //outils dossiers
    if ((*util).num_dossiers < MAX_DOSSIERS) {
        printf("%d. Creer un dossier\n", (*util).num_dossiers + 1);
    }
    if ((*util).num_dossiers > 3) {
        printf("%d. Supprimer un dossier\n", (*util).num_dossiers + 2 - (*util).num_dossiers/MAX_DOSSIERS);
    }
    printf("%d. Retour\n\n", (*util).num_dossiers + 2 + ((*util).num_dossiers > 3 && (*util).num_dossiers < MAX_DOSSIERS));

    //choix
    printf("Veuillez entrer votre choix: ");
    choix = get_entier();

    while (choix < 1 || choix > (*util).num_dossiers + 2 + ((*util).num_dossiers > 3 && (*util).num_dossiers < MAX_DOSSIERS)) {
        printf("\nChoix invalide\n");
        printf("Veuillez entrer votre choix: ");
        choix = get_entier();
    }

    if (choix <= (*util).num_dossiers) {
        page = 1;

        do {
            page = affiche_messages(util, &(*util).dossiers[choix - 1], page);
        }
        while (page > 0);
    }
    else {
        if ((*util).num_dossiers < MAX_DOSSIERS && (*util).num_dossiers > 3) { /* Créer et supprimer sont affichés */
            switch (choix - (*util).num_dossiers) {
                case 1: { /*Créer*/
                    creer_dossier(util);
                    return 1;
                };
                break;
                case 2: { /*Supprimer*/
                    supprimer_dossier(util);
                    return 1;
                };
                break;
                default: return 0; /*Retour*/
            }
        }
        else {
            if ((*util).num_dossiers > 3) { /* Supprimer est affiché */
                if (choix == (*util).num_dossiers + 1) {
                    supprimer_dossier(util);
                    return 1;
                }
                else {
                    return 0;
                }
            }
            else { /* Créer est affiché */
                if (choix == (*util).num_dossiers + 1) {
                    creer_dossier(util);
                    return 1;
                }
                else {
                    return 0;
                }
            }
        }
    }

    return 1;
}

