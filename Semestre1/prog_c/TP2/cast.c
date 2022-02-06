#include <stdio.h>

int main(){
        float var;
	float *ptr_var;
	void *ptr_gen;
	ptr_var=&var;
        printf("ptr_var = %ld\n",sizeof(ptr_var));
        printf("var = %ld\n",sizeof(var));
        printf("ptr_gen = %ld\n",sizeof(ptr_gen));
return 0;
}