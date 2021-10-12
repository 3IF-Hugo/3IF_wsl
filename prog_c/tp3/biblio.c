#include <stdio.h>

int somme(int valIn[],int taille)
{
	int i;
	int somme=0;
	for(i=0;i<taille;i++)
		somme = somme + valIn[i];
	
	return somme;
}

int produit(int valIn[],int taille)
{
	int i;
	int produit=1;
	for(i=0; i<taille;i++)
		produit = produit*valIn[i];
	
	return produit;
}

int max(int tab[], int taille){
        int max = -1000000;
        int i;
        for(i=0; i<taille; i++){
                if(tab[i]>max)
                        max = tab[i];
        }
        return max;
}

int min(int tab[], int taille){
        int min = 1000000;
        int i;
        for(i=0; i<taille; i++){
                if(tab[i]<min)
                        min = tab[i];
        }
        return min;
}

float moyenne(int tab[], int taille){
        int i;
        int sum = 0;
        for(i=0; i<taille; i++)
                sum += tab[i];
        float moyenne = (float)sum/(float)taille;
        return moyenne;
}
