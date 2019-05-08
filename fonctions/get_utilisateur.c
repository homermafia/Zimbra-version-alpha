#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../structures/utilisateur.h"
#include "../constantes.h"

utilisateur get_utilisateur(char nom[]) {
    FILE *comptes = fopen(BDD_COMPTES, "r+");
    utilisateur util;



    fclose(comptes);

    return util;
}
