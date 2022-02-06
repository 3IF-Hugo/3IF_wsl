#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
        char caract = 'a';
        long offset;
        char *res = (char*)malloc(820*sizeof(char));
        int i, j;
        int cnt = 40;
        for(i=0; i<20; i++){
                for(j=0; j<40; j++){
                        res[j+41*i] = '_';
                }
                res[cnt] = '\n';
                cnt += 41;
        }
        while(caract != 'q'){
                //Affichage
                int i;
                for(i=0; i<820; i++)
                        printf("%c", res[i]);
                printf("\nRentrer le caractère :\n");
                scanf(" %c", &caract);
                if(caract == 'q'){
                        FILE *output;
                        output = fopen(argv[1], "w");
                        for(i=0; i<820; i++)
                                fputc(res[i], output);
                        break;
                }else{
                        printf("Rentrer l'offset :\n");
                        scanf(" %ld", &offset);
                        if(offset <= 820 && res[offset] != '\n'){
                                res[offset] = caract;
                        }else
                                printf("Offset doit être <= 820 et impossible de remplacer un retour chariot.\n");
                }
        }
        return 0;
}