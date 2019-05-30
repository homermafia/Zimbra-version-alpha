#ifndef UTILISATEUR_H_INCLUDED
#define UTILISATEUR_H_INCLUDED
#include "../constantes.h"
#include "dossier.h"

struct utilisateur {
    char nom[21];
    int num_dossiers, num_bloques;
    dossier dossiers[MAX_DOSSIERS];
    char util_bloques[MAX_BLOQUES][21];
};
typedef struct utilisateur utilisateur;

#endif // UTILISATEUR_H_INCLUDED
