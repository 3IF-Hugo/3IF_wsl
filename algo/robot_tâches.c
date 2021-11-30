#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j;
    int N;
    int nbTaches;
    int duree, type;
    int nbA = 0;
    int nbB = 0;
    int res = 0;

    fscanf(stdin,"%d",&N);
    fscanf(stdin,"%d",&nbTaches);
    
    int tabTaches[nbTaches];
    j = nbTaches-1;
    int ibis = 0;
    for(i = 0; i < nbTaches; i++)
    {
        fscanf(stdin,"%d %d",&type, &duree);
        if(type == 2)
        {
            tabTaches[ibis] = duree;
            ibis++;
            nbB++;
        }else if(type == 1)
        {
            tabTaches[j] = duree;
            nbA++;
            j--;
        }
    }
    
    //Initialisation
    int L[nbTaches+1][N+1];
    for(j = 1; j < N+1; j++)
    {
        L[0][j] = 0;
    }

    for(i = 0; i < nbTaches+1; i++)
    {
        L[i][0] = 1;
    }

    //Multidimensionnel
    for(i = 1; i < nbB+1; i++)
    {
        for(j = 1; j < N+1; j++)
        {
            if((L[i-1][j] == 1) || ((j - tabTaches[i-1]) >= 0 && L[i-1][j-tabTaches[i-1]] == 1))
            {
                L[i][j] = 2;
            }else 
            {
                L[i][j] = 0;
            }
        }
    }
    
    if(L[nbB][N] == 1)
    {
        printf("%d\r\n", res);
        return 0;
    }

    for(i = nbB+1; i < nbTaches+1; i++)
    {
        for(j = 1; j < N+1; j++)
        {
            if((L[i-1][j] == 1) || ((j - tabTaches[i-1]) >= 0 && (L[i-1][j-tabTaches[i-1]] == 1 || L[i-1][j-tabTaches[i-1]] == 2)))
            {
                L[i][j] = 1;
            }else 
            {
                L[i][j] = 0;
            }
        }
    }

    if(L[nbTaches][N] == 1)
    {
        res++;
        i = nbTaches;
        j = N;
        while(i != 0)
        {
            if(L[i-1][j] == 0 && ((j - tabTaches[i-1]) >= 0 && L[i-1][j-tabTaches[i-1]] == 1))
            {
                res++;
                j = j-tabTaches[i-1];
                i--;
            }else if(L[i-1][j] == 1 || L[i-1][j] == 2)
            {
                i--;
                break;
            }else if((j - tabTaches[i-1]) >= 0 && L[i-1][j-tabTaches[i-1]] == 2)
            {
                printf("%d\r\n", res);
                return 0;
            }
        }
        printf("%d\r\n", res);
        return 0;
    }else {
        res = -1;
        printf("%d\r\n", res);
    }
    
    return 0;
}