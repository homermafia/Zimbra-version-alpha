#ifndef DOSSIER_H_INCLUDED
#define DOSSIER_H_INCLUDED
#include "message.h"

struct dossier {
    char nom[21];
    int num_messages;
    message messages[20];
};
typedef struct dossier dossier;

#endif // DOSSIER_H_INCLUDED
