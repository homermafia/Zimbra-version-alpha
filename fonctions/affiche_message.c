#include <stdio.h>
#include <stdlib.h>
#include "get_entier.h"
#include "convertir_date.h"
#include "supprimer_message.h"
#include "deplacer_message.h"
#include "maj_fichier.h"
#include "../structures/utilisateur.h"
#include "../structures/dossier.h"
#include "../structures/message.h"
int affiche_message(utilisateur *util, message *mes) {
    int choix;
    char date[19];
    (*mes).lu=1;
    convertir_date((*mes).date,date);
    printf("De %s\nEnvoye le %s\nDossier : %s\nSujet: %s\n\n%s\n\n",(*mes).expediteur,date,(*mes).dossier,(*mes).titre,(*mes).corps);
    printf("1. Repondre\n2. Supprimer\n3. Marquer comme non-lu\n4. Déplacer vers\n5. Bloquer cet expediteur\n6. Retour\n\n");
    printf("Veuillez entrer votre choix: ");
    choix = get_entier();

    while (choix < 1 || choix > 6) {
        printf("\nChoix invalide\n");
        printf("Veuillez entrer votre choix: ");
        choix = get_entier();
    }
    switch(choix){
            case 1:/*repondre*/;
            break;
            case 2: supprimer_message(util, *mes);
            break;
            case 3: (*mes).lu=0;
            break;
            case 4: deplacer_message(util, *mes);
            break;
            case 5:/*bloquer cet expéditeur*/;
            break;
    }
    maj_fichier(util);
    return 0;
}
