#ifndef UTILISATEUR_H_INCLUDED
#define UTILISATEUR_H_INCLUDED
#include "dossier.h"

struct utilisateur {
    char nom[21];
    int num_dossiers, num_bloque;
    dossier dossiers[8];
    char util_bloques[10][21];
};
typedef struct utilisateur utilisateur;

#endif // UTILISATEUR_H_INCLUDED
