#include <stdio.h>
#include <math.h>

char *itoa(int entier1){
	int i=0;
        int j=0;
        int res=0;

        switch(entier1)
                {
                        case 48: return "0";
                        case 49: return "1";
                        case 50: return "2";
                        case 51: return "3";
                        case 52: return "4"; 
                        case 53: return "5";
                        case 54: return "6";
                        case 55: return "7";
                        case 56: return "8";
                        case 57: return "9";
			default : return "-1";
                }
        }

int length(int t1){
	if(t1<10)
		return 1;
	if(t1>9 && t1<100)
		return 2;
	if(t1>99 && t1<1000)
		return 3;
	if(t1>999 && t1<10000)
		return 4;       
       
}

int main()
{
        int my_int = 55;
	char *testchar = "test";
        char *res=itoa(my_int);
        printf("Transformation entier en une chaine de carac : %s\n",res);
return 0;
}
