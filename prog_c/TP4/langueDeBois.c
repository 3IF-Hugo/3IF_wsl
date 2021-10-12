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

void lectureLigneAlea(FILE* stream, int numberL)
{
    int cptligne=0;
    char * ligne=(char *)malloc(100*sizeof(char));
    while (cptligne != numberL){
        fgets(ligne,99,stream);
        cptligne++;
    }

    fputs(ligne,stdout);
    free(ligne);
}

int main(int argc, char * argv[])
{
    int i;
    char str[200];
    srandom(time(NULL)); // initialisation de la graine d’aléa
    
    for(i=1;i<argc;i++)
    {
        
        FILE* fichier = NULL;
        fichier = fopen(argv[i], "r");
        
        int nbline = nbLines(fichier); 
        
        long tirage = random()%nbline;
        //printf("nb aléa %ld\n",tirage);
        lectureLigneAlea(fichier, tirage);
        fclose(fichier);
    }
}