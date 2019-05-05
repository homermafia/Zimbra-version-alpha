#include <stdio.h>
#include <stdlib.h>
#include "../structures/utilisateur.h"

int menu_messagerie(void)
{   int i=2;
    //dossiers obligatoires
    printf("1. Boite de reception\n2. Messages envoyes\n3. Messages effaces\n");

    //dossiers personnailsés
    /*for(i=0;utilisateur.dossier[i]!='\0';i++){
        printf("%i.%s\n",i+4,utilisateur.dossier[i].nom);
    }
    i++;*/

    //outils dossiers
    if(i<4){
            printf("%i.Creer un dossier\n",i+4);
    }
    if(i>0){
            printf("%i.Supprimer un dossier\n",i+5);
            i++;
    }
    printf("%i.Retour",i+5);

    return 0;
}
