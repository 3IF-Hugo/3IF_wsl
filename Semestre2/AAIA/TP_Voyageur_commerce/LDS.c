#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <string.h>

int** cout;
int dmin = INT_MAX;
int dmax;
//Ajoutez une variable globale pcc, et modifiez la procédure permut afin qu’elle maintienne dans pcc la longueur du plus court circuit hamiltonien : pcc est initialisée à infinie
int pcc = INT_MAX;
int pos = 0;
int dmax = 20;

int nextRand(int iseed){
    // Postcondition : retourne le prochain entier selon une suite pseudo-aleatoire avec la graine iseed
    int i = 16807 * (iseed % 127773) - 2836 * (iseed / 127773);
    if (i > 0) iseed = i;
    else iseed = 2147483647 + i;
    return iseed;
}

int** creeCout(int n){
    // retourne une matrice cout telle que pour tout i,j appartenant à [0,n-1], cout[i][j] = cout de l'arc (i,j)
    int** cout;
    int coutMax = 1000;
    int iseed = 1;
    cout = (int**) malloc(n*sizeof(int*));
    for (int i=0; i<n; i++){
        cout[i] = (int*) malloc(n*sizeof(int));
        for (int j=0; j<n; j++){
            if (i == j) cout[i][j] = coutMax+1;
            else {
                iseed = nextRand(iseed);
                cout[i][j] = 1 + iseed % coutMax;
                if(cout[i][j] < dmin) dmin = cout[i][j];
            }
        }
    }
    return cout;
}

int bound(int i,int nonVus[],int nbNonVus){
        //bound niveau 1
    // int min = INT_MAX;
    // min = dmin*(nbNonVus+1);

        //bound niveau 2
    //int li[nbNonVus];
    int minboucle = INT_MAX;
    int minFinal = 0;
    int l = INT_MAX;
    for(int j=0;j<nbNonVus;j++){
        if(cout[i][nonVus[j]] < l){
            l = cout[i][nonVus[j]];
        }
        minboucle = cout[nonVus[j]][0];
        for(int k=0;k<nbNonVus;k++){
            if(k != j && cout[nonVus[j]][nonVus[k]] < minboucle){
                minboucle = cout[nonVus[j]][nonVus[k]];
            }
        }
        minFinal += minboucle;
    }
    minFinal += l;
    return minFinal;
}
int costComparator ( const void * first, const void * second) {
    int firstInt = * (const int *) first;
    int secondInt = * (const int *) second;
    firstInt = cout[pos][firstInt];
    secondInt = cout[pos][secondInt];
    return firstInt - secondInt;
}


void LDS(int vus[], int nbVus, int nonVus[], int nbNonVus, int longueur, int d){
    /*
     Variable globale :
     - pour tout couple de sommets (i,j), cout[i][j] = cout pour aller de i vers j
     Entree :
     - nonVus[0..nbNonVus-1] = sommets non visites
     - vus[0..nbVus-1] = sommets visites
     Precondition :
     - nbVus > 0 et Vus[0] = 0 (on commence toujours par le sommet 0)
     - longueur = somme des couts des arcs du chemin <vus[0], vus[1], ..., vus[nbVus-1]>
     Postcondition : affiche les longueurs de tous les circuits commençant par vus[0..nbVus-1] et se terminant par les sommets de nonVus[0..nbNonVus-1] (dans tous les ordres possibles), suivis de 0
     */
    // ECRIVEZ VOTRE CODE ICI :-)

    if (nbNonVus == 0){
        int p = longueur + cout[vus[nbVus-1]][0];
        printf("%d ", pcc);
        if (p < pcc) {
            pcc = p;
        }
        //printf("%d\n", longueur + cout[vus[nbVus-1]][0]);
        return;
    }else{
        if((longueur + bound(vus[nbVus-1], nonVus,nbNonVus)) <= pcc && d<dmax){
            int tab[nbNonVus];
            memcpy(tab, nonVus, sizeof(int)*nbNonVus);
            pos = vus[nbVus-1];
            qsort( tab, nbNonVus, sizeof(int), costComparator );
            for (int i=0; i<nbNonVus; i++){
                //int tmp = nonVus[i];
                //pos = tmp;
                //nonVus[i] = nonVus[nbNonVus-1];
                //vus[nbVus] = tmp;
                ////int newlongueur = longueur + cout[vus[nbVus-1]][vus[nbVus]];
                //permut(vus, nbVus+1, nonVus, nbNonVus-1, longueur + cout[vus[nbVus-1]][vus[nbVus]]);
                ////permut(vus, nbVus+1, nonVus, nbNonVus-1, longueur + cout[vus[nbVus-1]][vus[nbVus]]);
                //nonVus[nbNonVus-1] = nonVus[i];
                //nonVus[i] = tmp;


                int tmp = tab[i];
                
                tab[i] = tab[nbNonVus-1];
                vus[nbVus] = tmp;
                
                LDS(vus, nbVus+1, tab, nbNonVus-1, longueur + cout[vus[nbVus-1]][vus[nbVus]], d+i);
                tab[nbNonVus-1] = tab[i];
                tab[i] = tmp;
            }
        }
    }
}

int main(){
    int nbSommets;
    scanf("%d",&nbSommets);
    cout = creeCout(nbSommets);
    int vus[nbSommets];
    int nonVus[nbSommets-1];
    for (int i=0; i<nbSommets-1; i++) nonVus[i] = i+1;
    vus[0] = 0;

    clock_t tpsDebut = clock();
    LDS(vus,1,nonVus,nbSommets-1,0, 0);
    float duree = ((double) (clock() - tpsDebut)) / CLOCKS_PER_SEC;
    printf("Longueur du plus court circuit hamiltonien = %d ; temps de calcul = %.3fs\n", pcc, duree);
}
