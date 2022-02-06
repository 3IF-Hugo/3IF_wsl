#include <stdio.h>
#include <math.h>

int myAtoi(char* str)
{
    // Initialize result
    int res = 0;
 
    // Iterate through all characters
    // of input string and update result
    // take ASCII character of corresponding digit and
    // subtract the code from '0' to get numerical
    // value and multiply res by 10 to shuffle
    // digits left to update running total
    for (int i = 0; str[i] != '\0'; ++i)
        res = res * 10 + str[i] - '0';
 
    // return result.
    return res;
}

// int atoi(const char *s1,int taille){
//         int i=0;
// 	int j=0;
// 	int tab[taille];
// 	int res=0;

// 	for(i=0;i<taille;i++)
//         {
// 		switch(s1[i])
// 		{
// 			case 48: tab[i]=0;break;
// 			case 49: tab[i]=1;break;
// 			case 50: tab[i]=2;break;
// 			case 51: tab[i]=3;break;
// 			case 52: tab[i]=4;break;
// 			case 53: tab[i]=5;break;
// 			case 54: tab[i]=6;break;
// 			case 55: tab[i]=7;break;
// 			case 56: tab[i]=8;break;
// 			case 57: tab[i]=9;break;
// 		}
//         }
// 	for(j=0;j<taille;j++)
// 		res = res + tab[j]*pow(10,taille-j-1);

// return res;
// }

int length(const char *s1){
	int cpt=0;
	while(s1[cpt]!=0){		
		cpt++;
	}
return cpt;
}

int main()
{ 
	char my_string1[] = "4562";
	int taille  = length(my_string1);
	int resultat =0; 
	//resultat = atoi(my_string1, taille);
	resultat = myAtoi(my_string1);
	printf("Transformation chaine caract en un entier : %d\n",resultat);
return 0;
}