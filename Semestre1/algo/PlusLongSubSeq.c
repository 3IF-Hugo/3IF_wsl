#include <stdio.h>

int main()
{
    int i,j;
    int tailleSeq;
    int maxSub = 0;
    fscanf(stdin,"%d",&tailleSeq);

    int tabChiffres[tailleSeq];

    for(i = 0; i < tailleSeq; i++)
    {
        fscanf(stdin,"%d",&tabChiffres[i]);
    }

    int tableRes[tailleSeq];
    tableRes[0] = 0;

    for(i = 1; i < tailleSeq; i++)
    {
        maxSub = 0;
        for(j = 0; j < i; j++)
        {
            if(tabChiffres[j] < tabChiffres[i])
            {
                if(tableRes[j] > maxSub)
                {
                    maxSub = tableRes[j];
                }
            }
        }
        tableRes[i] = 1 + maxSub;
        printf("%d %d\n", tableRes[i], maxSub);
    }

    printf("\n");
    for(i = 0; i<tailleSeq; i++)
    {
        printf("%d ", tableRes[i]);
    }
    
    printf("\n");

    int maxFin = 0;
    for(i = 0; i < tailleSeq; i++)
    {
        if(tableRes[i] > maxFin)
        {
            maxFin = tableRes[i];
        }
    }

    printf("%d\r\n", maxFin);

    return 0;
}