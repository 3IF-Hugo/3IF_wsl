/*
Pour deux entiers A et B, avec 1 ≤ A, B ≤ 50000 énumérer tous les entiers x, y
respectant les contraintes suivantes :
x*x + y*y = A et 
x*x*x + y*y*y = B
*/

#include <stdio.h>

int main(){
        int a,b,i,j;
        int boo=0;
        scanf("%d", &a);
        scanf("%d", &b);
        for(i=0; i<a; i++){
                for(j=0; j<b; j++){
                        if((i*i + j*j == a) && (i*i*i + j*j*j == b)){
                                printf("%d %d\r\n", i, j);
                                boo=1;
                        }
                }
        }
        if(boo==0){
                printf("-\r\n");
        }
        return 0;
}