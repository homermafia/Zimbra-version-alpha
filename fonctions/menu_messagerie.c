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

    //outils dossiers
    if(i<3){
            printf("8.Creer un dossier\n");
    }
    if(i>0){
            printf("9.Supprimer un dossier\n");
    }
    printf("10.Retour");

    //choix
    printf("Veuillez entrer votre choix: ");
    scanf("%d", &choix);

    while (choix < 1 || choix > 10) {
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
        case 4: ;
        break;
        case 5: ;
        break;
        case 6: ;
        break;
        case 7: ;
        break;
        case 8: ;
        break;
        case 9: ;
        break;
        case 10: ;
        break;

    }
}
