#include <stdio.h>
int main() {
    
    int tab[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int i=0;
    int val=1;
    
    for(i=0; i<11;i++){
        val = val *tab[i];
    }

    printf("10! = %d\n", val);
    return 0;
}
