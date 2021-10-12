/*
Problème : Intervalles
Proposez un algorithme pour calculer l'aire de l'intersection de deux intervalles
[a1; b1] et [a2; b2].
Description de l'entrée (IN) : sur la première ligne la valeur a1 (réel), sur la
deuxième ligne la valeur b1 (réel), la troisième ligne la valeur a2 (réel) et sur la
quatrième ligne la valeur b2 (réel).
Description de la sortie (OUT) : l'aire de l'intersection comme nombre réel.
Observation : chaque ligne achée sera terminée par deux caractères (CR et
LF), correspondant à la chaine "\r\n".
*/

#include <stdio.h>

int main()
{
    //Déclaration des variables
    int a1;
    int b1;
    int a2;
    int b2;
    int aire;
    //on demande les intervalles
    scanf("%d", &a1);
    scanf("%d", &b1);
    scanf("%d", &a2);
    scanf("%d", &b2);
    
    if(b1 < a2 || b2<a1)
    {
        printf("0");
        return 0;
    }
    
    if(a1<a2)
    {
        aire = b1 - a2;
    }
    
    if(a2<a1)
    {
        aire = b2 - a1;
    }
    
    printf("L'aire est : %d\r\n",aire);
    return 0;
}
