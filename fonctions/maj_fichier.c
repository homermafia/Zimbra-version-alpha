#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../structures/utilisateur.h"
#include "../constantes.h"

void maj_fichier(utilisateur *util) {
    char ligne_mdp[40], char_num[15], chemin_donnees[55] = BDD_UTILISATEURS;
    int i, n;

    strcat(chemin_donnees, (*util).nom);
    strcat(chemin_donnees, ".txt");
    FILE *f_utilisateur = fopen(chemin_donnees, "r+");
    fgets(ligne_mdp, 40, f_utilisateur); /* ligne du mot de passe */
    fclose(f_utilisateur);

    FILE *f_util = fopen(chemin_donnees, "w+");
    fputs(ligne_mdp, f_util);
    fputs("Dossiers: {\n", f_util);

    for (i = 0; i <= (*util).num_dossiers - 1; i = i + 1) {
        fputs("\t", f_util);
        fputs((*util).dossiers[i].nom, f_util);
        fputs(": {\n\t", f_util);
        if ((*util).dossiers[i].num_messages == 0) {
            fputs("\t\n\t", f_util);
        }
        else {
            for (n = 0; n <= (*util).dossiers[i].num_messages - 1; n = n + 1) {
                if (strcmp((*util).dossiers[i].nom, "Messages envoyés") == 0) {
                    fputs("\t{\n\t\t\tDestinataire: ", f_util);
                    fputs((*util).dossiers[i].messages[n].destinataire, f_util);
                }
                else {
                    fputs("\t{\n\t\t\tExpéditeur: ", f_util);
                    fputs((*util).dossiers[i].messages[n].expediteur, f_util);
                }

                fputs(",\n\t\t\tDate: ", f_util);
                itoa((*util).dossiers[i].messages[n].date, char_num, 10);
                fputs(char_num, f_util);

                fputs(",\n\t\t\tTitre: ", f_util);
                fputs((*util).dossiers[i].messages[n].titre, f_util);

                fputs(",\n\t\t\tCorps: ", f_util);
                fputs((*util).dossiers[i].messages[n].corps, f_util);

                fputs(",\n\t\t\tLu: ", f_util);
                itoa((*util).dossiers[i].messages[n].lu, char_num, 10);
                fputs(char_num, f_util);

                fputs(",\n\t\t},\n\t", f_util);
            }
        }
        fputs("},\n", f_util);
    }

    fputs("},\nUtilisateurs bloqués: {\n", f_util);
    if ((*util).num_bloques == 0) {
        fputs("\t\n", f_util);
    }
    else {
        for (i = 0; i <= (*util).num_bloques - 1; i = i + 1) {
            fputs("\t", f_util);
            fputs((*util).util_bloques[i], f_util);
            fputs(",\n", f_util);
        }
    }
    fputs("}", f_util);

    fclose(f_util);
}
