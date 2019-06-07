#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_chaine.h"
#include "maj_fichier.h"
#include "../structures/utilisateur.h"
#include "../structures/dossier.h"

int existe_dossier(utilisateur *util, char nom[]) {
    int i = 0;
    while(i < (*util).num_dossiers && strcmp(nom,(*util).dossiers[i].nom) != 0){
        i++;
    }
    return i != (*util).num_dossiers;
}

void creer_dossier(utilisateur *util) {
    dossier dos;
    dos.num_messages = 0;

    printf("\nVeuillez saisir un nom de dossier de 20 caracteres maximum\n");

    while (get_chaine(dos.nom, 21) != 1 || existe_dossier(util,dos.nom) == 1) {
        printf("\nNom incorrect ou dossier deja existant\n");
        printf("\nVeuillez saisir un nom de dossier de 20 caracteres maximum\n");
    }

    (*util).dossiers[(*util).num_dossiers] = dos;
    (*util).num_dossiers++;
    maj_fichier(util);
}
