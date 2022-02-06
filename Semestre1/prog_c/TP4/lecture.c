#include <stdio.h>

int main(int argc, char * argv[])
{
    /*
    FILE* fichier = NULL;
    int caractereActuel = 0;
 
    fichier = fopen("text.txt", "r");
 
    if (fichier != NULL)
    {
        // Boucle de lecture des caractères un à un
        do
        {
            caractereActuel = fgetc(fichier); // On lit le caractère
            printf("%c", caractereActuel); // On l'affiche
        } while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
 
        fclose(fichier);
    }*/

    FILE* fichier = NULL;
    FILE* fichierOut = NULL;
 
    fichier = fopen(argv[1], "r");
    fichierOut = fopen(argv[2],"w");
    
    int caractereActuel = fgetc(fichier);

    if (fichier != NULL)
    {
        // Boucle de lecture des caractères un à un
        do
        {
            fputc(caractereActuel,fichierOut);
            caractereActuel = fgetc(fichier); // On lit le caractère
            fputc(caractereActuel,stdout);
        } while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
 
        fclose(fichier);
        fclose(fichierOut);
    }
 
    return 0;
}