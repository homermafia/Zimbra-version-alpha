#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED

struct message {
    char expediteur[21], destinataire[21], titre[31], corps[501], dossier[21];
    int date, lu;
};
typedef struct message message;

#endif // MESSAGE_H_INCLUDED
