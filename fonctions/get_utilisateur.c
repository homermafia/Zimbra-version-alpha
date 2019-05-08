#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../structures/utilisateur.h"
#include "../structures/dossier.h"
#include "../structures/message.h"
#include "../constantes.h"

void get_valeur(char ligne[], char valeur[]) {
    int i, debut = 0;

    while (ligne[debut] != ':') {
        debut = debut + 1;
    }

    for (i = debut + 2; i <= strlen(ligne) - 3; i = i + 1) {
        valeur[i - debut - 2] = ligne[i];
    }
    valeur[strlen(valeur)] = '\0';
}

utilisateur get_utilisateur(char nom[]) {
    utilisateur util;
    char ligne[515], chemin_donnees[55] = BDD_UTILISATEURS; /* variables pour le fichier */
    char nom_dossier[21]; /* variables pour les dossiers */
    char autre_util[21], date_c[11], titre[31], corps[501], lu_c[2]; /* variables pour les messages */
    char util_bloque[21]; /* variable pour les utilisateurs bloqués */
    int i, num_dossier = 0, num_message = 0, num_bloque = 0;

    strcat(chemin_donnees, nom);
    strcat(chemin_donnees, ".txt");
    FILE *f_utilisateur = fopen(chemin_donnees, "r");

    fgets(ligne, 40, f_utilisateur); /* ligne du mot de passe */
    fgets(ligne, 15, f_utilisateur); /* ligne de dossier */

    /* Obention des dossiers */
    do {
        fgets(ligne, 25, f_utilisateur);
        if (ligne[0] == '\t' && ligne[1] != '\t' && ligne[1] != '}') { /* on est sur une ligne contenant un dossier */
            num_dossier = num_dossier + 1;
            num_message = 0;

            /* Obtention du nom du dossier */
            i = 1;
            while (ligne[i] != ':') {
                nom_dossier[i - 1] = ligne[i];
                i = i + 1;
            }
            nom_dossier[i - 1] = '\0';

            /* Création de la structure dossier */
            dossier dos;
            strcpy(dos.nom, nom_dossier);

            /* Obtention des messages */
            do {
                fgets(ligne, 9, f_utilisateur);
                if (ligne[1] == '\t' && ligne[2] != '\n' && ligne[2] != '}') { /* on est sur une ligne contenant un message */
                    num_message = num_message + 1;

                    fgets(ligne, 40, f_utilisateur); /* ligne expéditeur ou destinataire */
                    get_valeur(ligne, autre_util);

                    fgets(ligne, 25, f_utilisateur); /* ligne date */
                    get_valeur(ligne, date_c);

                    fgets(ligne, 45, f_utilisateur); /* ligne titre */
                    get_valeur(ligne, titre);

                    fgets(ligne, 515, f_utilisateur); /* ligne corps */
                    get_valeur(ligne, corps);

                    fgets(ligne, 15, f_utilisateur); /* ligne lu */
                    get_valeur(ligne, lu_c);

                    /* Création de la structure message */
                    message msg;

                    if (strcmp(nom_dossier, "Messages envoyés") == 0) {
                        strcpy(msg.destinataire, autre_util);
                    }
                    else {
                        strcpy(msg.expediteur, autre_util);
                    }
                    strcpy(msg.titre, titre);
                    strcpy(msg.corps, corps);
                    strcpy(msg.dossier, nom_dossier);
                    msg.date = atoi(date_c);
                    msg.lu = atoi(lu_c);

                    dos.messages[num_message - 1] = msg;
                }
            }
            while (ligne[1] == '\t');

            dos.num_messages = num_message;
            util.dossiers[num_dossier - 1] = dos;
        }
    }
    while (ligne[0] == '\t');

    util.num_dossiers = num_dossier;

    fgets(ligne, 25, f_utilisateur); /* ligne d'utilisateur bloqués */

    /* Obention des utilisateurs bloqués */
    do {
        fgets(ligne, 25, f_utilisateur);
        if (ligne[0] == '\t' && ligne[1] != '\n') { /* on est sur une ligne contenant un utilisateur */
            num_bloque = num_bloque + 1;

            /* Obtention du nom de l'utilisateur bloqué */
            for (i = 1; i <= strlen(ligne) - 3; i = i + 1) {
                util_bloque[i - 1] = ligne[i];
            }
            util_bloque[i - 1] = '\0';

            strcpy(util.util_bloques[num_bloque - 1], util_bloque);
        }
    }
    while (ligne[0] == '\t');

    util.num_bloques = num_bloque;

    fclose(f_utilisateur);

    return util;
}
