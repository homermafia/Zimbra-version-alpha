#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vider_buffer.h"
#define MAX_CHIFFRE 2

int get_entier(void) {
    char c_entier[MAX_CHIFFRE + 2];
    int i = 0;

    if (fgets(c_entier, MAX_CHIFFRE + 2, stdin) != NULL) {
        while (i <= MAX_CHIFFRE + 1 && c_entier[i] >= 48 && c_entier[i] <= 57) {
            i = i + 1;
        }
        if (c_entier[i] == '\n') {
            c_entier[i] = '\0';
            return atoi(c_entier);
        }
        else {
            if (c_entier[strlen(c_entier) - 1] != '\n') { /* buffer overflow */
                vider_buffer();
            }
        }
    }
    else {
        vider_buffer();
    }

    return -1;
}
