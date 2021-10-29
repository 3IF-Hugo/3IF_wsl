/*
Problème 3 : sous-séquence contigüe de somme maximale
-----------------------------------------------------

Pour une séquence de n nombres réels (0 < n <= 5000), nous vous demandons de trouver
la somme maximale d'une sous-séquence contigüe. 
Exemple 1 : pour la séquence 1 -2 10 -14 2 5 7 -1 le résultat 
est 14 (correspondant à la sous-séquence 2 5 7).

Exemple 2 : pour la séquence 1 -2 10 -2 2 5 7 -1 le résultat 
est 22 (correspondant à la sous-séquence 10 -2 2 5 7).

Observation : pour ce problème vous pouvez obtenir une erreur de type TIMELIMIT,
correspondant à une durée d'exécution trop importante de votre algorithme !

Format d'entrée
---------------

L'entrée standard sera composée d'une série de nombres :
- un nombre entier indiquant le nombre de valeurs à analyser noté n
- n nombres réels correspondants aux valeurs à analyser

Le format en entrée est respecté, vous n'avez pas à faire de test pour le vérifier.

Format de sortie
----------------

Un nombre réel correspondant à la valeur recherchée.


Exemple
-------

Entrée :
8
1
-2
10
-14
2
5
7
-1

Sortie :
14*/
#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int T[n];
	int i;
	for(i=0; i<n; i++)
		scanf("%d", &T[i]);

	// séquence positive la plus longue

	int max = 0;
	int maxtab = 0;
	int ind_base = 0;
	int j;

	for(j = 0; j < n; j++) {
		if(T[j] > 0)
			max++;
		else {
			if (maxtab < max) {
				maxtab = max;
				ind_base = j - 1;
			}
			max = 0;
		}
	}

	// max somme sous-séquence contifuë
	
	int sum = 0;
	int k;
	for(k=ind_base-maxtab+1; k<=ind_base; k++) {
		sum += T[k];
	}

	int sumTest = sum;
	int maxSum = sum;
	for(k=ind_base-maxtab; k>=0; k--){
		sumTest += T[k];
		if(sumTest > maxSum)
			maxSum = sumTest;
	}
	sumTest = sum;
	for(k=ind_base+1; k<n; k++){
		sumTest += T[k];
		if(sumTest > maxSum)
			maxSum = sumTest;
	}
	printf("%d\r\n", maxSum);
	return 0;
}