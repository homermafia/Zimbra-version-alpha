#include <stdio.h>
#include <stdlib.h>
#include "fonctions/menu.h"

int main()
{
    switch (menu()) {
        case 1: printf("Se connecter a ete choisi\n");
        break;
        case 2: printf("Creer un compte a ete choisi\n");
        break;
        default: printf("A bientot !\n");
    }
    return 0;
}
