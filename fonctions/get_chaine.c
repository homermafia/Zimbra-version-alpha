#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vider_buffer.h"

int get_chaine(char chaine[], int taille) {
    char ch[taille + 1];
    int i = 0;

    if (fgets(ch, taille + 1, stdin) != NULL) {
        while (ch[i] != '\0') {
            i = i + 1;
        }
        if (ch[i - 1] == '\n') {
            ch[i - 1] = '\0';
            strcpy(chaine, ch);
            return 1;
        }
        else {
            vider_buffer();
        }
    }
    else {
        vider_buffer();
    }

    return 0;
}
