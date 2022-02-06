#include <stdio.h>
#include <math.h>

void initL(int *tab[], int capacite, int nbObjet)
{
    for(int j = 1; j < capacite+1; j++)
    {
        tab[0][j] = 0;
    }

    for(int i = 0; i < nbObjet+1; i++)
    {
        tab[i][0] = 0;
    }
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

    //Initialisation Premier Bateau avec Argent
    int LB1Ar[nbObjetArgent+1][capaciteBat1+1];
    for(int j = 1; j < capaciteBat1+1; j++)
    {
        LB1Ar[0][j] = 0;
    }

    for(int i = 0; i < nbObjetArgent+1; i++)
    {
        LB1Ar[i][0] = 1;
    }
   
    for(i = 1; i < nbObjetArgent+1; i++)
    {
        for(j = 1; j < capaciteBat1+1; j++)
        {
            if((LB1Ar[i-1][j] == 1) || ((j - tabObjetArgent[i-1]) >= 0 && LB1Ar[i-1][j-tabObjetArgent[i-1]] == 1))
            {
                LB1Ar[i][j] = 1;
            }else 
            {
                LB1Ar[i][j] = 0;
            }
        }
    }

    int resB1Ar = 0;

    for(int i = 1; i < capaciteBat1+1; i++)
    {
        if(LB1Ar[nbObjetArgent][i] == 1)
        {
            resB1Ar = i;
        }
    }

    printf("%d\n", resB1Ar);
    //B1Ar
    //Initialisation Deuxième Bateau avec Argent
    int LB2Ar[nbObjetArgent+1][capaciteBat2+1];
    for(int j = 1; j < capaciteBat2+1; j++)
    {
        LB2Ar[0][j] = 0;
    }

    for(int i = 0; i < nbObjetArgent+1; i++)
    {
        LB2Ar[i][0] = 1;
    }

    for(i = 1; i < nbObjetArgent+1; i++)
    {
        for(j = 1; j < capaciteBat2+1; j++)
        {
            if((LB2Ar[i-1][j] == 1) || ((j - tabObjetArgent[i-1]) >= 0 && LB2Ar[i-1][j-tabObjetArgent[i-1]] == 1))
            {
                LB2Ar[i][j] = 1;
            }else 
            {
                LB2Ar[i][j] = 0;
            }
        }
    }

    int resB2Ar = 0;

    for(int i = 1; i < capaciteBat2+1; i++)
    {
        if(LB2Ar[nbObjetArgent][i] == 1)
        {
            resB2Ar = i;
        }
    }
    printf("%d\n", resB2Ar);

    if(resB1Ar >= resB2Ar)
    {
        resArgent = resB1Ar;
    }else if(resB1Ar < resB2Ar)
    {
        resArgent = resB2Ar;
    }

    //printf("resArgent %d\n", resArgent);


    //Pour l'or
    //Initialisation Premier Bateau avec Or
    int LB1Or[nbObjetOr+1][capaciteBat1+1];
    for(int j = 1; j < capaciteBat1+1; j++)
    {
        LB1Or[0][j] = 0;
    }

    for(int i = 0; i < nbObjetOr+1; i++)
    {
        LB1Or[i][0] = 1;
    }
   
    for(i = 1; i < nbObjetOr+1; i++)
    {
        for(j = 1; j < capaciteBat1+1; j++)
        {
            if((LB1Or[i-1][j] == 1) || ((j - tabObjetOr[i-1]) >= 0 && LB1Or[i-1][j-tabObjetOr[i-1]] == 1))
            {
                LB1Or[i][j] = 1;
            }else 
            {
                LB1Or[i][j] = 0;
            }
        }
    }

    int resB1Or = 0;

    for(int i = 1; i < capaciteBat1+1; i++)
    {
        if(LB1Or[nbObjetOr][i] == 1)
        {
            resB1Or = i;
        }
    }

    printf("%d\n", resB1Or);

    //Initialisation Deuxième Bateau avec Or
    int LB2Or[nbObjetOr+1][capaciteBat2+1];
    for(int j = 1; j < capaciteBat2+1; j++)
    {
        LB2Or[0][j] = 0;
    }

    for(int i = 0; i < nbObjetOr+1; i++)
    {
        LB2Or[i][0] = 1;
    }
   
    for(i = 1; i < nbObjetOr+1; i++)
    {
        for(j = 1; j < capaciteBat2+1; j++)
        {
            if((LB2Or[i-1][j] == 1) || ((j - tabObjetOr[i-1]) >= 0 && LB2Or[i-1][j-tabObjetOr[i-1]] == 1))
            {
                LB2Or[i][j] = 1;
            }else 
            {
                LB2Or[i][j] = 0;
            }
        }
    }

    int resB2Or = 0;

    for(int i = 1; i < capaciteBat2+1; i++)
    {
        if(LB2Or[nbObjetOr][i] == 1)
        {
            resB2Or = i;
        }
    }

    printf("%d\n", resB2Or);
    
    //Comparaison
    
    int resB1OrB2Ar = resB1Or+resB2Ar;
    int resB2OrB1Ar = resB2Or+resB1Ar;
    
    
    printf("resB1OrB2Ar %d\n", resB1OrB2Ar);
    printf("resB2OrB1Ar %d\n", resB2OrB1Ar);
    

    int resTotal = 0;
    if(resB1OrB2Ar >= resB2OrB1Ar)
    {
        resTotal = resB1OrB2Ar;
    }else if(resB1OrB2Ar < resB2OrB1Ar)
    {
        resTotal = resB2OrB1Ar;
    }
    // printf("resOr %d\n", resOr);
    // printf("\n");

    //Ajout des deux et résultat
    //int resTotal = resArgent + resOr;
    printf("%d\r\n", resTotal);

    return 0;
}


    // //AFFICHAGE
    // for(int i = 0; i < nbObjetArgent+1; i++)
    // {
    //     for(int j = 0; j < capaciteBat1+1; j++)
    //     {
    //         printf("%d ", LB1Ar[i][j]);
    //     }
    //     printf("\n");
    // }