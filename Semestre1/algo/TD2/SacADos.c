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

    for(int i=0; i<nbObjet; i++)
    {
        printf("%d\n", tabObjet[i]);
    }
    
    // for(i=0; i<capacite; i++){
    //     scanf("%d", &tabObjet[i]);
    // }

    int L[capacite+1];
    L[0] = 1;
    for(int i = 1;i<=capacite+1; i++)
    {
        L[i] = 0;
    }

    for(i = 1; i<=capacite; i++)
    {
        for(j = 0; j < nbObjet; j++)
        {
            if((i - tabObjet[j]) >= 0 && L[i-tabObjet[j]] == 1)
            {
                L[i] = 1;
            }
        }
    }

    if(L[capacite] == 1)
    {
        printf("OUI\r\n");
    }else {
        printf("NON\r\n");
    }

}
