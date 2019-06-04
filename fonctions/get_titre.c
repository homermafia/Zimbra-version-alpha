#include <stdio.h>
#include <stdlib.h>
#include "get_chaine.h"

void get_titre(char titre[]) {
    printf("Entrez le titre de votre message (<= 30 caracteres): ");

    while (get_chaine(titre, 31) != 1) {
        printf("Ce titre est trop long !\n");
        printf("Entrez le titre de votre message (<= 30 caracteres): ");
    }
}
