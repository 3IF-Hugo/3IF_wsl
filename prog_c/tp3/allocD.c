#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,j;
	int N;
	scanf("%d",&N);
	int *monTab = (int*) malloc(sizeof(int)*N);
	int min = 10000;
	int max = 0;
	int sum=0;
	double moy=0;
	for(i=0;i<N;i++)
	{
		scanf("%d", &monTab[i]);
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
	printf("min %d\n",min);
	printf("max %d\n",max);
	printf("moy %lf\n",moy);

	return 0;
}
