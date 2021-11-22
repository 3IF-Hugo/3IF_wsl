#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void affichageEtoile(int n) {
int i;
for(i=0;i<n;i++){
printf("*");
}
printf("\n");
}


void affichageEspace(int n){
int i;
for(i=0;i<n;i++){
printf(" ");
}
}

void affichageBarre(int n){
int i;
for(i=0;i<n;i++){
printf("|");
}
printf("\n");
}

int main() {
    int coneH;
    int troncH;
    int troncL;
    int etage;
    int place;
    int i=0;
    int espace;
    int t=0;
    int j=0;

    srand((unsigned) time(NULL));
    coneH = rand()%50+1;
    troncH = rand()%10+1;
    troncL = rand()%10+1;
    etage = rand()%coneH;
    place = rand()%coneH*2-1;

    for(i=0; i < coneH ; i++){
            for(j=0 ; j < coneH-i ; j++){
                printf(" ");
            }
            for(j=0; j < 2*i+1 ; j++){
                if(i== etage-1 && j == place-1){
                    printf("0");
                }
                else
                    printf("*");
            }
            printf("\n");
        }

    for(i=0 ; i < troncH ; i++){
            for(j=0; j < coneH-troncL/2 ; j++){
                printf(" ");
            }
            for(j=0 ; j < troncL ; j++){
                printf("|");
            }
            printf("\n");
        }

    return 0;
}
