/*
Problème 3 : robot (6 points)
--------------------------------------------------------
Un robot dois se trouve dans la case (0, 0) correspondant au coin haut-gauche d’une grille carrée de taille NxN. 
Le robot peut se déplacer vers la droite ou en bas de la grille, dans une case voisine à la case où il se trouve. 
Quelques cases de la grille peuvent contenir également un obstacle, et dans ce cas le robot ne peut pas se déplacer sur cette case. 
L’objectif du robot est d’arriver dans la case (N-1, N-1) correspondant au coin bas-droite de la grille. 
Quel est le nombre de chemins distincts possibles que le robot peut emprunter pour y arriver ?

Format en entrée
----------------

L'entrée standard sera composée de :
- le nombre N (entier, 1 <= N <= 100) ;
- la matrice représentant la grille, avec les nombres décrivant chaque case séparés par un espace ; une case peut avoir la valeur 0 (passage possible) ou -1 (obstacle) ; chaque ligne de la matrice se trouve sur une ligne en entrée ; les cases (0, 0) et (N-1, N-1) ne peuvent pas contenir d’obstacle.

Le format en entrée est respecté, vous n'avez pas à faire de test pour le vérifier. 

Format en sortie
----------------
La sortie : le nombre de chemins distincts possibles.
La ligne de sortie sera finalisée par un retour à la ligne de type "\r\n".
*/
#define _CRT_SECURE_NO_WARNINGS //pour Visual Studio
#include <stdio.h>
#define MaxN 100

int nbChemin(int arrGrid[MaxN][MaxN], int size)
{
    arrGrid[0][0] = 1;
    int i,j;
    for(i = 1; i <size; i++)
    {
        if(arrGrid[0][i] != -1)
        {
            arrGrid[0][i] = 1;
        }
        else
        {
            break;
        }
    }

    for(i = 1; i <size; i++)
    {
        if(arrGrid[i][0] != -1)
        {
            arrGrid[i][0] = 1;
        }
        else
        {
            break;
        }
    }

    for(i = 1; i<size; i++)
    {
        for(j = 1; j<size; j++)
        {
            if(arrGrid[i][j] != -1)
            {
                if(arrGrid[i-1][j] != -1 && arrGrid[i][j-1] != -1)
                {
                    arrGrid[i][j] = arrGrid[i-1][j] + arrGrid[i][j-1];
                }
                else
                {
                    if(arrGrid[i-1][j] > arrGrid[i][j-1])
                    {
                        arrGrid[i][j] = arrGrid[i-1][j];
                    }else
                    {
                        arrGrid[i][j] = arrGrid[i][j-1];
                    }
                }
            }
        }
    }
    // for (int nPosI = 0; nPosI < size; nPosI++) 
    // {
	// 	for (int nPosJ = 0; nPosJ < size; nPosJ++) 
    //     {
    //         printf("%d ", arrGrid[nPosI][nPosJ]);
    //     }
    //     printf("\n");
    // }
    return arrGrid[size-1][size-1];
}

int main(){
    
    int n;
	scanf("%d", &n);
	int arrGrid[100][100];
	char temp;
    int nbchemin = 0;
    int nPosI;
    int nPosJ;

	for (nPosI = 0; nPosI < n; nPosI++) {
		for (nPosJ = 0; nPosJ < n; nPosJ++) {
			scanf("%d%c", &arrGrid[nPosI][nPosJ], &temp);
		}
	}

    // for (int nPosI = 0; nPosI < n; nPosI++) 
    // {
	// 	for (int nPosJ = 0; nPosJ < n; nPosJ++) 
    //     {
    //         printf("%d ", arrGrid[nPosI][nPosJ]);
    //     }
    //     printf("\n");
    // }
    // printf("----");
    // printf("\n");

    nbchemin = nbChemin(arrGrid, n);

    if(nbchemin==-1)
    {
        nbchemin = 0;
    }

    printf("%d\r\n", nbchemin);
    return 0;
}