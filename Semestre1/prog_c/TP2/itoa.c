#include <stdio.h>
#include <math.h>
#define base 10

// void reverse(char str[], int length)
// {
//     int start = 0;
//     int end = length -1;
//     while (start < end)
//     {
//         swap(*(str+start), *(str+end));
//         start++;
//         end--;
//     }
// }

char* myItoa(int num, char *str)
{
    
    int i = 0;
    int isNegative = 0;
 
    /* Handle 0 explicitly, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
 
    // In standard itoa(), negative numbers are handled only with
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = 1;
        num = -num;
    }
 
    // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
        printf("rem : %d\n", rem);
        str[i++] = rem + '0';
        //str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }
 
    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';
 
    str[i] = '\0'; // Append string terminator
 
    // Reverse the string
    //reverse(str, i);
 
    return str;
}


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
        char str[100];
        int my_int = 2354;
	char *testchar = "test";
        char *res = myItoa(my_int, str);
        printf("Transformation entier en une chaine de carac : %s\n",res);
return 0;
}
