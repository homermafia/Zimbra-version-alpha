#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../constantes.h"

int corresp_mdp(char mdp[], char nom[]) {
    char vrai_mdp[21], ligne [41], chemin_donnees[55] = BDD_UTILISATEURS;
    int i = 0;

    strcat(chemin_donnees, nom);
    strcat(chemin_donnees, ".txt");
    FILE *f_utilisateur = fopen(chemin_donnees, "r");

    fgets(ligne, 40, f_utilisateur); /* ligne du mot de passe */

    while (ligne[14 + i] != '\n') {
        vrai_mdp[i] = ligne[14 + i];
        i = i + 1;
    }
    vrai_mdp[i - 1] = '\0';

    fclose(f_utilisateur);

    return strcmp(mdp, vrai_mdp) + 1;
}
