#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_entier.h"
#include "convertir_date.h"
#include "existe_page.h"
#include "../constantes.h"
#include "../structures/utilisateur.h"
#include "../structures/dossier.h"
#include "affiche_message.h"

int affiche_messages(utilisateur *util, dossier *dos, int page) {
    int i, num_affiche, num_choix, choix;
    char apercu[90], date[19];
    printf("\nPage %d/%d:\n\n", page, 1 + ((*dos).num_messages - 1)/NUM_APERCU);

    for (i = (page - 1)*NUM_APERCU; i < page*NUM_APERCU && i < (*dos).num_messages; i++) {
        itoa(i + 1, apercu, 10);
        strcat(apercu, ". ");
        if ((*dos).messages[i].lu == 0) {
            strcat(apercu,"*** ");
        }
        strcat(apercu, (*dos).messages[i].expediteur);
        strcat(apercu, " : ");
        strcat(apercu, (*dos).messages[i].titre);
        strcat(apercu, " - ");
        convertir_date((*dos).messages[i].date, date);
        strcat(apercu, date);
        printf("%s\n", apercu);
    }

    num_affiche = i - (page - 1)*NUM_APERCU;

    if (existe_page(dos, page + 1) && existe_page(dos, page - 1)) {
        printf("%d. Page suivante\n", num_affiche + 1);
        printf("%d. Page precedente\n", num_affiche + 2);
        printf("%d. Aller a la page\n", num_affiche + 3);
        printf("%d. Retour\n", num_affiche + 4);
        num_choix = num_affiche + 4;
    }
    else {
        if (existe_page(dos, page + 1)) {
            printf("%d. Page suivante\n", num_affiche + 1);
            printf("%d. Aller a la page\n", num_affiche + 2);
            printf("%d. Retour\n", num_affiche + 3);
            num_choix = num_affiche + 3;
        }
        else {
            if (existe_page(dos, page - 1)) {
                printf("%d. Page precedente\n", num_affiche + 1);
                printf("%d. Aller a la page\n", num_affiche + 2);
                printf("%d. Retour\n", num_affiche + 3);
                num_choix = num_affiche + 3;
            }
            else {
                printf("%d. Retour\n", num_affiche + 1);
                num_choix = num_affiche + 1;
            }
        }
    }

    printf("\nVeuillez entrer votre choix: ");
    choix = get_entier();

    while (choix < 1 || choix > num_choix) {
        printf("\nChoix invalide\n");
        printf("Veuillez entrer votre choix: ");
        choix = get_entier();
    }

    if (choix <= num_affiche) {
        affiche_message(util, &(*dos).messages[choix - 1]);
    }
    else {
        printf("num = %d\n", num_choix - num_affiche);
        switch (num_choix - num_affiche) {
            case 1: return 0; /* retour affiché */
            break;
            case 3: { /* (page suivante OU page precedente) ET aller a la page ET retour affichés */
                switch (choix - num_affiche) {
                    case 1: { /* page suivante OU page precedente sélectionnée */
                        if (existe_page(dos, page + 1)) {
                            return page + 1;
                        }
                        else {
                            return page - 1;
                        }
                    }
                    break;
                    case 2: {
                        printf("Entrez le numéro de la page auquelle vous souhaitez aller: ");
                        choix = get_entier();

                        while (choix < 1 || choix > 1 + ((*dos).num_messages - 1)/NUM_APERCU) {
                            printf("\nPage invalide\n");
                            printf("Entrez le numéro de la page auquelle vous souhaitez aller: ");
                            choix = get_entier();
                        }

                        return choix;
                    }
                    break;
                    default: return 0;
                }
            }
            break;
            default: { /* page suivante ET page precedente ET aller a la page ET retour affichés */
                switch (choix - num_affiche) {
                    case 1: return page + 1;
                    break;
                    case 2: return page - 1;
                    break;
                    case 3: {
                        printf("Entrez le numéro de la page auquelle vous souhaitez aller: ");
                        choix = get_entier();

                        while (choix < 1 || choix > 1 + ((*dos).num_messages - 1)/NUM_APERCU) {
                            printf("\nPage invalide\n");
                            printf("Entrez le numéro de la page auquelle vous souhaitez aller: ");
                            choix = get_entier();
                        }

                        return choix;
                    }
                    break;
                    default: return 0;
                }
            }
        }
    }

    return 0;
}
