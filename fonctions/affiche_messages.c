#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "convertir_date.h"
#include "../constantes.h"
#include "../structures/utilisateur.h"
#include "../structures/dossier.h"

void affiche_messages(utilisateur *util, dossier *dos, int page) {
    int i;
    char apercu[90], date[19];

    printf("\nPage %d/%d:\n\n", page, 1 + (*dos).num_messages/(NUM_APERCU + 1));

    for (i = 0; i <= (*dos).num_messages - 1 - (page - 1)*NUM_APERCU; i++) {
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
    // affiche page suivante, page précédente si possible a l'aide de existe_page(page +- 1)
    // affiche aller à la page
    // affiche retour

    // entrer le choix, switch case etc...
}
