#include <stdio.h>
#include <stdlib.h>
#include "fonctions/menu_demarrer.h"
#include "constantes.h"
#include "fonctions/get_entier.h"

int main()
{
    //int a, *pa = &a;//
    //printf("%d\n%d\n", get_entier(pa), *pa);//
    /* cr�ation du fichier base de donn�es des comptes s'il n'existe pas */
    FILE *comptes = fopen(BDD_COMPTES, "r");
    if (comptes == NULL) {
        comptes = fopen(BDD_COMPTES, "w");
    }
    fclose(comptes);

    /* lancement du programme */
    menu_demarrer();

    return 0;
}
