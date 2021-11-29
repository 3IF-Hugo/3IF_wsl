#include <stdio.h>
#include <stdlib.h>

void init(int nbObjet, int capacite, int *resultat, int tab[])
{
    //Initialisation
    int LB1Ar[nbObjet+1][capacite+1];
    for(int j = 1; j < capacite+1; j++)
    {
        LB1Ar[0][j] = 0;
    }

    for(int i = 0; i < nbObjet+1; i++)
    {
        LB1Ar[i][0] = 1;
    }

    int i,j;
    for(i = 1; i < nbObjet+1; i++)
    {
        for(j = 1; j < capacite+1; j++)
        {
            if((LB1Ar[i-1][j] == 1) || ((j - tab[i-1]) >= 0 && LB1Ar[i-1][j-tab[i-1]] == 1))
            {
                LB1Ar[i][j] = 1;
            }else 
            {
                LB1Ar[i][j] = 0;
            }
        }
    }

    int resB1Ar = 0;

    for(int i = 1; i < capacite+1; i++)
    {
        if(LB1Ar[nbObjet][i] == 1)
        {
            resB1Ar = i;
        }
    }

    *resultat = resB1Ar;
}



int main()
{
    int i,j;
    int capaciteBat1;
    int capaciteBat2;
    int nbObjetArgent;
    int nbObjetOr;
    int resArgent = 0;
    int resOr = 0;

    fscanf(stdin,"%d",&capaciteBat1);
    fscanf(stdin,"%d",&capaciteBat2);
    fscanf(stdin,"%d",&nbObjetArgent);
    fscanf(stdin,"%d",&nbObjetOr);

    int tabObjetArgent[nbObjetArgent];
    int tabObjetOr[nbObjetOr];

    for(int i = 0; i < nbObjetArgent; i++)
    {
        fscanf(stdin,"%d",&tabObjetArgent[i]);
    }

    for(int i = 0; i < nbObjetOr; i++)
    {
        fscanf(stdin,"%d",&tabObjetOr[i]);
    }

    int *resB1Ar = (int*) malloc(sizeof(int));
    init(nbObjetArgent, capaciteBat1, resB1Ar, tabObjetArgent);

    int *resB2Ar = (int*) malloc(sizeof(int));
    init(nbObjetArgent, capaciteBat2, resB2Ar, tabObjetArgent);

    int *resB1Or = (int*) malloc(sizeof(int));
    init(nbObjetOr, capaciteBat1, resB1Or, tabObjetOr);

    int *resB2Or = (int*) malloc(sizeof(int));
    init(nbObjetOr, capaciteBat2, resB2Or, tabObjetOr);

    int resB1OrB2Ar = *resB1Or + *resB2Ar;
    int resB2OrB1Ar = *resB2Or+ *resB1Ar;
    
    
    // printf("resB1OrB2Ar %d\n", resB1OrB2Ar);
    // printf("resB2OrB1Ar %d\n", resB2OrB1Ar);
    

    int resTotal = 0;
    if(resB1OrB2Ar >= resB2OrB1Ar)
    {
        resTotal = resB1OrB2Ar;
    }else if(resB1OrB2Ar < resB2OrB1Ar)
    {
        resTotal = resB2OrB1Ar;
    }

    printf("%d\r\n", resTotal);

    free(resB1Ar);
    free(resB1Or);
    free(resB2Or);
    free(resB2Ar);

    return 0;
}