#include <stdio.h>
#include <stdlib.h>
#include "fonctions/menu_demarrer.h"
#include "constantes.h"

int main()
{
    /* création du fichier base de données des comptes s'il n'existe pas */
    FILE *comptes = fopen(BDD_COMPTES, "r");
    if (comptes == NULL) {
        comptes = fopen(BDD_COMPTES, "w");
    }
    fclose(comptes);

    /* lancement du programme */
    printf("Zimbra version alpha\n");
    while (menu_demarrer() == 1);
    printf("A bientot !\n");

    return 0;
}
