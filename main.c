#include <stdio.h>
#include <stdlib.h>
#include "fonctions/menu_demarrer.h"
#include "constantes.h"

int main()
{
    /* cr�ation du fichier base de donn�es s'il n'existe pas */
    FILE *bdd = fopen(NOM_BDD, "r");
    if (bdd == NULL) {
        bdd = fopen(NOM_BDD, "w");
    }
    fclose(bdd);

    /* lancement du programme */
    menu_demarrer();

    return 0;
}
