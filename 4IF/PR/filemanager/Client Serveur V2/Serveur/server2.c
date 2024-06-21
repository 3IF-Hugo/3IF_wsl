#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "server2.h"
#include "client2.h"

static void init(void)
{
#ifdef WIN32
   WSADATA wsa;
   int err = WSAStartup(MAKEWORD(2, 2), &wsa);
   if(err < 0)
   {
      puts("WSAStartup failed !");
      exit(EXIT_FAILURE);
   }
#endif
}

static void end(void)
{
#ifdef WIN32
   WSACleanup();
#endif
}

static void app(void)
{
   SOCKET sock = init_connection();
   char buffer[BUF_SIZE];
   char param[BUF_SIZE];
   char message[BUF_SIZE];
   /* the index for the array */
   int actual = 0;
   int max = sock;
   /* an array for all clients */
   Client clients[MAX_CLIENTS];

   fd_set rdfs;

   /* Chargement de l'ensemble des données de l'application*/

   while(1)
   {
      int i = 0;
      FD_ZERO(&rdfs);

      /* add STDIN_FILENO */
      FD_SET(STDIN_FILENO, &rdfs);

      /* add the connection socket */
      FD_SET(sock, &rdfs);

      /* add socket of each client */
      for(i = 0; i < actual; i++)
      {
         FD_SET(clients[i].sock, &rdfs);
      }

      if(select(max + 1, &rdfs, NULL, NULL, NULL) == -1)
      {
         perror("select()");
         exit(errno);
      }

      /* something from standard input : i.e keyboard */
      if(FD_ISSET(STDIN_FILENO, &rdfs))
      {
         /* stop process when type on keyboard */
         break;
      }
      else if(FD_ISSET(sock, &rdfs))
      {
         /* new client */
         SOCKADDR_IN csin = { 0 };
         size_t sinsize = sizeof csin;
         int csock = accept(sock, (SOCKADDR *)&csin, &sinsize);
         if(csock == SOCKET_ERROR)
         {
            perror("accept()");
            continue;
         }

         /* after connecting the client sends its name */
         if(read_client(csock, buffer) == -1)
         {
            /* disconnected */
            continue;
         }
         printf("Le client \" %s \" vient de se connecter \r\n", buffer);

         /* what is the new maximum fd ? */
         max = csock > max ? csock : max;

         FD_SET(csock, &rdfs);

         Client c = { csock };
         strncpy(c.name, buffer, BUF_SIZE - 1);
         c.actual_conversation = 0;
         c.conversation_actuelle = NULL;
         clients[actual] = c;

         write_client(clients[actual].sock, "Veuillez entrer votre mot de passe :");
         read_client(clients[actual].sock, buffer);

         //Le client doit renseigné son mot de passe
         //on appelle la fonction qui va vérifier si le mot de passe est correct
         const char *mot_de_passe = findPwd(clients[actual].name);
         if (strcmp(buffer, mot_de_passe) == 0)
         {
            write_client(clients[actual].sock, "Vous êtes connecté ! \nTaper \" /help \" pour ouvrir le manuel d'utilisation.");
         }
         else
         {
            write_client(clients[actual].sock, "Mot de passe incorrect ! \nDéconnexion...");
            closesocket(clients[actual].sock);
            remove_client(clients, i, &actual);
            strncpy(buffer, c.name, BUF_SIZE - 1);
            strncat(buffer, " disconnected !", BUF_SIZE - strlen(buffer) - 1);
         }
         
         actual++;
         printf("Nombre de client(s) actuellement connecté(s) : %d \r\n\n", actual);
      }
      else
      {
         int i = 0;
         for(i = 0; i < actual; i++)
         {
            /* a client is talking */
            if(FD_ISSET(clients[i].sock, &rdfs))
            {
               Client *client = clients+i;
               /*afficher_client(client);*/
               //memset(buffer, 0, BUF_SIZE);
               int c = read_client(clients[i].sock, buffer);

               //Si buffer commence par / alors c'est une commande sous la forme /commande param
               //commande : quit, group, join, invite, info
               if (buffer[0] == '/')
               {
                  char *commande = strtok(buffer, " ");
                  char *param = strtok(NULL, " ");
                  //strncpy(param,param_in,strlen(param_in)+1);
                  //param = strncat(NULL, strtok(NULL, " "),BUF_SIZE - 1);
                  if (strcmp(commande, "/quit") == 0)
                  {
                     printf("Client %s disconnected from server !\n", client[i].name);
                     write_client(clients[i].sock, "Déconnexion...");
                     closesocket(clients[i].sock);
                     remove_client(clients, i, &actual);
                     strncpy(buffer, client->name, BUF_SIZE - 1);
                     strncat(buffer, " disconnected !", BUF_SIZE - strlen(buffer) - 1);
                  }
                  else if (strcmp(commande, "/group") == 0)
                  {
                     if (param == NULL)
                     {
                        printf("Client %s : Aucun nom de groupe renseigné !\n", client[i].name);
                        write_client(clients[i].sock, "\nAucun nom de groupe renseigné !");
                     }
                     else
                     {
                        printf("Client %s vient de créer le groupe %s !\n", client[i].name, param);
                        sprintf(message, "\nVous venez de créer le groupe %s !\n", param);
                        creer_conversation(client, param);
                        write_client(clients[i].sock, message);
                        //afficher_client(client);
                     }
                  }
                  else if (strcmp(commande, "/join") == 0)
                  {
                     if (param == NULL)
                     {
                        printf("Client %s : Aucun nom de groupe renseigné !\n", client[i].name);
                        write_client(clients[i].sock, "\nAucun nom de groupe renseigné !");
                     }
                     else
                     {
                        sprintf(message, "\nVous avez bien rejoint le groupe %s !\nHistorique de la conversation : \n", param);
                        write_client(client->sock, message);
                        i=0;
                        while(i < client->actual_conversation && strcmp(client->conversations[i++]->nom,param)!= 0)
                        {
                           printf("Conversation %d : %s     Objectif : %s     Resultat : %d\r\n", i-1, client->conversations[i-1]->nom, param, strcmp(client->conversations[i-1]->nom,param));
                        }
                        if(--i >= 0 && strcmp(client->conversations[i]->nom,param) == 0)
                        {
                           client->conversation_actuelle = client->conversations[i];
                           afficher_historique_conversation(client);
                           printf("Le client %s vient de rejoindre la conversation %s\r\n", client->name, client->conversation_actuelle->nom);
                           //persister_participants(client->conversation_actuelle, client->name);
                        }
                     }
                  }
                  else if (strcmp(commande, "/invite") == 0)
                  {
                     if (param == NULL)
                     {
                        printf("Client %s : aucun nom de client renseigné !\n", client[i].name);
                        write_client(clients[i].sock, "\nIl faut renseigner une personne à inviter !");
                     }
                     else
                     {
                        printf("Client  : %s a invité le client : %s dans le groupe : %s\n", client[i].name, param, client->conversation_actuelle->nom);
                        if(client->conversation_actuelle != NULL){
                           inviter_conversation(clients, actual, client->conversation_actuelle, param);
                           sprintf(message, "\nVous avez bien ajouter %s au groupe %s !\n", param, client->conversation_actuelle->nom);
                           write_client(client->sock, message);
                           //write_client(client->sock, "La personne a bien été invité dans le groupe !");
                        }else{
                           write_client(client->sock, "\nVous devez d'abord vous connecter à une conversation !");
                        }
                     }
                  }
                  /*Ne fonctionne pas.
                  else if (strcmp(commande, "/infos") == 0)
                  {
                     if (param != NULL)
                     {
                        printf("La commande \"infos\" ne prend pas de paramètre : %s!\n", param);
                        sprintf(message, "La commande \"infos\" ne prend pas de paramètre : %s!\n", param);
                        write_client(client->sock, message);
                     }
                     else
                     {
                        int nb_clients = 0;
                        for(int i = 0; i < MAX_CLIENTS; i++)
                        {
                           if(client->conversation_actuelle->participants[i] != NULL)
                           {
                              nb_clients++;
                           }
                        }
                        sprintf(message, "\n Nombre de personnes actuellement connectés : %d \n",nb_clients);
                        write_client(client->sock, message);
                     }
                  }*/
                  else if (strcmp(commande, "/help") == 0)
                  {
                     if (param != NULL)
                     {
                        printf("La commande \"help\" ne prend pas de paramètre !\n");
                     }
                     else
                     {
                        write_client(client->sock, "\nManuel d'utlisation : \n - Pour créer un groupe : /group nom_groupe \n -Pour inviter une personne dans le groupe : /invite nom_personne \n - Pour rejoindre un groupe : /join nom_groupe \n - Pour afficher les informations du groupe : /infos \n");
                     }
                  }
                  else
                  {
                     printf("Client %s : command inconnue !\n", client[i].name);
                     write_client(client->sock, "Commande inconnue ! \nTapez /help pour afficher le manuel d'utilisation ! \n");
                  }
               }
               
               /* client disconnected */
               if(c == 0)
               {
                  closesocket(clients[i].sock);
                  remove_client(clients, i, &actual);
                  strncpy(buffer, client->name, BUF_SIZE - 1);
                  strncat(buffer, " disconnected !", BUF_SIZE - strlen(buffer) - 1);
                  if(client->conversation_actuelle!=NULL)
                  {
                     send_message_to_conversation(clients, *client, actual, buffer, 1);
                  }
                  //send_message_to_all_clients(clients, *client, actual, buffer, 1);
               }
               else
               {
                  //send_message_to_all_clients(clients, *client, actual, buffer, 0);
                  if(client->conversation_actuelle!=NULL)
                  {
                     send_message_to_conversation(clients, *client, actual, buffer, 0);
                  }
               }
               break;
            }
         }
      }
   }

   clear_clients(clients, actual);
   end_connection(sock);
}

//Fonction findPwd : Trouve le mot de passe d'un client en fonction de son nom d'utilisateur (fonctionne avec le fichier users.txt)
//Retourne le mot de passe du client en const char*
const char* findPwd(char* name)
{
   FILE* fichier = NULL;
   char ligne[100] = "";
   char* nom = NULL;
   char* pwd = NULL;
   char* token = NULL;
   const char* delim = " ";
   fichier = fopen("users.txt", "r");
   if (fichier != NULL)
   {
      while (fgets(ligne, 100, fichier) != NULL)
      {
         token = strtok(ligne, delim);
         nom = token;
         token = strtok(NULL, delim);
         pwd = token;
         if (strcmp(nom, name) == 0)
         {
            return pwd;
         }
      }
      fclose(fichier);
   }
   return NULL;
}

static void clear_clients(Client *clients, int actual)
{
   int i = 0;
   for(i = 0; i < actual; i++)
   {
      closesocket(clients[i].sock);
   }
}

static void remove_client(Client *clients, int to_remove, int *actual)
{
   /* we remove the client in the array */
   memmove(clients + to_remove, clients + to_remove + 1, (*actual - to_remove - 1) * sizeof(Client));
   /* number client - 1 */
   (*actual)--;
   printf("Le client \" %s \" vient de se déconnecter. \r\n", clients[to_remove].name);
   printf("Nombre de client(s) actuellement connecté(s) : %d \r\n\n", *actual);
}

static void send_message_to_all_clients(Client *clients, Client sender, int actual, const char *buffer, char from_server)
{
   int i = 0;
   char message[BUF_SIZE];
   message[0] = 0;
   for(i = 0; i < actual; i++)
   {
      /* we don't send message to the sender */
      if(sender.sock != clients[i].sock)
      {
         if(from_server == 0)
         {
            strncpy(message, sender.name, BUF_SIZE - 1);
            strncat(message, " : ", sizeof message - strlen(message) - 1);
         }
         strncat(message, buffer, sizeof message - strlen(message) - 1);
         write_client(clients[i].sock, message);
      }
   }
}

static void send_message_to_conversation(Client *clients, Client sender, int actual, const char *buffer, char from_server)
{
   int i = 0;
   char message[BUF_SIZE];
   message[0] = 0;

   //Ajout du message à l'historique
   Historique* nouveau_historique = (Historique*) malloc(sizeof(Historique));
   strncpy(nouveau_historique->expediteur, sender.name, strlen(sender.name));
   strncpy(nouveau_historique->message, buffer, BUF_SIZE - 1);
   nouveau_historique->message_suivant = NULL;
   if(sender.conversation_actuelle->debut_historique == NULL)
   {
      sender.conversation_actuelle->debut_historique = nouveau_historique;
      sender.conversation_actuelle->fin_historique = nouveau_historique;
   } else{
      sender.conversation_actuelle->fin_historique->message_suivant = nouveau_historique;
      nouveau_historique->message_precedent = sender.conversation_actuelle->fin_historique;
      sender.conversation_actuelle->fin_historique = nouveau_historique;
   }
   afficher_historique(sender.conversation_actuelle);

   persister_historique(sender.conversation_actuelle->nom, nouveau_historique);
   
   for(i = 0; i < actual; i++)
   {
      /* we don't send message to the sender */
      if(sender.sock != clients[i].sock && sender.conversation_actuelle == clients[i].conversation_actuelle)
      {
         if(from_server == 0)
         {
            strncpy(message, sender.name, BUF_SIZE - 1);
            strncat(message, " : ", sizeof message - strlen(message) - 1);
         }
         strncat(message, buffer, sizeof message - strlen(message) - 1);
         write_client(clients[i].sock, message);
      }
   }
}

static int init_connection(void)
{

   SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
   SOCKADDR_IN sin = { 0 };

   if(sock == INVALID_SOCKET)
   {
      perror("socket()");
      exit(errno);
   }

   sin.sin_addr.s_addr = htonl(INADDR_ANY);
   sin.sin_port = htons(PORT);
   sin.sin_family = AF_INET;

   if(bind(sock,(SOCKADDR *) &sin, sizeof sin) == SOCKET_ERROR)
   {
      perror("bind()");
      exit(errno);
   }

   if(listen(sock, MAX_CLIENTS) == SOCKET_ERROR)
   {
      perror("listen()");
      exit(errno);
   }

   return sock;
}

static void end_connection(int sock)
{
   closesocket(sock);
}

static int read_client(SOCKET sock, char *buffer)
{
   int n = 0;

   if((n = recv(sock, buffer, BUF_SIZE - 1, 0)) < 0)
   {
      perror("recv()");
      /* if recv error we disonnect the client */
      n = 0;
   }

   buffer[n] = 0;

   return n;
}

static void write_client(SOCKET sock, const char *buffer)
{
   if(send(sock, buffer, strlen(buffer), 0) < 0)
   {
      perror("send()");
      exit(errno);
   }
}

static Conversation *creer_conversation(Client *client, char *nom_conversation)
{
   Conversation* conversation = (Conversation*) malloc(sizeof(Conversation));
   conversation->debut_historique = NULL;
   conversation->fin_historique = NULL;
   conversation->nb_participants = 1;
   strncpy(conversation->participants[0],client->name,BUF_SIZE-1);
   strncpy(conversation->nom, nom_conversation, BUF_SIZE - 1);
   client->conversations[client->actual_conversation++] = conversation;
   printf("Conversation %s a bien ete creee\r\n", nom_conversation);
   client->conversation_actuelle = conversation;

   //Persistence
   persister_conversation(conversation);
   persister_participants(conversation->nom, client->name);

   //afficher_client(client);
   return conversation;
}

static void inviter_conversation(Client *clients, int actual, Conversation *conversation, char *participant)
{
   int i = 0;
   while(i < actual && strcmp(clients[i++].name,participant));
   if(strcmp(clients[--i].name,participant) == 0)
   {
      clients[i].conversations[clients[i].actual_conversation++] = conversation;        //Rajouter une erreur quand on arrive à 50
      strncpy(conversation->participants[conversation->nb_participants++],participant,BUF_SIZE-1);
      persister_participants(conversation->nom, participant);
      printf("Le client %s vient d'etre ajoute dans %s\r\n", participant, conversation->nom);
   }

}

//Pour l'instant on estime que le serveur n'envoie pas de messages à un groupe
static void afficher_historique_conversation(Client *client)
{
   afficher_historique(client->conversation_actuelle);
   Historique* message = client->conversation_actuelle->debut_historique;
   char buffer[BUF_SIZE];
   while(message != NULL)
   {
      if(strcmp(client->name, message->expediteur)!=0)
      {
         strncpy(buffer, message->expediteur, BUF_SIZE - 1);
      } else{
         strncpy(buffer, "                         moi", BUF_SIZE - 1);
      }
      strncat(buffer, " : ", sizeof buffer - strlen(buffer) - 1);
      strncat(buffer, message->message, sizeof buffer - strlen(buffer) - 1);
      write_client(client->sock, buffer);
      write_client(client->sock, "\n");
      message = message->message_suivant;
   }
}

static void persister_client(Client *client)
{
   FILE* fichier = fopen("clients.txt", "a");

   //Ajout du nom du client et son mot de passe dans le fichier
   char buffer[BUF_SIZE];
   strncpy(buffer, client->name, BUF_SIZE-1);
   strncat(buffer, ";", BUF_SIZE-1);
   strncat(buffer, client->password, BUF_SIZE-1);
   strncat(buffer, "\n", BUF_SIZE-1);
   fputs(buffer, fichier);

   fclose(fichier);
}

static void persister_conversation(Conversation *conversation)
{
   FILE* fichier = fopen("conversations.txt", "a");

   //Ajout du nom de la conversation dans le fichier
   char buffer[BUF_SIZE];
   strncpy(buffer, conversation->nom, BUF_SIZE-1);
   strncat(buffer, "\n", BUF_SIZE-1);
   fputs(buffer, fichier);

   fclose(fichier);
}

static void persister_participants(const char* nom_conversation, const char *participant)
{
   char buffer[BUF_SIZE];
   strncpy(buffer, nom_conversation, BUF_SIZE-1);
   strncat(buffer, "_participants.txt", BUF_SIZE-1);
   FILE* fichier = fopen(buffer, "a");

   strncpy(buffer, participant, BUF_SIZE-1);
   strncat(buffer, "\n",BUF_SIZE-1);

   //Ecriture dans le fichier
   
   fputs(buffer, fichier);
   fclose(fichier);
}

static void persister_historique(const char* nom_conversation, Historique *historique)
{
   char buffer[BUF_SIZE];
   
   //Ouverture du fichier correspondant à la conversation
   strncpy(buffer, nom_conversation, BUF_SIZE-1);
   strncat(buffer, "_historique.txt", sizeof buffer - strlen(buffer) - 1);
   FILE* fichier = fopen(buffer, "a");

   //Mise en forme des données à stocker pour chaque message (historique)
   strncpy(buffer, historique->expediteur, BUF_SIZE-1);
   strncat(buffer, ";", BUF_SIZE-1);
   strncat(buffer, historique->message, BUF_SIZE-1);
   strncat(buffer, "\n", BUF_SIZE-1);
   fputs(buffer, fichier);

   //Fermer le fichier
   fclose(fichier);
}

static void afficher_client(Client *client)
{
   printf("Nom :%s - Conversation actuelle :%s - index %d\r\n", client->name, client->conversation_actuelle->nom, client->actual_conversation);
}

//Test pour le serveur
static void afficher_historique(Conversation *conversation)
{
   printf("---Debut affichage historique\r\n");
   Historique* message = conversation->debut_historique;
   while(message != NULL)
   {
      printf("Message : '%s'\r\n", message->message);
      message = message->message_suivant;
   }
   printf("---Fin affichage historique\r\n");
}

int main(int argc, char **argv)
{
   init();

   app();

   end();

   return EXIT_SUCCESS;
}
