#include <stdio.h>
#include <stdlib.h>
#include "get_chaine.h"
#include "existe_nom.h"
#include "get_utilisateur.h"
#include "corresp_mdp.h"
#include "../structures/utilisateur.h"

utilisateur connexion(void) {
    char nom[21], mdp[21];

    printf("\nConnexion a un compte\n\n");

    printf("Nom d'utilisateur: ");
    while (get_chaine(nom, 21) != 1 || existe_nom(nom) != 1) {
        printf("Ce nom n'existe pas\n");
        printf("Nom d'utilisateur: ");
    }

    printf("Mot de passe: ");
    while (get_chaine(mdp, 21) != 1 || corresp_mdp(mdp, nom) != 1) {
        printf("Mot de passe incorrect\n");
        printf("Mot de passe: ");
    }

    printf("\nBienvenue dans votre espace zimbra !\n");

    return get_utilisateur(nom);
}
