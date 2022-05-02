#include "sa.h"
#include <time.h>
#include <math.h>

static int N;            /* N villes                       */
static int *X;           /* X[i] est la coordonnée X de la ville i           */
static int *Y;           /* Y[i] est la coordonnée X de la ville i           */
static int *ordre;       /* ordre[i] est l'ordre de passage des villes */
static int MVI;
static int MVJ;
static int *best_ordre;

int /* Sum of distance in ordre */
cost() {
    int d = 0;
    for (int i=0;i<N-1;i++) {
        // d += sqrt((X[ordre[i]]-X[ordre[i+1]])*(X[ordre[i]]-X[ordre[i+1]]) +
        //          (Y[ordre[i]]-Y[ordre[i+1]])*(Y[ordre[i]]-Y[ordre[i+1]]));
        d += hypot(X[ordre[i]]-X[ordre[i-1]], Y[ordre[i]]-Y[ordre[i-1]]);
    }
    //Rajouter la distance entre la dernière ville et la première
    d += sqrt((X[ordre[N-1]]-X[ordre[0]])*(X[ordre[N-1]]-X[ordre[0]]) +  (Y[ordre[N-1]]-Y[ordre[0]])*(Y[ordre[N-1]]-Y[ordre[0]]));
    return d;
}

void
printConfig() {
    for (int i=0;i<N;i++) printf("%i ", ordre[i]);
    printf("\n");
}

int //scan input file and put data in global variables
scanConfig() {
    if (!scanConfigTitle()) return 0;
    if (scanf("%i", &N) != 1) {
        fprintf(stderr, "error scan number of tiles\n");
        exit(1);
    }
    free(X); X = (int *)malloc(N*sizeof(int));
    free(Y); Y = (int *)malloc(N*sizeof(int));
    free(ordre); ordre = (int *)malloc(N*sizeof(int));
    free(best_ordre); best_ordre = malloc(N*sizeof(int));
    //Il faut faire les malloc avant les scanf vu qu'on les mets dans les cases du tableau
    for (int i=0;i<N;i++) {
        if (scanf("%i %i", &X[i], &Y[i]) != 2) {
            fprintf(stderr, "error scan X and Y\n");
            exit(1);
        }
    }
    allocTempsAndCosts();
    return 1;
}

void /* swap X and Y of i and j */
doMove(int i, int j) {
    int t = X[i];
    X[i] = X[j];
    X[j] = t;
    t = Y[i];
    Y[i] = Y[j];
    Y[j] = t;
}
void
rndMove(){
  MVI = MVJ = rand() % N; //C'est pour etre sur qu'au debut ils sont egaux
  while (MVI == MVJ) MVJ = rand() % N;
  doMove(MVI, MVJ);
}

void undoMove() { doMove(MVI,MVJ); }

void saveNewBest() /*Copy new best in a new memory zone  */{
    for (int i=0;i<N;i++) best_ordre[i] = ordre[i];
} 

int
main() {
  srand(time(0)); scanParam(); initPlot();
  scanConfig();
  heat(); sa(); plot(); printConfig();
  exit(0);
}
