/*
Problème : Sac à dos - 1
Pour un ensemble d'objets de poids connus (entiers) et pour un sac à dos avec
une capacité connue (nombre entier), trouvez si c'est possible de remplir exactement le sac avec des objets existants.
*/

#include <stdio.h>

int main(){
        int tailleSac;
        int tObjets[100];
        int nObjets=0;
        scanf("%d", &tailleSac);
        do{
                scanf("%d", &tObjets[nObjets]);
                nObjets++;
        }while(tObjets[nObjets-1] != -1);
        nObjets -= 1;
        int tRes[tailleSac+1];
        tRes[0] = 1;
        int i,j;
        for(i=1; i<tailleSac+1; i++){
                for(j=0; j<nObjets; j++){
                        if(i-tObjets[j]>=0 && tRes[i-tObjets[j]]==1){
                                tRes[i]=1;
                                break;
                        }else
                                tRes[i]=0;
                }
        }
        if(tRes[tailleSac]==1)
                printf("OUI\r\n");
        else
                printf("NON\r\n");
        return 0;
}