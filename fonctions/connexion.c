#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "existe_nom.h"
#include "get_utilisateur.h"
#include "corresp_mdp.h"
#include "../structures/utilisateur.h"

utilisateur connexion(void) {
    char nom[21], mdp[21];

    printf("\nConnexion a un compte\n\n");

    printf("Nom d'utilisateur: ");
    gets(nom);

    while (existe_nom(nom) != 1) {
        printf("Ce nom n'existe pas\n");
        printf("Nom d'utilisateur: ");
        gets(nom);
    }

    printf("Mot de passe: ");
    gets(mdp);

    while (corresp_mdp(mdp, nom) != 1) {
        printf("Mot de passe incorrect\n");
        printf("Mot de passe: ");
        gets(mdp);
    }

    printf("\nBienvenue dans votre espace zimbra !\n\n");

    return get_utilisateur(nom);
}
