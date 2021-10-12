#include <stdio.h>
#include <float.h>

int main () {
   printf("The maximum value of float = %.10e\n", FLT_MAX);
   printf("The minimum value of float = %.10e\n", FLT_MIN);

   printf("la taille mémoire du long double = %ld\n", sizeof(long double));
   printf("la taille mémoire du long long = %ld\n", sizeof(long long));
}

