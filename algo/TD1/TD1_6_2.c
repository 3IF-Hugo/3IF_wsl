int main(){
        int n=0;
        int i;
        scanf("%d", &n);
        int tab[n];
        for(i=0; i<n; i++){
                scanf("%d", &tab[i]);
        }

        int somme = 0;
        int max=0;
        for(i=0; i<n; i++){
                if(tab[i]>=tab[i]+somme){
                        somme = tab[i];
                }else{
                        somme = tab[i]+somme;
                }
                if(somme>max){
                        max = somme;
                }
        }
        printf("%d\r\n",max);
return(0);
}