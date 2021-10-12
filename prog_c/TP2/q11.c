#include <stdio.h>

int main(){
	int tab[10] ={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int i;
        int *ptr_tab = tab;
	int *ptr_suiveur;
	for(i=0;i<11;i++)
	{
		ptr_suiveur = ptr_tab+i;
                printf("valeur de tab = %d\n",*ptr_suiveur);
	}
return 0;
}