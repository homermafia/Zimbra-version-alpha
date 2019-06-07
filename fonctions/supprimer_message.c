#include <string.h>
#include "../constantes.h"
#include "../structures/utilisateur.h"
#include "../structures/message.h"
#include "maj_fichier.h"
#include "inserer_message.h"

void supprimer_message(utilisateur *util, message *msg) {
    int v, n = 0, i = 0;

    while (strcmp((*util).dossiers[i].nom, (*msg).dossier) != 0) {
        i = i + 1;
    }

    while ((*util).dossiers[i].messages[n].date != (*msg).date) {
        n = n + 1;
    }

    for (v = n + 1; v < (*util).dossiers[i].num_messages; v = v + 1) {
        (*util).dossiers[i].messages[v - 1] = (*util).dossiers[i].messages[v];
    }

    if (i != 2) { /* Si le message n'était pas dans le dossier "Messages supprimés", alors */
        inserer_message(util, msg, 2);
    }

    (*util).dossiers[i].num_messages = (*util).dossiers[i].num_messages - 1;
    maj_fichier(util);
}
