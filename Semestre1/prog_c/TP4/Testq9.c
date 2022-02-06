#include <stdio.h>

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
    FILE* fichier = NULL;
    fichier = fopen(argv[1], "r");
    int res = nbLines(fichier);
    printf("le nombre de lignes : %d\n",res);
    fclose(fichier);
    return 0;
}