#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_entier.h"
#include "maj_fichier.h"
#include "inserer_message.h"
#include "../constantes.h"
#include "../structures/utilisateur.h"
#include "../structures/message.h"

void deplacer_message(utilisateur *util, message *msg) {
    int i, n, v, choix;

    printf("Dossiers\n\n");
    for (i = 0; i < (*util).num_dossiers; i++) {
        printf("%i. %s\n", i + 1, (*util).dossiers[i].nom);
    }
    printf("%d. Retour\n\n", i + 1);

    printf("Entrez le numero du dossier dans lequel vous souhaitez deplacer le message: ");
    choix = get_entier();

    while (choix < 1 || choix > (*util).num_dossiers + 1) {
        printf("Numero invalide\n");
        printf("Entrez le numero du dossier dans lequel vous souhaitez deplacer le message: ");
        choix = get_entier();
    }

    if (choix < i + 1) {
        //déplacement du message
        inserer_message(util, msg, i - 1);

        //effacement du message dans le dossier d'origine
        i = 0;
        n = 0;

        while (strcmp((*util).dossiers[i].nom, (*msg).dossier) != 0) {
            i = i + 1;
        }

        while ((*util).dossiers[i].messages[n].date != (*msg).date) {
            n = n + 1;
        }

        for (v = n + 1; v < (*util).dossiers[i].num_messages; v = v + 1) {
            (*util).dossiers[i].messages[v - 1] = (*util).dossiers[i].messages[v];
        }

        (*util).dossiers[i].num_messages = (*util).dossiers[i].num_messages - 1;
        maj_fichier(util);
    }
}
