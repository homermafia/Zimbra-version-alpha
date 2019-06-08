#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_entier.h"
#include "convertir_date.h"
#include "repondre_message.h"
#include "supprimer_message.h"
#include "deplacer_message.h"
#include "bloquer_exp.h"
#include "maj_fichier.h"
#include "../structures/utilisateur.h"
#include "../structures/dossier.h"
#include "../structures/message.h"

int affiche_message(utilisateur *util, message *msg) {
    int choix;
    char date[20];

    if ((*msg).lu == 0) {
        (*msg).lu = 1;
        maj_fichier(util);
    }

    convertir_date((*msg).date, date);

    printf("\nMessage\n\n");

    if (strcmp((*msg).expediteur, (*util).nom) == 0) {
       printf("Destinataire: %s\n", (*msg).destinataire);
    }
    else {
        printf("Expediteur: %s\n", (*msg).expediteur);
    }

    printf("Envoye le: %s\nDossier: %s\nObjet: %s\n\n%s\n\n",date,(*msg).dossier,(*msg).titre,(*msg).corps);

    if (strcmp((*msg).expediteur, (*util).nom) == 0) {
       printf("1. Supprimer\n2. Marquer comme non-lu\n3. Retour\n\n");
    }
    else {
        printf("1. Repondre\n2. Supprimer\n3. Marquer comme non-lu\n4. Deplacer vers\n5. Bloquer cet expediteur\n6. Retour\n\n");
    }

    printf("Veuillez entrer votre choix: ");
    choix = get_entier();

    while (choix < 1 || choix > 3 + (strcmp((*msg).expediteur, (*util).nom) != 0)*3) {
        printf("\nChoix invalide\n");
        printf("Veuillez entrer votre choix: ");
        choix = get_entier();
    }

    if (strcmp((*msg).expediteur, (*util).nom) == 0) {
       switch (choix) {
            case 1: supprimer_message(util, msg);
            break;
            case 2: {
                (*msg).lu = 0;
                maj_fichier(util);
            }
            break;
            default: return 0;
        }
    }
    else {
        switch (choix) {
            case 1: repondre_message(util, msg);
            break;
            case 2: supprimer_message(util, msg);
            break;
            case 3: {
                (*msg).lu = 0;
                maj_fichier(util);
            }
            break;
            case 4: deplacer_message(util, msg);
            break;
            case 5: bloquer_exp(util, (*msg).expediteur);
            break;
            default: return 0;
        }
    }

    return 1;
}
