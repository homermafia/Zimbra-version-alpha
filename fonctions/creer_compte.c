#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nom_valide.h"
#include "menu_demarrer.h"

void creer_compte(void) {
    char nom[21], mdp[21];

    printf("\nCreation d'un compte\n\n");
    gets(nom); /* enelever ceci lorsque la fonction pour vider le buffer sera implémentée */

    printf("Entrez un nom d'utilisateur (<= 20 caracteres et lettres uniquement): ");
    gets(nom);

    while (nom_valide(nom) != 0) {
        printf("Ce nom ne comporte des caracteres autre que des lettres\n");
        printf("Entrez un nom d'utilisateur (<= 20 caracteres et lettres uniquement): ");
        gets(nom);
    }
    /* vérifier que le nom est unique*/

    printf("Entrez un mot de passe (>= 8 caracteres et <= 20 caracteres): ");
    gets(mdp);

    while (strlen(mdp) < 8) {
        printf("Le mot de passe doit contenir au moins 8 caracteres\n");
        printf("Entrez un mot de passe (>= 8 caractères et <= 20 caracteres): ");
        gets(mdp);
    }

    /* stocker dans le fichier les données de l'utilisateur*/

    printf("\nBienvenue sur zimbra ! Votre adresse mail est %s", strcat(nom, "@utbm.fr\n\n"));
    menu_demarrer();
}
