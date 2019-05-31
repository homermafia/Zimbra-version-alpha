#include <stdio.h>
#include <stdlib.h>
#include "get_entier.h"
#include "supprimer_dossier.h"
#include "../structures/utilisateur.h"
#include "../constantes.h"

int menu_dossier(utilisateur *util) {
    int i, choix;

    printf("\nDossiers:\n\n");

    //dossiers personnailsés
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
        //affiche le dossier (*util).dossiers[choix]
    }
    else {
        if ((*util).num_dossiers < MAX_DOSSIERS && (*util).num_dossiers > 3) { /* Créer et supprimer sont affichés */
            switch (choix - (*util).num_dossiers) {
                case 1: { /*Créer*/
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
                    //supprimer dossier
                    return 1;
                }
                else {
                    return 0;
                }
            }
            else { /* Créer est affiché */
                if (choix == (*util).num_dossiers + 1) {
                    //creer dossier
                    return 1;
                }
                else {
                    return 0;
                }
            }
        }
    }

    return choix;
}

