#include <stdio.h>
#include <string.h>

int main() {
    char dest[7]="Hello";
    char src[7]="World";
    strncat(dest,src,10);
    printf("%s\n",dest);
    strncat(dest,src,2);
    printf("%s\n",dest);
return 0;
}
