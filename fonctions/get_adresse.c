#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_chaine.h"
#include "existe_nom.h"

void get_adresse(char adresse[]) {
    char nom[21];

    do {
        printf("Entrez l'adresse mail du destinataire: ");

        while (get_chaine(adresse, 29) != 1 || strstr(adresse, "@utbm.fr") == NULL) {
            printf("Adresse invalide\n");
            printf("Entrez l'adresse mail du destinataire: ");
        }
        strncpy(nom, adresse, strlen(adresse) - 8);
        nom[strlen(adresse) - 8] = '\0';

        if (existe_nom(nom) != 1) {
            printf("Cette adresse n'existe pas\n");
        }
    }
    while (existe_nom(nom) != 1);
}
