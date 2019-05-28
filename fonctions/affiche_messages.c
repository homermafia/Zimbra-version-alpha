#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../structures/utilisateur.h"
#include "../structures/dossier.h"

void affiche_messages(utilisateur util,dossier dos) {
    int i;
    char m[100];
    for(i=1;i<=dos.num_messages;i++){
        itoa(i,m,10);
        strcat(m,".");
        if(dos.messages[i].lu==0){
            strcat(m,"***");
        }
        strcat(m,dos.messages[i].expediteur);
        strcat(m," : ");
        strcat(m,dos.messages[i].titre);
        strcat(m," - ");
        strcat(m,convertir_date(dos.messages[i].date));
        printf("%s",m);
    }
}
