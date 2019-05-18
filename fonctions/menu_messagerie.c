#include <stdio.h>
#include <stdlib.h>
#include "../structures/utilisateur.h"

void menu_messagerie(utilisateur n)
{   int i=2,choix;
    //dossiers obligatoires
    printf("1. Boite de reception\n2. Messages envoyes\n3. Messages effaces\n");

    //dossiers personnailsés
    for(i=0;n.dossiers[i].nom!='\0';i++){
        printf("%i.%s\n",i+4,n.dossiers[i].nom);
    }
    i++;

    //outils dossiers
    if(i<4){
            printf("%i.Creer un dossier\n",i+4);
    }
    if(i>0){
            printf("%i.Supprimer un dossier\n",i+5);
            i++;
    }
    printf("%i.Retour",i+5);

    //choix
    printf("Veuillez entrer votre choix: ");
    scanf("%d", &choix);

    while (choix < 1 || choix > 3) {
        printf("\nChoix invalide\n");
        printf("Veuillez entrer votre choix: ");
        scanf("%d", &choix);
    }
    switch (choix) {
        case 1: ;
        break;
        case 2: ;
        break;
        case 3: ;
        break;

        case i+5: ;
        break;

    }
}
