 #include <stdio.h>
 #define MAX 100000
 #define min(a, b) (((a) < (b)) ? (a) : (b))

// int max(int tab[], int tailleTab)
// {
//     int i;
//     int max =0;
//     for(i=0; i<tailleTab; i++)
//     {
//         if(tab[i] > max)
//         {
//             max = tab[i];
//         }
//     }
//     return max;
// }

// int min(int a, int b)
// {
//     if(a<=b)
//     {
//         return a;
//     }else
//     {
//         return b;
//     }
// }

// void sacADos(int taille, int nObjets, int tObjets[])
// {
//     int res[taille+1];
//      res[0] = 1;
//      int i,j;
//      for(i=1; i<=taille; i++)
//      {
//          for(j=0; j<nObjets; j++)
//          {
//              if(i - tObjets[j] >= 0 && res[i-tObjets[j]] == 1)
//              {
//                  res[i] = 1;
//                  break;
//              }else
//              {
//                  res[i] = 0;
//              }
//          }
//      }
//      int maxi = max(tObjets, nObjets);
     
// }

int sacADosCoinChange(int taille, int nObjets, int tObjets[])
{
    int res[taille+1];
    res[0] = 0;
    int i,j;
     //Traitement = on checher le minimum de pièce de façon itérative
     for(i = 1; i <= taille; i++)
     {
         int minimum = MAX;
         for(j = 0; j < nObjets; j++)
         {
             if(tObjets[j] <= i)
             {
                 minimum = min(minimum, 1+res[i-tObjets[j]]);
             }
         }
         res[i] = minimum;
     }
     //debug
    //  for(i=0; i<=taille; i++)
    //  {
    //      printf("%d ", res[i]);
    //  }
    //  printf("\n");
     return res[taille];
     
}

 int main()
 {
     int taille, nObjets, i;

     scanf("%d", &nObjets);
     
     int tObjets[nObjets];
     
     for(i = 0; i < nObjets; i++)
     {
         scanf("%d", &tObjets[i]);
     }
     
     scanf("%d", &taille);
     
     int res = sacADosCoinChange(taille, nObjets, tObjets);
     
     printf("%d\r\n", res);
     return 0;
 }