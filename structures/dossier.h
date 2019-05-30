#ifndef DOSSIER_H_INCLUDED
#define DOSSIER_H_INCLUDED
#include "../constantes.h"
#include "message.h"

struct dossier {
    char nom[21];
    int num_messages;
    message messages[MAX_MESSAGES];
};
typedef struct dossier dossier;

#endif // DOSSIER_H_INCLUDED
