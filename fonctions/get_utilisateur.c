#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../structures/utilisateur.h"

utilisateur get_utilisateur(char nom[]) {
    FILE *bdd = fopen("base_de_donnees.txt", "r+");

    if (bdd == NULL) {
        bdd = fopen("base_de_donnees.txt", "w+");
    }

    fclose(bdd);

}
