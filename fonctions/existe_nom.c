#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../constantes.h"

int existe_nom(char nom[]) {
    FILE *bdd = fopen(NOM_BDD, "r");
    char c, nom_bis[21];
    int i, fin_utilisateur = 0, existe;

    if (fgetc(bdd) == EOF) {
        existe = 0; /* fichier vide */
    }
    else {
        do {
            i = 0;
            fin_utilisateur = 0;
            fseek(bdd, -1, SEEK_CUR);
            strcpy(nom_bis, "");

            /* obtention du nom d'uilisateur du sur la ligne en cours */
            do {
                c = fgetc(bdd);
                if (c == ':') {
                    nom_bis[i] = '\0';
                }
                else {
                    nom_bis[i] = c;
                    i = i + 1;
                }
            }
            while (c != ':');

            /* positionnement du curseur à la fin des informatons sur cet utilisateur */
            do {
                c = fgetc(bdd);
                if (c == '\n' && fgetc(bdd) == '}' && fgetc(bdd) == ',' && fgetc(bdd) == '\n' && fgetc(bdd) == '\n') {
                    fin_utilisateur = 1;
                }
            }
            while (fin_utilisateur == 0);
        }
        while (strcmp(nom_bis, nom) != 0 && fgetc(bdd) != EOF);

        existe = strcmp(nom_bis, nom) + 1;
    }

    fclose(bdd);

    return existe;
}
