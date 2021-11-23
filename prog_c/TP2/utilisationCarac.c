#include <stdio.h>
#include <string.h>
int main()
{
	int i;
	char my_string[] = "<-_->";
	char *myString = "<-_->";
	printf("%ld\n", strlen(myString));
	for(i=0;i<strlen(my_string);i++)
	{
		//printf("%c.",my_string[i]);
		printf("%c ",myString[i]);
	}
	printf("\n");
	return 0;
}