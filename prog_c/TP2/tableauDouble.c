#include <stdio.h>

int main(){
	double tab[10] ={1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10};
        int i;
        double *ptr_tab = tab;
	void* ptr_voidmemo=tab;
	void* ptr_void;
	for(i=0;i<10;i++)
	{
                ptr_void= ptr_voidmemo +i;
		printf("valeur de tab = %f\n",*(double*)ptr_void);
	}
return 0;
}

