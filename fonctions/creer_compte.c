#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_chaine.h"
#include "nom_valide.h"
#include "existe_nom.h"
#include "../constantes.h"

void creer_compte(void) {
    char nom[21], mdp[21], donnees[250] = "Mot de passe: ", chemin_donnees[55] = BDD_UTILISATEURS;
    int nom_existant;

    printf("\nCreation d'un compte\n\n");

    do {
        printf("Entrez un nom d'utilisateur (<= 20 caracteres et lettres uniquement): ");
        while (get_chaine(nom, 21) != 1 || nom_valide(nom) != 0) {
            printf("Nom invalide\n");
            printf("Entrez un nom d'utilisateur (<= 20 caracteres et lettres uniquement): ");
        }

        nom_existant = existe_nom(nom);
        if (nom_existant == 1) {
            printf("Ce nom est deja pris ! Veuillez en proposer un autre\n");
        }
    }
    while (nom_existant == 1);

    printf("Entrez un mot de passe (>= 8 caracteres et <= 20 caracteres): ");
    while (get_chaine(mdp, 21) != 1 || strlen(mdp) < 8) {
        printf("Mot de passe invalide\n");
        printf("Entrez un mot de passe (>= 8 caracteres et <= 20 caracteres): ");
    }

    /* Ajout du nom de l'utilisateur dans la base donn�es */
    FILE *comptes = fopen(BDD_COMPTES, "a");
    fputs(nom, comptes);
    fputs("\n", comptes);
    fclose(comptes);

    /* Ajout des donn�es de l'utilisateur dans la base de donn�es */
    strcat(donnees, mdp);
    strcat(donnees, ",\nDossiers: {\n\tBoite de r�ception: {\n\t\t\n\t},\n\tMessages envoy�s: {\n\t\t\n\t},\n\tMessages supprim�s: {\n\t\t\n\t},\n},\nUtilisateurs bloqu�s: {\n\t\n}");

    strcat(chemin_donnees, nom);
    strcat(chemin_donnees, ".txt");
    FILE *nouvel_util = fopen(chemin_donnees, "w");
    fputs(donnees, nouvel_util);
    fclose(nouvel_util);

    printf("\nBienvenue sur zimbra ! Votre adresse mail est %s", strcat(nom, "@utbm.fr\n\n"));
}
