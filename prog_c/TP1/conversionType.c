#include <stdio.h>
#include <stdlib.h>

int main(){
    int i = 4;
    float f = (float) i;
    char c = 100;
    int dc = (int) c;
    printf("i = %d \n", i);
    printf("f = %f \n", f);
    printf("c = %c \n", c);
    printf("dc = %d \n", dc);
    printf("4 / 5 = %f \n", (float)(4/5));
    printf("(float)4 / 5 = %f\n", (float)4 / (float)5);
    return 0;
}
