#include <stdio.h>
#include <stdlib.h>
#include "get_entier.h"
#include "menu_dossier.h"
#include "../structures/utilisateur.h"

int menu_messagerie(utilisateur util) {
    int choix;
    printf("\n1. Consulter vos messages\n2. Envoyer un message\n3. Se deconnecter\n\n");

    //choix
    printf("Veuillez entrer votre choix: ");
    choix = get_entier();

    while (choix < 1 || choix > 3) {
        printf("\nChoix invalide\n");
        printf("Veuillez entrer votre choix: ");
        choix = get_entier();
    }

    switch (choix) {
        case 1: {
            choix = menu_dossier(util);
            if (choix <= util.num_dossiers) {
                //affiche le dossier util.dossiers[choix]
            }
            else {
                if (util.num_dossiers < MAX_DOSSIERS && util.num_dossiers > 3) { /* Cr�er et supprimer sont affich�s */
                    switch (choix) {
                        case 1: /*cr�er dossier*/;
                        break;
                        case 2: /*supprimer dossier*/;
                        break;
                        default: return 1;
                    }
                }
                else {
                    if (util.num_dossiers > 3) { /* Supprimer est affich� */
                        if (choix == util.num_dossiers + 1) {
                            //supprimer dossier
                        }
                        else {
                            return 1;
                        }
                    }
                    else { /* Cr�er est affich� */
                        if (choix == util.num_dossiers + 1) {
                            //creer dossier
                        }
                        else {
                            return 1;
                        }
                    }
                }
            }
        }
        break;
        case 2: /*evoyer*/;
        break;
        case 3: return 0;
        break;
    }

    return choix;
}
