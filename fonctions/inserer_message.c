#include "../constantes.h"
#include "../structures/utilisateur.h"
#include "../structures/message.h"

void inserer_message(utilisateur *util, message *msg, int i) {
    int n;

    for (n = (*util).dossiers[i].num_messages - 1 - (*util).dossiers[i].num_messages/MAX_MESSAGES; n >= 0; n = n - 1) {
        (*util).dossiers[i].messages[n + 1] = (*util).dossiers[i].messages[n];
    }
    (*util).dossiers[i].messages[0] = *msg;
    (*util).dossiers[i].num_messages = (*util).dossiers[i].num_messages + ((*util).dossiers[i].num_messages < MAX_MESSAGES);
}
