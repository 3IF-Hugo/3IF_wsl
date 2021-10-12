#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char** argv){
	int i=0;
	printf("le nombre de param passés : %d\n",argc);
	for(i=0;i<argc;i++)
		printf("%s\n",argv[i]);

return 0;
}