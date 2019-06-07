#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "est_bloque.h"
#include "get_titre.h"
#include "get_adresse.h"
#include "get_corps.h"
#include "get_utilisateur.h"
#include "envoyer_message.h"
#include "../structures/utilisateur.h"
#include "../structures/message.h"

void composer_message(utilisateur *util) {
    char adresse[29];
    utilisateur destinataire;
    message msg;

    printf("\nEnvoyer un message\n\n");

    get_adresse(adresse);
    strncpy(msg.destinataire, adresse, strlen(adresse) - 8);
    msg.destinataire[strlen(adresse) - 8] = '\0';
    destinataire = get_utilisateur(msg.destinataire);

    if (est_bloque(&destinataire, (*util).nom)) {
        printf("Vous ne pouvez pas envoyer de message a ce destinataire car il vous a bloque");
    }
    else {
        strcpy(msg.expediteur, (*util).nom);
        get_titre(msg.titre);
        get_corps(msg.corps);
        envoyer_message(util, &msg);
    }
}
