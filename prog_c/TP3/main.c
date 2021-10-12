#include <stdio.h>
#include "biblio.h"

int main()
{
	int taille;
	int sum;
	int prod;
	double moy;
	int i;
	const int max = 10;
	do
	{
		scanf("%d", &taille);
	}while(taille > max);

	int tableauACalculer[taille];
	for(i=0;i<taille;i++)
	{
		scanf("%d", &tableauACalculer[i]);
	
	}

	sum = somme(tableauACalculer,taille);
	prod = produit(tableauACalculer,taille);
	moy = moyenne(tableauACalculer,taille);

	printf("somme %d\n",sum);
	printf("produit %d\n",prod);
	printf("moyenne %lf\n",moy);

return 0;
}
