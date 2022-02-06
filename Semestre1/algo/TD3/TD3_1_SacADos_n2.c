#include <stdio.h>

int main(){
        int tailleSac;
        scanf("%d", &tailleSac);
        int tObjets[100];
        int nObjets=0;

        do{
                scanf("%d", &tObjets[nObjets]);
                nObjets++;
        }while(tObjets[nObjets-1] != -1);

        nObjets--;
        int tRes[nObjets+1][tailleSac+1];
        int i,j;

        for(i=0; i<nObjets+1; i++)
                tRes[i][0] = 1;

        for(j=1; j<tailleSac+1; j++)
                tRes[0][j] = 0;

        for(i=1; i<nObjets+1; i++)
        {
                for(j=1; j<tailleSac+1; j++)
                {
                        if((j-tObjets[i-1] >= 0 && tRes[i-1][j-tObjets[i-1]] == 1) || tRes[i-1][j] == 1)
                        {
                                tRes[i][j] = 1;
                        }else
                                tRes[i][j] = 0;
                }
        }

        if(tRes[nObjets][tailleSac] == 1)
                printf("OUI\r\n");
        else
                printf("NON\r\n");
        return 0;
}