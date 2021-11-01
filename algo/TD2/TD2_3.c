/*
DS Algorithmique - 3IF - jeudi 9 novembre 2017
Problème 2 : L'alchimie
-----------------------------------

Nous avons à notre disposition un récipient de volume V. Dans ce récipient se trouve 
une substance de volume S. Une expérience est réalisée dans ce récipient, en appliquant 
successivement plusieurs procédés/opérations sur le contenu du récipient. Chaque 
opération a un effet sur le volume de la substance disponible (diminution ou augmentation), 
mais à un aucun moment le volume de la substance ne peux dépasser le volume du récipient. 
Les opérations possibles :
-	Op 1 : la substance arrive à un volume 3*S 
-	Op 2 : la substance arrive à un volume 2*S 
-	Op 3 : la substance arrive à un volume [S/5], où [x] représente le plus grand 
entier inférieur ou égal à x.
Quel est le volume maximal de substance que vous pouvez obtenir dans le récipient, en 
combinant les trois opérations ?
Contraintes : 0 <= S <= V <= 20000

Format en entrée
----------------

L'entrée standard sera composée d'une série de nombres entiers séparés par des retours à 
la ligne :
- le volume V ;
- le volume S ;
Le format en entrée est respecté, vous n'avez pas à faire de test pour le vérifier. 
Les contraintes pour les différentes entrées sont également respectées, pas de vérification à faire.

Format en sortie
----------------
La sortie : Volume maximal atteint (entier).
La ligne de sortie sera finalisée par un retour à la ligne de type "\r\n". 
*/

#include <stdio.h>

int op1(int volS)
{
    return 3*volS;
}

int op2(int volS)
{
    return 2*volS;
}

int op3(int volS)
{
    return (int) volS/5;
}

void testOperations(int resultPassage[], int volS, int volV)
{
    if(op1(volS) <= volV && !resultPassage[op1(volS)])
    {
        resultPassage[op1(volS)]=1;
        testOperations(resultPassage, op1(volS), volV);
    }

    if(op2(volS) <= volV && !resultPassage[op2(volS)])
    {
        resultPassage[op2(volS)]=1;
        testOperations(resultPassage,op2(volS), volV);
    }

    if(op3(volS) <= volV && !resultPassage[op3(volS)])
    {
        resultPassage[op3(volS)]=1;
        testOperations(resultPassage,op3(volS), volV);
    }
}

int main(){
        int volRecipient;
        int volSubstance;
        int maxFinal=0;

        scanf("%d", &volRecipient);
        scanf("%d", &volSubstance);

        int tRes[volRecipient+1];
        int i,j;

        for(i=0;i<=volRecipient;i++)
        {
            if(i == volSubstance)
            {
                tRes[i]=1;
            }else
            {
                tRes[i]=0;
            }
        }

        testOperations(tRes,volSubstance,volRecipient);
        maxFinal = volSubstance;
        for(j=0;j<=volRecipient;j++)
        {
            if(tRes[j]==1)
            {
                maxFinal=j;
            }
        }               

        printf("%d\r\n", maxFinal);

        return 0;
}