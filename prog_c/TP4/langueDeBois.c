#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int nbLines(FILE* stream)
{
    int posCourante = ftell(stream);
    int cpt=0;
    while (feof(stream)==0)
    {
        if(fgetc(stream) == '\n')
            cpt++;
    }
    fseek(stream, posCourante, SEEK_SET);
    return cpt;
}

int main(int argc, char * argv[])
{
    int i;

    for(i=1;i<argc+1;i++)
    {
        char str[200];
        FILE* fichier = NULL;
        fichier = fopen(argv[i], "r");
        
        int nbline = nbLines(fichier); 
        
        srandom(time(NULL)); // initialisation de la graine d’aléa
        long tirage = random() % nbline;

        fgets(str,200,fichier);
        fputs(str,stdout);

    }
}