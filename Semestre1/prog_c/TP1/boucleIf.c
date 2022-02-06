#include <stdio.h>

int main() {
    
    int val = 1000;

    if(val == 1000){
        printf("vous êtes dans le mille");
    }
    if(val <1000){
        printf("valeur trop petite");
    }
    if(val>1000 && val< 10000){
        printf("valeur trop grande");
    }
    if(val>10000){
        printf("valeur beaucoup trop grande");
    }
    return 0;
}
