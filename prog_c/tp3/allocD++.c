#include <stdio.h>
#include <stdlib.h>
#include "biblio.h"

int main(){
        int filled = 0;
        int tailleMax = 5;
        int *tab = (int*) malloc(sizeof(int)*tailleMax);
        while(1){
                if(filled == tailleMax){
                        tailleMax *= 2;
                        tab = (int*)realloc(tab, sizeof(int)*tailleMax);
                }
                int number;
                int nbtokens = scanf("%d", &number);
                if(nbtokens != 1 || feof(stdin))
                        break;
                tab[filled] = number;
                filled++;
        }
        int minimum = min(tab, filled);
        int maximum = max(tab, filled);
        float moy = moyenne(tab, filled);
        printf("N = %d, Min : %d, Max : %d, Moyenne : %f\n", filled, minimum, maximum, moy);
        free(tab);
        return 0;
}
