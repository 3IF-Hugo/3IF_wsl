#include <stdio.h>

int main()
{
    int sum = 0;
    int moy = 0;
    int cpt = 0;
    int nbEntier;
    int i;
    fscanf(stdin,"%d",&nbEntier);

    int elem[nbEntier];
    for(i = 0; i<nbEntier; i++)
    {
        fscanf(stdin,"%d",&elem[i]);
    }

    for(i = 0; i<nbEntier; i++)
    {
        sum += elem[i];
    }

    moy = sum/nbEntier;

    for(i = 0; i<nbEntier; i++)
    {
        if(elem[i] > moy)
        {
            cpt++;
        }
    }

    printf("%d\r\n", cpt);

    return 0;
}