#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    
    int i, n;
    n = 5;
    
    /* initialiser le generateur de nombres aleatoires */
    // !!!!!!! mettre le générateur en dehors de la boucle !
    srand((unsigned) time(NULL));
    
    /* afficher 5 nombres entiers aleatoires compris 0 et 49 */
    for( i = 0 ; i < n ; i++ ) {
        printf("%d\n", rand() % 50);
    }
    return(0);
}
