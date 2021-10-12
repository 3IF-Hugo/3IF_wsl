#include <stdio.h>
#include <stdlib.h>

typedef struct _elem
{
	int value;
	struct _elem* next;
} elem;

typedef struct _treenode
{
	int value;
	struct _treenode* left;
	struct _treenode* right;
} treenode;
/*
// un arbre vide
	treenode* root=NULL;

// creation d’un noeud racine
	treenode* node=malloc(...);
	node->value=42;
	node->left=NULL;
	node->right=NULL;
	root=node;
*/
elem* list = NULL;

void afficher(void)
{
	printf("Affichage de la liste :\n");
	elem* listPrint= list;
	while(listPrint != NULL)
	{
		printf("%d\n",listPrint->value);
		listPrint = listPrint->next;
	}
	printf("Fin de la liste\n");
}

void ajouter_en_tete(void)
{

// creation d’un nouveau maillon
	printf("Tapez un nombre\r\n");
	int val;	
	scanf("%d",&val);
	elem* e = malloc(sizeof(elem));

// insertion en tete de liste
	(*e).next = list;
	(*e).value = val;
	list=e;
}

void ajouter_en_queue(void)
{

// creation d’un nouveau maillon
	printf("Tapez un nombre\r\n");
	int val;	
	scanf("%d",&val);
	elem* e = list;

// insertion en queue
	while((*e).next != NULL)
	{
		e = (*e).next;
	}
	elem* nouveau = malloc(sizeof(elem));
	(*e).next = nouveau;
	nouveau->next=NULL;
	(*nouveau).value = val;
}

void rechercher(void)
{
	int res;
	int cpt=0;
	int pos=1;
	elem* listSearch = list;
	printf("Quel nombre rechercher ? \n");
	scanf("%d",&res);
	while(listSearch != NULL)
	{
		if(listSearch->value == res)
		{
			printf("Sa position est : %d\n",pos);
			cpt++;
		}
		
		listSearch = listSearch->next;
		
		if(listSearch == NULL && cpt == 0)							
		{
			printf("Pas trouvé \n");
			break;
		}
		
		pos++;
	}	
}

void supprimer(void)
{
	int valAsuppr;
	printf("Quel nombre supprimer ? \n");
	scanf("%d",&valAsuppr);
	
	elem* aSupprimer = NULL;
	while(list->value==valAsuppr){
    	aSupprimer=list;
        list=(*list).next;
        free(aSupprimer);
		elem* aSupprimer = NULL;
    }

	elem* courant=list;
	elem* precedent=NULL;
	
	if(courant==NULL)
	{}else
	{
		while(courant->next != NULL)
		{
			if(courant->value == valAsuppr)
			{
				aSupprimer=courant;
				precedent->next= courant->next;
				courant=courant->next;
				free(aSupprimer);
				elem* aSupprimer = NULL;

			}
			precedent=courant;
			courant=courant->next;
		}	

		if(courant->value==valAsuppr)
		{
			aSupprimer=courant;
			free(aSupprimer);
			precedent->next=NULL;
		}
	}
}

void dupliquer()
{
	int valAdup;
	printf("Quel nombre dupliquer ? \n");
	scanf("%d",&valAdup);

	elem* courant=list;
	elem* suivant= NULL;

	while(courant != NULL)
	{
		if(courant->value == valAdup)
		{
			elem* e=malloc(sizeof(elem));
			e->value=valAdup;
			e->next=courant->next;
			courant->next = e;
			courant=e->next;		//on actualise la position du courant pour qu'il saute la case qu'on vient de créer
			
		}else{
			courant= courant->next;
		}
		
	}
}

void est_triee()
{
	int cpt=0;
	int trie=0;
	elem* courant=list;
	elem* precedent=list;

	while(courant->next != NULL)
	{
		courant = courant->next;
		if(precedent->value < courant->value)
		{
			trie++;
		}
		precedent = precedent->next;	
		cpt++;
	}
	if(cpt==trie)
	{
		printf("Oui\n");
	}else{
		printf("Non\n");
	}
}

void ajouter_en_place()
{
	int valAjouter;
	int fin =0;
	printf("Quel nombre ajouter ? \n");
	scanf("%d",&valAjouter);
	
	
	elem* courant=list->next;
	elem* precedent=list;

	if(valAjouter < list->value)
	{
		printf("Vous ajoutez en tete");
		ajouter_en_tete();
	}else
	{
		while(fin!=1)
		{
			if(courant->next == NULL)
			{
				printf("Vous ajoutez en fin\n");
				ajouter_en_queue();
				fin=1;
			}
			if((courant->value) > valAjouter && valAjouter>(precedent->value))
			{
				elem* nouveau = malloc(sizeof(elem));
				nouveau->next = courant;
				precedent->next = nouveau;
				nouveau->value = valAjouter;
				fin=1;
			}
			precedent=precedent->next;
			courant = courant->next;
		}
	}
}

void retourner()
{
	elem* pointeur1 = NULL;
	elem* head = list;
	elem* pointeur2 = head->next;
	while(pointeur2 != NULL)
	{
		head->next=pointeur1;
		pointeur1 = head;
		head = pointeur2;
		pointeur2= pointeur2->next;
	}
	head->next=pointeur1;
	list=head;
}

int main(void)
{
	while(1)
	{
		printf("menu:\n");
		printf("\t1: ajouter en tete\n");
		printf("\t2: afficher la liste\n");
		printf("\t3: rechercher\n");
		printf("\t4: ajouter en queue\n");
		printf("\t5: Supprimer\n");
		printf("\t6: Dupliquer\n");
		printf("\t7: Est triee\n");
		printf("\t8: Ajouter en place\n");
		printf("\t9: Retourner\n");
		printf("\t0: quitter\n");
		int choix;
		scanf("%d", &choix);
		switch(choix)
		{
			case 0:
				goto fin;
			case 1:
				ajouter_en_tete();
				break;
			case 2:
				afficher();
				break;
			case 3: 
				rechercher();
				break;
			case 4: 
				ajouter_en_queue();
				break;
			case 5:
				supprimer();
				break;
			case 6:
				dupliquer();
				break;
			case 7:
				est_triee();
				break;
			case 8:
				ajouter_en_place();
				break;
			case 9:
				retourner();
				break;
			default:
				printf("choix incorrect\n");
				continue ; // revenir au menu
		}
	}
	fin:
	printf("Au revoir\n");
	return 0;
}
