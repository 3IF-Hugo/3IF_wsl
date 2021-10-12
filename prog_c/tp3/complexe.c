#include <stdio.h>

typedef struct
{
	float reel;
	float im;
}complexe;

void affiche(complexe z)
{
	if(z.im>0)
		printf("%f%c%f%c%c\n",z.reel,'+',z.im,'*','i');
	if(z.im<0)
		printf("%f%c%f%c%c\n",z.reel,'-',z.im,'*','i');
	if(z.im ==0)
		printf("%f\n",z.reel);
}

complexe ajoute(complexe z1, complexe z2)
{
	complexe z;
	z.reel = z1.reel + z2.reel;
	z.im = z1.im + z2.im;
	return z;
}

complexe multiplie(complexe z1, complexe z2)
{
	complexe z;
	z.reel = z1.reel*z2.reel - z1.im*z2.im;
	z.im = z1.reel*z2.im + z2.reel*z1.im;
	return z;
}



int main()
{
	complexe c1;
	complexe c2;
	complexe cAjoute;
	complexe cProduit;
	scanf("%f", &c1.reel);
	scanf("%f", &c1.im);
	
	scanf("%f", &c2.reel);
	scanf("%f", &c2.im);
	
	cAjoute = ajoute(c1,c2);
	cProduit = multiplie(c1,c2);

	affiche(cAjoute);
	affiche(cProduit);
}
	

