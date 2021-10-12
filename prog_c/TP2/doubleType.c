#include <stdio.h>
 
int main(){
	double d= 13.12;
	double *ptr_d;
	ptr_d = &d;
	printf("d = %lf\n",d);
	printf("l'adresse de d = %p\n",&d);
	printf("ptr_d = %lf\n",*ptr_d);
	printf("adresse de ptr_d = %p\n",ptr_d);
	*ptr_d=4.5;
	printf("d = %lf\n",d);
return 0;
}