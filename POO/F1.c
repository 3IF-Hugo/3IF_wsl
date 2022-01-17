#include <stdio.h>

int Modifie();
int i;
int j=0;

int main()
{
    i=1;
    printf("i (main 1) = %d\n", i);
    j = Modifie();
    printf("i (main 2) = %d\n", i);
    printf("j (main 2) = %d\n", j);

    return 0;
}