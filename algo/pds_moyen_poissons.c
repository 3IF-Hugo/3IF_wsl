#define _CRT_SECURE_NO_WARNINGS //pour Visual Studio
#include <stdio.h>

int main()
{
    int nbRouges;
    int sumRouges = 0;
    int moyRouges = 0;
    
    int nbBleus;
    int sumBleus = 0;
    int moyBleus = 0;

    fscanf(stdin,"%d",&nbRouges);
    fscanf(stdin,"%d",&nbBleus);

    int pdsRouges[nbRouges];
    int pdsBleus[nbBleus];

    for(int i = 0; i<nbRouges; i++)
    {
        fscanf(stdin,"%d",&pdsRouges[i]);
    }

    for(int i = 0; i<nbBleus; i++)
    {
        fscanf(stdin,"%d",&pdsBleus[i]);
    }

    for(int i = 0; i<nbRouges; i++)
    {
        sumRouges += pdsRouges[i];
    }
    moyRouges = sumRouges/nbRouges;

    for(int i = 0; i<nbBleus; i++)
    {
        sumBleus += pdsBleus[i];
    }
    moyBleus = sumBleus/nbBleus;

    if(moyRouges > moyBleus)
    {
        printf("R\r\n");
    }

    if(moyRouges < moyBleus)
    {
        printf("N\r\n");
    }

    if(moyRouges == moyBleus)
    {
        printf("RN\r\n");
    }

    return 0;
}