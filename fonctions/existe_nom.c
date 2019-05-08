#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../constantes.h"

int existe_nom(char nom[]) {
    FILE *comptes = fopen(BDD_COMPTES, "r");
    char nom_bis[22];
    int existe;

    if (fgetc(comptes) == EOF) {
        existe = 0; /* fichier vide */
    }
    else {
        do {
            fseek(comptes, -1, SEEK_CUR);
            fgets(nom_bis, 22, comptes);
            nom_bis[strlen(nom_bis) - 1] = '\0';
        }
        while (getc(comptes) != EOF && strcmp(nom, nom_bis) != 0);

        existe = strcmp(nom, nom_bis) + 1;
    }

    fclose(comptes);

    return existe;
}
