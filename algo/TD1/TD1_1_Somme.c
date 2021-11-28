/*
Problème simple : la somme de trois nombres réels
Soit a, b, c trois nombres réels. Implémentez dans le langage C un algorithme
qui calcule la somme de ces trois nombres.
Description de l'entrée (IN) : les trois nombres, un par ligne. Description de la
sortie (OUT) : un nombre représentant la somme. Observation : chaque ligne
achée sera terminée par deux caractères (CR et LF), correspondant à la chaine
"\r\n".
*/

#include <stdio.h>

int main()
{
    int a;
    int b;
    int c;
    int sum;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
 
    sum = a+b+c;
    printf("La somme est : %d\r\n",sum);

    return 0;
}