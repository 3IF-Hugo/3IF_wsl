/*
Problème : palindromes
Soit un ensemble de nombres naturelles positives X = {x1, x2, . . . , xn}. Proposez
un algorithme qui pour l'entrée X produit la valeur 1, si X est un palindrome,
et la sortie 0 en cas contraire. X est un palindrome s'il peut se lire dans les deux
sens avec la même valeur.
Description de l'entrée (IN) : les nombres formant le vecteur X, un par ligne.
La taille du vecteur X est limitée à 1000 éléments. Le tableau X en entrée est
ni avec la valeur −1, qui ne fait pas partie du tableau. Description de la sortie
(OUT) : 0 ou 1. Observation : chaque ligne achée sera terminée par deux
caractères (CR et LF), correspondant à la chaine "\r\n".
*/

#include <stdio.h>

int main()
{
    //Déclaration des variables
    int X [1000];
    int i;
    int val=0;
    int n;

    while(n != -1)
    {
        scanf("%d", &n);
        X [i] = n;
        i += 1;
    }
    
    for(int j = 0; j<i; j++)
    {
        if(X[j] == X[i-j])
        {
            val = 1;
        }
    }
    
    printf("X est-il palindrome ? %d", val);
    return 0;
}