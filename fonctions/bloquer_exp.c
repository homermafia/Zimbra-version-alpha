#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "est_bloque.h"
#include "maj_fichier.h"
#include "../constantes.h"
#include "../structures/utilisateur.h"

void bloquer_exp(utilisateur *util, char expediteur[]) {
    if (est_bloque(util, expediteur) == 0 && (*util).num_bloques < MAX_BLOQUES) {
        strcpy((*util).util_bloques[(*util).num_bloques], expediteur);
        (*util).num_bloques++;
        maj_fichier(util);
        printf("\n%s est maintenant bloque(e)\n", expediteur);
    }
    else {
        printf("\nExpediteur deja bloque ou nombre maximun d'utilisateur depasse\n");
    }
}
