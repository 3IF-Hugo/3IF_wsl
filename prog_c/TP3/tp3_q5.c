#include <stdio.h>
#include <stdlib.h>

int main(){
        int filled = 0;
        int N = 5;
        int j;
	int min=40000;
	int max=0;
	double moy=0;
	int sum=0;
	int *monTab = (int*)malloc(sizeof(int)*N);
        while(1){
                if(filled == N){
                        N *= 2;
                        monTab = (int*)realloc(monTab, sizeof(int)*N);
                }
                int number;
                int nbtokens = scanf("%d", &number);
                if(nbtokens != 1 || feof(stdin))
                        break;
                monTab[filled] = number;
                filled++;
        }
	for(j=0;j<N;j++)
	{
		if(monTab[j]<min)
			min = monTab[j];
	}

	for(j=0;j<N;j++)
	{
		if(monTab[j]>max)
		{
			max = monTab[j];
		}
	}
	
	for(j=0;j<N;j++)
		sum = sum + monTab[j];
	
	moy = sum/N;


        printf("N = %d, Min : %d, Max : %d, Moyenne : %f\n", filled, min, max, moy);
        free(monTab);
        return 0;
}
