/*
Problème : la conjecture de Collatz
La conjecture de Collatz est un problème mathématique avec un énoncé très

simple, mais sans solution connue. Soit la fonction f dénie de la manière sui-
vante :

f(n) = 
n/2 si n ≡ 0 (mod 2)
3 ∗ n + 1 si n ≡ 1 (mod 2)

et la série :

ai(n) = 
n si i = 0
f(ai−1(n)) si i > 0

La conjecture nous dit que dans la succession a0(n), a1(n), a2(n), . . . nous allons
arriver sur un terme avec la valeur 1, peu importe la valeur initiale de n (entier
strictement positif). Le nombre de termes avant le premier 1 est nommé la
longueur de cycle pour n. Proposez un algorithme qui ache les termes de la
série ai(n) avant le premier 1.
Description de l'entrée (IN) : un nombre entier, inférieur à 1000. Description

de la sortie (OUT) : les nombres entiers formant la série, un par ligne. Obser-
vation : chaque ligne achée sera terminée par deux caractères (CR et LF),
correspondant à la chaine "\r\n".
*/

#include <stdio.h>

int main()
{
    int a;
    scanf("%d",&a);
    while(a!=1)
    {
        printf("%d\r\n",a);
        if(a%2 == 0)
        {
            a = a/2;
        }else if(a%2 == 1)
        {
            a = 3*a+1;
        }
    }
    printf("%d\r\n",a);
    return 0;
}