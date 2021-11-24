#include <stdio.h>

void remplacer(FILE* fileOut, long offset, int k);

int nbLines(FILE* stream);

int main(int argc, char * argv[])
{
    int i,j;
    char caract='_';
    FILE* fichierOut = NULL;
    fichierOut = fopen(argv[1], "w");
    //int caractereActuel = fgetc(fichierOut);
    //int caractereActuel;
    char caractOut;
    char k;
    long offset;
    
    for(i=0;i<20;i++)
    {
            for(j=0;j<40;j++)
            {
                fputc(caract,fichierOut);
            }
            fputc('\n',fichierOut);
    }
    //fseek(fichierOut, 0, SEEK_SET);
    //rewind(fichierOut);
    //printf("le nombre de lignes : %d",nbLines(fichierOut));
    fclose(fichierOut);
    
    while (1)
    {
        FILE* fichierALire;
        fichierALire = fopen(argv[1],"r");
        int caractereActuel = fgetc(fichierALire);
        do
        {
            fputc(caractereActuel,stdout);
            caractereActuel = fgetc(fichierALire); // On lit le caractère
        } while (caractereActuel != EOF);

        fclose(fichierALire);

        scanf(" %c", &k);
        if(k == 'q')
        {
            break;
        }
        scanf(" %ld", &offset);
        
        FILE* fileOut;
        fileOut = fopen(argv[1],"r+");
        remplacer(fileOut, offset, (int) k);
        fclose(fileOut);
    }
    return 0;
}

int nbLines(FILE* stream)
{
    int cpt=0;
    while (feof(stream)==0)
    {
        if(fgetc(stream) == '\n')
            cpt++;
    }
}

void remplacer(FILE* fileOut, long offset, int k)
{
    fseek(fileOut, offset, SEEK_SET);
    if(fgetc(fileOut) == '\n'&& offset<=820)
    {
        fseek(fileOut, offset+1, SEEK_SET);
        fputc(k, fileOut);
        //fputc('\n',fileOut);
    }else
    {
        fseek(fileOut, offset, SEEK_SET);
        fputc(k, fileOut);
    }
}