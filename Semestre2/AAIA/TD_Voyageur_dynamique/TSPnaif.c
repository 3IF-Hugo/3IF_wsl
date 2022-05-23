#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>

int cpt = 0;

int** memD;

typedef int ensemble; // representation d'un ensemble d'elements compris entre 1 et 32 par un vecteur de bits

bool estElementDe(int e, ensemble s){
    // Precondition : 1 <= e <= 32
    // Postrelation : retourne true si e appartient à l'ensemble s
    return ((s & (1 << (e-1))) != 0);
}

bool estVide(ensemble s){
    // Postrelation : retourne true si s est vide
    return (s == 0);
}

ensemble ajouteElement(ensemble s, int e){
    // Precondition : 1 <= e <= 32
    // Postrelation : retourne l'ensemble s U {e}
    return (s | (1 << (e-1)));
}

ensemble enleveElement(ensemble s, int e){
    // Precondition : 1 <= e <= 32
    // Postrelation : retourne l'ensemble s \ {e}
    return (s ^ (1 << (e-1)));
}

ensemble creeEnsemble(int n){
    // Precondition : 1<= n <= 32
    // Postrelation : retourne l'ensemble contenant tous les entiers compris entre 1 et n-1
    return (1 << (n - 1)) - 1;
}

void afficheEnsemble(ensemble s){
    // Postcondition : affiche sur stdout l'ensemble des elements de s
    int i = 1;
    while (s != 0){
        if (s%2 != 0) printf(" %d",i);
        s /= 2;
        i++;
    }
}

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
            }
        }
    }
    return cout;
}

// int calculeD(int i, ensemble s, int n, int** cout){
//     // Preconditions : estElementDe(i,s) = false et estElement(0,s) = false
//     // Postrelation : retourne le cout du plus court chemin partant du sommet i, passant par chaque sommet de s exactement une fois, et terminant sur 0
//     cpt++;
//     if (estVide(s)) return cout[i][0];
//     int min = INT_MAX;
//     for (int j=1; j<n; j++){
//         if (estElementDe(j,s)){
//             int d = calculeD(j, enleveElement(s,j), n, cout);// on enleve j de s et on calcule le cout du plus court chemin partant de j, passant par chaque sommet de s exactement une fois, et terminant sur 0
//             if (cout[i][j] + d < min) min = cout[i][j] + d;
//          }
//     }
//     return min;
// }

int calculeD(int i, ensemble s, int n, int** cout){
    // Preconditions : estElementDe(i,s) = false et estElement(0,s) = false
    // Postrelation : retourne le cout du plus court chemin partant du sommet i, passant par chaque sommet de s exactement une fois, et terminant sur 0
    cpt++;
    if (estVide(s)) return cout[i][0];
    if(memD[i][s] != 0) return memD[i][s];
    int min = INT_MAX;
    for (int j=1; j<n; j++){
        if (estElementDe(j,s)){
            int d = calculeD(j, enleveElement(s,j), n, cout);// on enleve j de s et on calcule le cout du plus court chemin partant de j, passant par chaque sommet de s exactement une fois, et terminant sur 0
            memD[j][enleveElement(s,j)] = d;
            if (cout[i][j] + d < min) min = cout[i][j] + d;
        }
    }
    return min;
}

int main(){
    int n;
    printf("Nombre de sommets : ");
    fflush(stdout);
    scanf("%d",&n);
    if ((n > 32) || (n < 1)){
        printf("Le nombre de sommets doit être compris entre 1 et 32\n");
        return 0;
    }
    
    int** cout = creeCout(n);
    ensemble s = creeEnsemble(n); // s contient tous les entiers compris entre 1 et n-1

    memD = (int**) malloc(n*sizeof(int*));
    for (int i=0; i<n; i++){
        memD[i] = (int*) calloc(s, sizeof(int));
        for (int j=0; j<n; j++){
            memD[i][j] = 0;
        }
    }

    clock_t tpsDebut = clock();
    int d = calculeD(0, s, n, cout);
    float duree = ((double) (clock() - tpsDebut)) / CLOCKS_PER_SEC;
    printf("Longueur du plus court circuit hamiltonien = %d ; temps de calcul = %.3fs\n", d, duree);
    printf("Nombre d'appels de la fonction calculeD : %d\n", cpt);
    return 0;
}
