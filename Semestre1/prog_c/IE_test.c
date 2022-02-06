#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define tailleMax 30

typedef struct 
{
    char *mot;
    //char mot[tailleMax];
}mot_fr_t;

typedef struct
{           
    int valeur;
    int *precedent;
    int* next;
}dbl_list;


long set_bit(long bitfield, int numbit)
{
    int res = 0;
    long tmp = bitfield;
    for(int i=0; i <= numbit; i++)
    {
        res = tmp % 10;
        tmp = tmp/10;
    }
    bitfield = bitfield -(res - 1)*pow(10, numbit);
    return bitfield;
}

int estfactgauch(mot_fr_t *facteurg, mot_fr_t *src)
{
    int i=0;
    while(facteurg->mot[i] != '\0')
    {
        printf("%c\n", facteurg->mot[i]);
        if(facteurg->mot[i] != src->mot[i])
        {
            return 0;
        }
        i++;
    }
    return 1;
}

char *readN(int n, char* nom)
{
    FILE *file = fopen(nom, "r");
    char *s = (char*) malloc(200*sizeof(char));
    for(int i=0; i<n; i++)
    {
        fgets(s, 200, file);
    }
    fgets(s, 200, file);
    return s;
}

int concat(char *nomFichierAll, char *nomFichier1, char *nomFichier2)
{
    FILE *fileOut = fopen(nomFichierAll, "w");
    FILE *fileIn1 = fopen(nomFichier1, "r");
    FILE *fileIn2 = fopen(nomFichier2, "r");
    char *s = (char*) malloc(200*sizeof(char));
    while(feof(fileIn1) != EOF)
    {
        fputs(fgets(s, 200, fileIn1), fileOut);
    }
    while(feof(fileIn2) != EOF)
    {
        fputs(fgets(s, 200, fileIn2), fileOut);
    }
    fputc('\0', fileOut);
    return 2;
}

int * createArray(int initvalue, int *tab)
{
    int i =0;
    for(i=0; i<20; i++)
    {
        tab[i] = initvalue;
    }
    return tab;
}

// char *readNiemeLigne(int numberL, char* nom)
// {
//     int cptligne=0;
//     char * ligne=(char *)malloc(100*sizeof(char));
//     while (cptligne != numberL){
//         fgets(ligne,99,nom);
//         cptligne++;
//     }
//     return ligne;
// }

void octetParOctet(unsigned int param)
{
    for(int i=0; i<sizeof(param); i++)
    {
        printf("%x\n", (param >> i*4) & 0x0F);
    }
}

int main(int argc, char * argv[])
{
    // char x = 'e';
    // int i = x - 200;
    // printf("%d\n", i);
    // printf("%x\n",0x53835);
    // printf("%c\n",x);

    // long test = 1234;
    // test = set_bit(test, 3);
    // printf("%ld\n", test);

    // int tab[] = {3,5,7,9,11,13,15,17,19};
    // int *p;
    // p = tab;
    // printf("%p\n", p);
    // printf("%d\n", tab[5]-3);

    // int A = 2;
    // int B = 4;
    // int C = 8;
    // printf("les adresses à check");
    // printf("A : %p, B : %p, C : %p\n", &A, &B, &C);
    // int *P1, *P2 , *P3 ;
    // P1=&A;
    // printf("A : %d, B : %d, C : %d\n", A, B, C);
    // P2=&C;
    // printf("A : %d, B : %d, C : %d\n", A, B, C);
    // P3 = P1++;
    // printf("A : %d, B : %d, C : %d\n", A, B, C);
    // *P1= (*P2 )++;
    // printf("A : %d, B : %d, C : %d\n", A, B, C);
    // P1=P2 ;
    // printf("A : %d, B : %d, C : %d\n", A, B, C);
    // P2=&B;
    // printf("A : %d, B : %d, C : %d\n", A, B, C);
    // *P1 -= *P3 ;
    // printf("A : %d, B : %d, C : %d\n", A, B, C);
    // ++*P2 ;
    // printf("A : %d, B : %d, C : %d\n", A, B, C);
    // *P3*=*P2 ;
    // printf("A : %d, B : %d, C : %d\n", A, B, C);
    // A=++*P2**P1 ;
    // printf("A : %d, B : %d, C : %d\n", A, B, C);
    // P1=&A;
    // printf("A : %d, B : %d, C : %d\n", A, B, C);
    // *P2=*P1/=*P2 ;
    // printf("A : %d, B : %d, C : %d\n", A, B, C);

    // printf("Fin affichage et suite :");
    // printf("P1 : %p, P2 : %p, P3 : %p\n", P1, P2, P3);
    // printf("A : %d, B : %d, C : %d\n", A, B, C);

    // int tab[20];
    // int *res;
    // res = createArray(0, tab);
    // for(int i=0; i<20; i++)
    // {
    //     printf("%d ",tab[i]);
    // }

    // char c = 0x12;
    // int i = 42;
    // int itab[6] = {0, 11, 22, 33, 44, 55};
    // int* p1;
    // char* ctab ="chai";

    // int tailleC = sizeof(c);
    // printf("%d\n", tailleC);

    // int tailleI = sizeof(i);
    // printf("%d\n", tailleI);

    // int tailletab = sizeof(itab);
    // printf("%d\n", tailletab);

    // int taillep1 = sizeof(p1);
    // printf("%d\n", taillep1);

    // int taillectab = sizeof(ctab);
    // printf("%d\n", taillectab);

    //     printf("\n %ld octets pour adresse vers variable de type char ",sizeof(char * ));

    // printf("\n %ld octets pour adresse vers variable de type unsigned char ",sizeof(unsigned char * ));

    // printf("\n %ld octets pour adresse vers variable de type short_int ",sizeof(short int * ));

    // printf("\n %ld octets pour adresse vers variable de type int ",sizeof(int *));

    // printf("\n %ld octets pour adresse vers variable de type long int ",sizeof(long int *));

    // printf("\n %ld octets pour adresse vers variable de type float ",sizeof(float *));

    // printf("\n %ld octets pour adresse vers variable de type double ",sizeof(double *));

    //printf("\n %ld octets pour taille d'une structure ",sizeof(mot_fr_t * ));

    // unsigned int valeur = 1024;
    // octetParOctet(valeur);

    // mot_fr_t *facteurG = (mot_fr_t*) malloc(sizeof(mot_fr_t));
    // mot_fr_t *src = (mot_fr_t*) malloc(sizeof(mot_fr_t));

    // facteurG->mot = "diction";
    // src->mot = "dictionnaire";

    // printf("%d\n", estfactgauch(facteurG, src));

    //printf("%s\n", readN(2,argv[1]));

    concat(argv[1], argv[2], argv[3]);






















    return 0;
}

