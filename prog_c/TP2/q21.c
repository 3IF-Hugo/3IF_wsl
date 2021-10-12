#include <stdio.h>

int TP_strcmp(const char *s1, const char *s2){
	int i=0;
	while(s1[i]!=0 || s2[i]!=0)
	{
		if(s1[i]<s2[i])
			return -1;
		if(s1[i]>s2[i])
			return 1;
		if(s1[i]==s2[i])
		{
			i++;
			continue;
		}
	i++;
	}
	return 0;
}
int main()
{
        char my_string1[] = "Toto";
        char my_string2[] = "toto";
	printf("comparaison de chaines de caractères : %d\n",TP_strcmp(my_string2, my_string1));
	
return 0;
}