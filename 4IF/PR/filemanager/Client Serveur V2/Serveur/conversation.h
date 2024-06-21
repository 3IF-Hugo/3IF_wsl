#ifndef CONVERSATION_H
#define CONVERSATION_H

#include "server2.h"
#include "historique.h"

typedef struct
{
   char nom[BUF_SIZE];
   char participants[MAX_PARTICIPANTS][BUF_SIZE];
   int nb_participants;
   Historique* debut_historique;
   Historique* fin_historique;
}Conversation;

#endif /* guard */