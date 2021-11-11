/*
Problème 3 : robot (6 points)
--------------------------------------------------------
Un robot dois se trouve dans la case (0, 0) correspondant au coin haut-gauche d’une grille carrée de taille NxN. Le robot peut se déplacer vers la droite ou en bas de la grille, dans une case voisine à la case où il se trouve. Quelques cases de la grille peuvent contenir également un obstacle, et dans ce cas le robot ne peut pas se déplacer sur cette case. L’objectif du robot est d’arriver dans la case (N-1, N-1) correspondant au coin bas-droite de la grille. Quel est le nombre de chemins distincts possibles que le robot peut emprunter pour y arriver ?

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

int main(){
    
    int n;
    int nbChemin=0;
	scanf("%d", &n);
	int arrGrid[100][100];
	char temp;
    int cellVisit[100][100];

	for (int nPosI = 0; nPosI < n; nPosI++) {
		for (int nPosJ = 0; nPosJ < n; nPosJ++) {
			scanf("%d%c", &arrGrid[nPosI][nPosJ], &temp);
		}
	}

    for (int nPosI = 0; nPosI < n; nPosI++) 
    {
		for (int nPosJ = 0; nPosJ < n; nPosJ++) 
        {
            printf("%d ", arrGrid[nPosI][nPosJ]);
        }
        printf("\n");
    }

    int nPosI=0;
    int nPosJ=1;
    while (nPosI != n-1 && nPosJ != n-1 && nPosJ<n && nPosI<n)
    {
        if(arrGrid[nPosI][nPosJ] == 0 && cellVisit[nPosI][nPosJ]!=1)
        {
            if(nPosJ>=n)
            {
                printf("j'augmente les lignes, je vais vers le bas\n");
                nPosI++;
            }else{
                printf("j'augmente les colonnes, je me déplace vers la droite\n");
                nPosJ++;
            }
            cellVisit[nPosI][nPosJ]=1;
        }else if(arrGrid[nPosI][nPosJ] ==-1)
        {
            cellVisit[nPosI][nPosJ]=1;
            continue;
        }
    }
    for (int nPosI = 0; nPosI < n; nPosI++) 
    {
		for (int nPosJ = 0; nPosJ < n; nPosJ++) 
        {
            printf("%d ", cellVisit[nPosI][nPosJ]);
        }
        printf("\n");
    }
}