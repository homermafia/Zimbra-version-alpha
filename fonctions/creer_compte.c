#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nom_valide.h"
#include "existe_nom.h"
#include "../constantes.h"

void creer_compte(void) {
    FILE *bdd = fopen(NOM_BDD, "a");
    char nom[21], mdp[21], donnees[250];
    int nom_existant;

    printf("\nCreation d'un compte\n\n");
    gets(nom); /* enelever ceci lorsque la fonction pour vider le buffer sera impl�ment�e */

    do {
        printf("Entrez un nom d'utilisateur (<= 20 caracteres et lettres uniquement): ");
        gets(nom);

        while (nom_valide(nom) != 0) {
            printf("Ce nom ne comporte des caracteres autre que des lettres\n");
            printf("Entrez un nom d'utilisateur (<= 20 caracteres et lettres uniquement): ");
            gets(nom);
        }

        nom_existant = existe_nom(nom);
        if (nom_existant == 1) {
            printf("Ce nom est deja pris ! Veuillez en proposer un autre\n");
        }
    }
    while (nom_existant == 1);

    printf("Entrez un mot de passe (>= 8 caracteres et <= 20 caracteres): ");
    gets(mdp);

    while (strlen(mdp) < 8) {
        printf("Le mot de passe doit contenir au moins 8 caracteres\n");
        printf("Entrez un mot de passe (>= 8 caract�res et <= 20 caracteres): ");
        gets(mdp);
    }

    strcpy(donnees, nom);
    strcat(donnees, ": {\n\tMot de passe: ");
    strcat(donnees, mdp);
    strcat(donnees, ",\n\tDossiers: {\n\t\tBoite de r�ception: {\n\t\t\t\n\t\t},\n\t\tMessages envoy�s: {\n\t\t\t\n\t\t},\n\t\tMessages supprim�s: {\n\t\t\t\n\t\t},\n\t},\n\tUtilisateurs bloqu�s: {\n\t\t\n\t},\n},\n\n");
    fputs(donnees, bdd);
    fclose(bdd);

    printf("\nBienvenue sur zimbra ! Votre adresse mail est %s", strcat(nom, "@utbm.fr\n\n"));
}
