/*
Implémentez dans le langage C un algorithme qui calcule la factorielle d'un
nombre n.

Description de l'entrée (IN) : un nombre entier, inférieur ou égale à 12. Descrip-
tion de la sortie (OUT) : un nombre entier. Observation : chaque ligne achée
sera terminée par deux caractères (CR et LF), correspondant à la chaine "\r\n".
*/

#include <stdio.h>

int fact(int n)
{
    if (n <= 1)
    {
        return 1;
    }else{
        return n*fact(n-1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("La factorielle est : %d\r\n",fact(n));
    return 0;
}