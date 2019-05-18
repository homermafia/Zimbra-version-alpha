#include <stdio.h>
#include <stdlib.h>
#include "fonctions/menu_demarrer.h"
#include "constantes.h"1

int main()
{
    /* création du fichier base de données des comptes s'il n'existe pas */
    FILE *comptes = fopen(BDD_COMPTES, "r");
    if (comptes == NULL) {
        comptes = fopen(BDD_COMPTES, "w");
    }
    fclose(comptes);

    /* lancement du programme */
    menu_demarrer();

    return 0;
}
