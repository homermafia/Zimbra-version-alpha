#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_corps.h"
#include "../structures/utilisateur.h"
#include "../structures/message.h"
int repondre_message(utilisateur *util, message *mes1, message *mes2) {
    printf("\nRepondre a un message\n\n");
    strcpy((*mes2).expediteur, (*util).nom);
    strcpy((*mes2).titre,"Re: ");
    strcat((*mes2).titre, (*mes1).titre);
    strcpy((*mes2).destinataire, (*mes1).expediteur);
    get_corps((*mes2).corps);
    return 0;
}
