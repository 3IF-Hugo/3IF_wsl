#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//strcmp(char *, char*) renvoie 0 si les chaines de caractères sont égales

/* mettez ici vos déclarations de fonctions et types */
typedef char * Key;
typedef char * Value;
/* état d’une case (peut être fait aussi avec un enum) */
#define EMPTY 0
#define SET 1
#define REMOVED 2
/* utile pour l’affichage */
const char * Labels[] = {"Empty","Set","Removed"};

/* une cellule de la table */
typedef struct {
    Key key;
    unsigned char status;
    Value val;
} Data;

/* la table de hachage elle-même */
typedef struct {
    Data * tab;
    int size;
} HashTable;

HashTable * Init(int size);
void Insert(HashTable *ht, Key key, Value value);
void Supprimer(HashTable *ht, Key key);
int Requete(HashTable *ht, Key key, Value *v);
void Stat(HashTable *ht);
void Destroy(HashTable *ht);
void Afficher(HashTable *ht);

void error(void);

int main(void) 
{
   int size;
   HashTable *ht;
   char lecture[100];
   char * key;
   char * val;

   if (fscanf(stdin,"%99s",lecture)!=1)
      error();
   while (strcmp(lecture,"bye")!=0)
   {
      if (strcmp(lecture,"init")==0)
      {
         if (fscanf(stdin,"%99s",lecture)!=1)
            error();
         size = atoi(lecture);
         /* mettre le code d'initialisation ici */
         ht = Init(size);
      }
      else if (strcmp(lecture,"insert")==0)
      {
         if (fscanf(stdin,"%99s",lecture)!=1)
            error();
         key = strdup(lecture);
         if (fscanf(stdin,"%99s",lecture)!=1)
            error();
         val = strdup(lecture);
         /* mettre ici le code d'insertion */
         Insert(ht, key, val);
      }
      else if (strcmp(lecture,"delete")==0)
      {
         if (fscanf(stdin,"%99s",lecture)!=1)
            error();
         key = strdup(lecture);
         /* mettre ici le code de suppression */
         Supprimer(ht, key);
      }
      else if (strcmp(lecture,"query")==0)
      {
         if (fscanf(stdin,"%99s",lecture)!=1)
            error();
         /* mettre ici le code de recherche et traitement/affichage du résultat */
         if(Requete(ht, key, &val))
			{
				printf("%s\r\n", val);
			}
			else
			{
				printf("Not found\r\n");
			}
      }
      else if (strcmp(lecture,"destroy")==0)
      {
         /* mettre ici le code de destruction */
         Destroy(ht);
      }
      else if (strcmp(lecture,"stats")==0)
      {
         /* mettre ici le code de statistiques */
         Stat(ht);
      }
      else if (strcmp(lecture,"aff")==0)
      {
          Afficher(ht);
      }

      if (fscanf(stdin,"%99s",lecture)!=1)
         error();
   }
   return 0;
}

//Savoir si le tableau est plein
//unsigned int estPlein(HashTable *ht)

/* fonction de décalage de bit circulaire */
unsigned int shift_rotate(unsigned int val, unsigned int n)
{
  n = n%(sizeof(unsigned int)*8);
  return (val<<n) | (val>> (sizeof(unsigned int)*8-n));
}

/* fonction d'encodage d'une chaîne de caractères */
unsigned int Encode(Key key)
{
   unsigned int i;
   unsigned int val = 0;
   unsigned int power = 0;
   for (i=0;i<strlen(key);i++)
   {
     val += shift_rotate(key[i],power*7);
     power++;
   }
   return val;
}

/* fonction de hachage simple qui prend le modulo */
unsigned int hash(unsigned int val, unsigned int size)
{
   return val%size;
}

/* fonction de hachage complète à utiliser */
unsigned int HashFunction(Key key, unsigned int size)
{
   return hash(Encode(key),size);
}

/* placer ici vos définitions (implémentations) de fonctions ou procédures */

void error(void)
{
   printf("input error\r\n");
   exit(0);
}

//Initialisation
HashTable * Init(int size)
{
    HashTable *ht;
    ht = (HashTable*)malloc(sizeof(HashTable));
    ht->size = size;
    ht->tab = (Data*)malloc(sizeof(Data)*size);
    for(int i=0; i<size; i++)
    {
        ht->tab[i].status = EMPTY;
        ht->tab[i].val = "";
        ht->tab[i].key = "";
    }
    return ht;
}

//Insertion
void Insert(HashTable *ht, Key key, Value value)
{
    int cpt = 0;
    int indice = HashFunction(key, ht->size);
    printf("Indice départ = %d\n", indice);
    int indiceRemoved = 0;
    int indicePrec = 0;
    unsigned int removedFound = 0;
    unsigned int present = 0;

    if(strcmp(ht->tab[indice].key, key) == 0)
    {
      ht->tab[indice].status = SET;
      ht->tab[indice].key = key;
      ht->tab[indice].val = value;
      return;
    }
    if(ht->tab[indice].status == EMPTY)
    {
        ht->tab[indice].status = SET;
        ht->tab[indice].key = key;
        ht->tab[indice].val = value;
    }
    else
    {
        while(ht->tab[indice].status != EMPTY && cpt < ht->size)
        {
            if(ht->tab[indice].status == REMOVED && removedFound == 0)
            {
                indiceRemoved = indice;
                removedFound = 1;
            }

            if(strcmp(ht->tab[indice].key, key) == 0)
            {
               ht->tab[indice].status = SET;
               ht->tab[indice].key = key;
               ht->tab[indice].val = value;
               return;

            }
            
            indicePrec = indice;
            if(indice == ht->size-1)
                indice = 0;
            else
                indice++;
            cpt++;
        }
        if(removedFound == 1)
        {
            ht->tab[indiceRemoved].status = SET;
            ht->tab[indiceRemoved].key = key;
            ht->tab[indiceRemoved].val = value;
            return;
        }
        else if(cpt < ht->size)
        {
            ht->tab[indice].status = SET;
            ht->tab[indice].key = key;
            ht->tab[indice].val = value;
        }
    }

}

//Supprimer
void Supprimer(HashTable *ht, Key key)
{
   int indice = HashFunction(key, ht->size);
   if(strcmp(ht->tab[indice].key,key) == 0)
   {
      ht->tab[indice].status = REMOVED;
      ht->tab[indice].key = "";
      ht->tab[indice].val = "";
      return;
   }
   int indiceInit = indice++;
   indice %= ht->size;
   printf("%d",indice);
   while(ht->tab[indice].status != EMPTY && indice != indiceInit)
   {
      if(strcmp(ht->tab[indice].key,key) == 0)
      {
         ht->tab[indice].status = REMOVED;
         ht->tab[indice].key = "";
         ht->tab[indice].val = "";
         return;
      }
      indice++;
      indice %= ht->size;
   }
   
}

int Requete(HashTable *ht, Key key, Value *v)
{
   int indice = HashFunction(key, ht->size);
   printf("Indice début : %d",indice);

   if(strcmp(ht->tab[indice].key, key) == 0)
   {
      *v = ht->tab[indice].val;
      return 1;
   }

   int indiceInit = indice++;
   indice %= ht->size;
   while(ht->tab[indice].status != EMPTY && indice != indiceInit)
   {
      if(strcmp(ht->tab[indice].key,key) == 0)
      {
         *v = ht->tab[indice].val;
         return 1;
      }
      indice++;
      indice %= ht->size;
   }
/*
   while(ht->tab[indice].status != EMPTY && cpt < ht->size)
   {
      if(!strcmp(ht->tab[indice].key, key))
      {
         printf("%s\r\n", ht->tab[indice].val);
         return;
      }
      indice++;
      indice %= ht->size;
      cpt++;
   }*/
   return 0;
}

void Stat(HashTable *ht)
{
   printf("    : %d\r\n",ht->size);
   int cpt=0;
   int vide=0;
   int supr = 0;
   int used = 0;
   while(cpt < ht->size)
   {
      
   }
}

void Destroy(HashTable *ht)
{
   free(ht->tab);
   free(ht);
}

//Afichage
void Afficher(HashTable *ht)
{
    printf("Size = %d\n", ht->size);
    for(int i=0; i < ht->size; i++)
    {
        printf("Indice = %d; Clé = %s; Valeur = %s; Status = %d\n", i, ht->tab[i].key, ht->tab[i].val, ht->tab[i].status);
    }
}