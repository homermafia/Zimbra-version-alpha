#include <stdio.h>
#include <stdlib.h>
#include "get_entier.h"
#include "maj_fichier.h"
#include "../structures/utilisateur.h"

void supprimer_dossier(utilisateur *util) {
    int i, choix;

    printf("\n");
    for (i = 3; i < (*util).num_dossiers; i = i + 1) {
        printf("%d. %s\n", i - 2, (*util).dossiers[i].nom);
    }
    printf("%d. Retour\n\n", i - 2);

    printf("Entrez le numero du dossier a supprimer: ");
    choix = get_entier();

    while (choix < 1 || choix > (*util).num_dossiers - 2) {
        printf("Numero invalide\n");
        printf("Entrez le numéro du dossier a supprimer: ");
        choix = get_entier();
    }

    if (choix < (*util).num_dossiers - 2) {
        for (i = choix + 2; i < (*util).num_dossiers - 1; i = i + 1) {
            (*util).dossiers[i] = (*util).dossiers[i + 1];
        }
        (*util).num_dossiers = (*util).num_dossiers - 1;
        maj_fichier(util);
        printf("Dossier supprime.\n");
    }
}
