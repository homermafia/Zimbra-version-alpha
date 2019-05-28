#include <stdio.h>
#include <stdlib.h>
#include "menu_messagerie.h"
#include "../structures/utilisateur.h"

void menu_dossier(utilisateur util) {

    int i, choix, c = 0;
    //dossiers personnailsés
    for(i=0;i<util.num_dossiers;i++){
        printf("%i. %s\n",i+1,util.dossiers[i].nom);
    }

    //outils dossiers
    if(i<8){
            printf("%d. Creer un dossier\n", i + 1);
    }
    if(i>3){
            printf("%d. Supprimer un dossier\n", i + 2);
    }
    printf("%d. Retour\n\n", i + 3);

    //choix
    printf("Veuillez entrer votre choix: ");
    scanf("%d", &choix);

    while (choix < 1 || choix > 3+util.num_dossiers) {
        printf("\nChoix invalide\n");
        printf("Veuillez entrer votre choix: ");
        scanf("%d", &choix);
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
                c++;
                }
                else{
                //affiche
                }
        }
        break;
        case 5: { if(c==1){
            //retour
            c++;
            }
            else{
                if(util.num_dossiers==4){
                //creation
                c++;
                }
                else{
                //affiche
                }
            }
        }
        break;
        case 6: { if(c==1){
            //supprimer
            c++;
            }
            else{
                if(util.num_dossiers==5){
                //creation
                c++;
                }
                else{
                //affiche
                }
            }
        }
        break;
        case 7: {if(c==1){
            //supprimer
            c++;
            }
            else{
                if(c==2){
                    menu_messagerie(util);
                }
                else{
                    if(util.num_dossiers==6){
                    //creation
                    c++;
                    }
                    else{
                    //affiche
                    }
                }
            }
        }
        break;
        case 8: { if(c==1){
            //supprimer
            c++;
            }
            else{
                if(c==2){
                    menu_messagerie(util);
                }
                else{
                    if(util.num_dossiers==7){
                    //creation
                    c++;
                    }
                    else{
                    //affiche
                    }
                }
            }
        }
        break;
        case 9: { if(c==2){
            menu_messagerie(util);
            }
            else{
                //supprimer
                c++;
            }
        }
        break;
        case 10: menu_messagerie(util);
        break;

    }
}

