#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "get_utilisateur.h"
#include "maj_fichier.h"
#include "inserer_message.h"
#include "../structures/utilisateur.h"
#include "../structures/message.h"

void envoyer_message(utilisateur *util, message *msg) {
    utilisateur destinataire = get_utilisateur((*msg).destinataire);

    (*msg).date = time(0);

    if (strcmp((*util).nom, destinataire.nom) == 0) { /* Si l'utilisateur s'envoie un message � soi-m�me */
        strcpy((*msg).dossier, "Boite de r�ception");
        (*msg).lu = 0;
        inserer_message(util, msg, 0);
    }
    else {
        /* Placement du dossier dans le dossier messages envoy�s de l'exp�diteur*/
        strcpy((*msg).dossier, "Messages envoy�s");
        (*msg).lu = 1;
        inserer_message(util, msg, 1);

        /* Placement du dossier dans le dossier boite de reception du destinataire*/
        strcpy((*msg).dossier, "Boite de r�ception");
        (*msg).lu = 0;
        inserer_message(&destinataire, msg, 0);

        maj_fichier(&destinataire);
    }
    maj_fichier(util);

    printf("\nMessage envoye avec succes !\n");
}
