#include <stdio.h>

int main()
{
	int i,j;
	int monTab[10];
	int min = 10000;
	int max = 0;
	int sum=0;
	double moy=0;
	for(i=0;i<10;i++)
	{
		scanf("%d", &monTab[i]);
	}
	
	for(j=0;j<10;j++)
	{
		if(monTab[j]<min)
			min = monTab[j];
	}

	for(j=0;j<10;j++)
	{
		if(monTab[j]>max)
		{
			max = monTab[j];
		}
	}
	
	for(j=0;j<10;j++)
		sum = sum + monTab[j];
	
	moy = sum/10;
	printf("min %d\n",min);
	printf("max %d\n",max);
	printf("moy %lf\n",moy);

	return 0;
}
