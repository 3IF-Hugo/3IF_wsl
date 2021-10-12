#include <stdio.h>

int main(){
        int tab[10][2];
        int i;
	int j;
	for(i=0;i<10;i++)
		for(j=0;j<2;j++)
                	printf("valeur de tab = %p\n",&tab[i][j]);
return 0;
}