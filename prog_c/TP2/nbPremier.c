#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
        int i,j,n_diviseurs;
	int valeur = atoi(argv[1]);
	if(argv[2] != NULL)
	{
		printf("il faut le nom de l'éxécutable et UN param : ./tp2 34\n");
		return 0;
	}
	printf("%d\n",1);
	for(i=1;i<=valeur;i++) 
	{ 
		n_diviseurs=0; 
		for(j=1;j<=i;j++)  
		{ 
			if(i%j==0) 
				n_diviseurs=n_diviseurs+1; 
		} if(n_diviseurs==2) 
			printf("%d\n",i); 
	}

return 0;
}