#include <stdio.h>

int main(){
//question 7
int tab[10] ={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int i;
	int *ptr_tab = tab; 
	for(i=0;i<10;i++)
        	printf("valeur de tab = %d\n",*ptr_tab+i);


	int *ptr_tab = tab; 
	for(i=9;i!=1;i=i-2)
        	printf("valeur de tab = %d\n",*ptr_tab+i);
		
return 0;
}