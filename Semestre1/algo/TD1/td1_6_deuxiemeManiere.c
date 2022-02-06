#include <stdio.h>
   
int main() {
    int n;
	scanf("%d", &n);
    printf("ceci est n : %d\n", n);
	int tab[n];
    int i,j,max,current = 0;
	for(i=0; i<n; i++)
    {
        scanf("%d", &tab[i]);
    }
    
        for(j=0;j<n;j++)
        {
            if(tab[j]>0 && j==0)
            {
                current = tab[j];
            } else if(current+tab[j] > 0)
            {
                current = current + tab[j];
            } else {
                current = 0;
            }
 
            if(current>max){
                max=current;
            }
        }
 
        printf("%d\r\n", max);
 
        return 0;
}