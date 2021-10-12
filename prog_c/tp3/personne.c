#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char nom[50];
	char tel[10];
}Personne;

void affiche(Personne z)
{
	printf("%s",z.nom);
	printf(" : %s\r\n",z.tel);
}

int main()
{
	int i=0;
	Personne repertoire[10];
	for(i=0;i<10;i++)
	{
		scanf("%s",repertoire[i].nom);
		scanf("%s",repertoire[i].tel);
	}
	
	for(i=0;i<10;i++)
		affiche(repertoire[i]);
	
	return 0;
}
