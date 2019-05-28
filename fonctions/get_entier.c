#include <stdio.h>
#include <stdlib.h>
#include "vider_buffer.h"

int get_entier(int *entier) {
    char c_entier[3];

    fgets(c_entier, 3, stdin);
    vider_buffer();

    *entier = atoi(c_entier);

    printf("%d\n", (c_entier[0] < 48 && c_entier[0] > 57) || (c_entier[1] < 48 && c_entier[1] > 57));

    return 1;
}
