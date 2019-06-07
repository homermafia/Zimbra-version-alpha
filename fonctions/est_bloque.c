#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../structures/utilisateur.h"

int est_bloque(utilisateur *destinataire, char expediteur[]) {
    int i = 0;

    while (i < (*destinataire).num_bloques && strcmp(expediteur,(*destinataire).util_bloques[i]) != 0) {
        i++;
    }

    return i != (*destinataire).num_bloques;
}

