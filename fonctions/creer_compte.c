#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nom_valide.h"
#include "existe_nom.h"
#include "../constantes.h"

void creer_compte(void) {
    char nom[21], mdp[21], donnees[250] = "Mot de passe: ", chemin_donnees[55] = BDD_UTILISATEURS;
    int nom_existant;

    printf("\nCreation d'un compte\n\n");

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
        printf("Entrez un mot de passe (>= 8 caractères et <= 20 caracteres): ");
        gets(mdp);
    }

    /* Ajout du nom de l'utilisateur dans la base données */
    FILE *comptes = fopen(BDD_COMPTES, "a");
    fputs(nom, comptes);
    fputs("\n", comptes);
    fclose(comptes);

    /* Ajout des données de l'utilisateur dans la base de données */
    strcat(donnees, mdp);
    strcat(donnees, ",\nDossiers: {\n\tBoite de réception: {\n\t\t\n\t},\n\tMessages envoyés: {\n\t\t\n\t},\n\tMessages supprimés: {\n\t\t\n\t},\n},\nUtilisateurs bloqués: {\n\t\n}");

    strcat(chemin_donnees, nom);
    strcat(chemin_donnees, ".txt");
    FILE *nouvel_util = fopen(chemin_donnees, "w");
    fputs(donnees, nouvel_util);
    fclose(nouvel_util);

    printf("\nBienvenue sur zimbra ! Votre adresse mail est %s", strcat(nom, "@utbm.fr\n\n"));
}
