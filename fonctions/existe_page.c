#include "../structures/dossier.h"
#include "../constantes.h"

int existe_page(dossier *dos, int page) {
    return page > 0 && (1 + ((*dos).num_messages - 1)/NUM_APERCU) >= page;
}
