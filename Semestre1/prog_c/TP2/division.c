#include <stdio.h>
#include <assert.h>

double doublediv(double a, double b)
{
	assert(b!=0);
	double res = a/b;
return res;
}

int main(){
    double a=10.0;
	double b =11.0;
	double a1=13.0;
	double b1=-12.0;
	double a2=42.0;
	double b2=0;

	printf("résultat %f\n",doublediv(a1, b1));
	printf("résultat %f\n",doublediv(a2, b2));

return 0;
}
            
