#include <string.h>

int nom_valide(char nom[]) {
    int i = 0;

    if (nom[0] == '\0') {
        return 1;
    }
    else {
        while ((((int) nom[i] >= 65 && (int) nom[i] <= 90) || ((int) nom[i] >= 97 && (int) nom[i] <= 122)) && i <= strlen(nom) - 1) {
            i = i + 1;
        }
        return strlen(nom) - i;
    }
}
