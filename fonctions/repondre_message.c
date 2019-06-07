#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_corps.h"
#include "est_bloque.h"
#include "get_utilisateur.h"
#include "envoyer_message.h"
#include "../structures/utilisateur.h"
#include "../structures/message.h"

void repondre_message(utilisateur *util, message *msg) {
    message msg_r;
    utilisateur expediteur = get_utilisateur((*msg).expediteur);

    if (est_bloque(&expediteur, (*util).nom)) {
        printf("\nVous ne pouvez pas repondre a ce message car l'expediteur vous a bloque.\n\n");
    }
    else {
        printf("\nRepondre a ce message\n\n");
        strcpy(msg_r.expediteur, (*util).nom);
        strcpy(msg_r.titre,"Re: ");
        strcat(msg_r.titre, (*msg).titre);
        strcpy(msg_r.destinataire, (*msg).expediteur);
        get_corps(msg_r.corps);
        envoyer_message(util, &msg_r);
    }
}
