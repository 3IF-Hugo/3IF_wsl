#include <stdio.h>
#include <stdlib.h>

void permut(int vus[], int nbVus, int nonVus[], int nbNonVus){
    /*
    Entree :
     - vus[0..nbVus-1] = sommets visites
     - nonVus[0..nbNonVus-1] = sommets non visites
    Precondition : nbVus > 0 et vus[0] = 0 (le tour commence toujours par le sommet 0)
    Postcondition : affiche tous les tours commencant par vus[0..nbVus-1] et se terminant par les sommets de nonVus[0..nbNonVus-1] (dans tous les ordres possibles)
     */
    // ECRIVEZ VOTRE CODE ICI :-)
    //Si nonVus est vide, on affiche vus
    if (nbNonVus == 0){
        for (int i=0; i<nbVus; i++) printf("%d ",vus[i]);
        printf("\n");
    }else{
        for(int i=0; i<nbNonVus; i++){
                //Enlever i de nonVus
            int tmp = nonVus[i];
            nonVus[i] = nonVus[nbNonVus-1];
                //Ajouter i à la fin de vus
            vus[nbVus] = tmp;
            //nbVus++;
                //On appelle permut sur vus et nonVus
            permut(vus,nbVus+1,nonVus,nbNonVus-1);
                //On enleve i de vus, inutile car on le fait dans le permut
            //nbVus
                //On remet i dans nonVus
            nonVus[nbNonVus-1] = nonVus[i];
            nonVus[i] = tmp;
        }
    }

}

int main(){
    int nbSommets, i;
    scanf("%d",&nbSommets);
    int vus[nbSommets], nonVus[nbSommets-1];
    vus[0] = 0;
    for (i=0; i<nbSommets-1; i++)
        nonVus[i] = i+1;
    permut(vus,1,nonVus,nbSommets-1);
}
