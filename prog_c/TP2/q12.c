#include <stdio.h>

int main(){
        int tab[10] ={1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10};
        int tab2[10] ={101, 102,103,104,105,106,107,108,109,110};
	int i;
        int *ptr_tab = tab;
	int *ptr_suiveur;
	ptr_suiveur=ptr_tab+15;
        printf("valeur de tab à la 15eme place= %d\n",*ptr_suiveur);
return 0;
}