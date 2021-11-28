#include <stdio.h>

int main(){

    int capacite = 0;
    scanf("%d", &capacite);

    int nbObjet = 0;
    int j = 0;
    int i = 0;
    int tabObjet[100];
    int pds = 0;

    do
    {
        scanf("%d", &pds);
        tabObjet[nbObjet] = pds;
        nbObjet++;
    }while(pds != -1);

    // for(int i=0; i<nbObjet; i++)
    // {
    //     printf("%d\n", tabObjet[i]);
    // }
    
    // for(i=0; i<capacite; i++){
    //     scanf("%d", &tabObjet[i]);
    // }

    int L[nbObjet][capacite+1];

    for(int i = 0; i < capacite+1; i++)
    {
        L[0][i] = 0;
    }
    for(int i = 1; i < nbObjet; i++)
    {
        L[i][0] = 1;
    }

    // for(i = 1; i < nbObjet; i++ )
    // {
    //     for(j = 0; j < capacite+1; j++)
    //     {
    //         printf("%d ", L[i][j]);
    //     }
    //     printf("\n");
    // }

    for(i = 1; i < nbObjet; i++)
    {
        for(j = 1; j < capacite+1; j++)
        {
            if((L[i-1][j] == 1) || (j - tabObjet[i]) >= 0 && L[i-1][j-tabObjet[i]] == 1)
            {
                    L[i][j] = 1;
            }
        
        }
    }

    for(i = 1; i < nbObjet; i++ )
    {
        for(j = 0; j < capacite+1; j++)
        {
            printf("%d ", L[i][j]);
        }
        printf("\n");
    }

    if(L[nbObjet-1][capacite] == 1)
    {
        printf("OUI\r\n");
    }else {
        printf("NON\r\n");
    }

}
