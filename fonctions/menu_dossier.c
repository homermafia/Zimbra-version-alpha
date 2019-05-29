#include <stdio.h>
#include <stdlib.h>
#include "get_entier.h"
#include "menu_messagerie.h"
#include "../structures/utilisateur.h"

void menu_dossier(utilisateur util) {
    int i, choix;

    printf("\nDossiers:\n\n");

    //dossiers personnailsés
    for(i=0;i<util.num_dossiers;i++){
        printf("%i. %s\n",i+1,util.dossiers[i].nom);
    }

    //outils dossiers
    if(i<8){
        printf("%d. Creer un dossier\n", i + 1);
    }
    if(i>3){
        printf("%d. Supprimer un dossier\n", i + 2 - i/8);
    }
    printf("%d. Retour\n\n", i + 2 + (i > 3 && i < 8));

    //choix
    printf("Veuillez entrer votre choix: ");
    choix = get_entier();

    while (choix < 1 || choix > i + 2 + (i > 3 && i < 8)) {
        printf("\nChoix invalide\n");
        printf("Veuillez entrer votre choix: ");
        choix = get_entier();
    }

    switch (choix) {
        case 1: /*affiche*/ ;
        break;
        case 2: /*affiche*/;
        break;
        case 3: /*affiche*/;
        break;
        case 4:{ if(util.num_dossiers==3){
                //creation
                }
                else{
                //affiche
                }
        }
        break;
        case 5: { if(util.num_dossiers==3){
            //retour
            }
            else{
                if(util.num_dossiers==4){
                //creation
                }
                else{
                //affiche
                }
            }
        }
        break;
        case 6: { if(util.num_dossiers==4){
            //supprimer
            }
            else{
                if(util.num_dossiers==5){
                //creation
                }
                else{
                //affiche
                }
            }
        }
        break;
        case 7: {if(util.num_dossiers==5){
            //supprimer
            }
            else{
                if(util.num_dossiers==4){
                    menu_messagerie(util);
                }
                else{
                    if(util.num_dossiers==6){
                    //creation
                    }
                    else{
                    //affiche
                    }
                }
            }
        }
        break;
        case 8: { if(util.num_dossiers==6){
            //supprimer
            }
            else{
                if(util.num_dossiers==5){
                    menu_messagerie(util);
                }
                else{
                    if(util.num_dossiers==7){
                    //creation
                    }
                    else{
                    //affiche
                    }
                }
            }
        }
        break;
        case 9: { if(util.num_dossiers==6){
            menu_messagerie(util);
            }
            else{
                //supprimer
            }
        }
        break;
        case 10: menu_messagerie(util);
        break;

    }
}

