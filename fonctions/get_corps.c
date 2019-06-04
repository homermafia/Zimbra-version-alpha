#include <stdio.h>
#include <stdlib.h>
#include "get_chaine.h"

void get_corps(char corps[]) {
    printf("Entrez le corps de votre message (<= 500 caracteres):\n");

    while (get_chaine(corps, 501) != 1) {
        printf("Ce message est trop long !\n");
        printf("Entrez le corps de votre message (<= 500 caracteres):\n");
    }
}
