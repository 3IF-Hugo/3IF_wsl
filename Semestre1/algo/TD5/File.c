#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 100

typedef struct {
  int debut; 
  int fin;   
  int taille;
  int *tab;
} File;

/* Init allocates the structure File
 and
 * also the membre array with the given size 
 * it also fill allocated (size) and intializes 
 * filled to 0 */
File * Init(int size);

/* InsertValue insert value into the binary File
 * the array is reallocated if necessary (allocated changed 
 * with respect to the new size )
 * filled is incremented by 1 */
void InsertValue(File * file, int value);

/* ExtractMAx returns 0 if the binary file is empty
 * otherwise it return 1 and fills *val with the maximum 
 * value present in the binary file
 * filled is decremented by 1  and the max value is removed
 * from the binary file */
int ExtractMax(File * file, int *res);

/* Destroy frees the structure and the array */


int main(void) 
{
  char lecture[100];
  int val;
  int res=0;
  File * file;
  file = Init(TAILLE);

  fscanf(stdin,"%99s",lecture);
  while (strcmp(lecture,"bye")!=0) {
    if (strcmp(lecture,"queue")==0) {
      fscanf(stdin,"%99s",lecture);
      val = strtol(lecture,NULL,10);
      InsertValue(file,val);
    } else if (strcmp(lecture,"dequeue")==0) {
      if(ExtractMax(file,&res))
      {
        printf("%d\r\n",res);
      }
    }
    fscanf(stdin,"%99s",lecture);
  }
  Destroy(file);
  return 0;
}

File * Init(int size)
{
  File * file = (File*) malloc(sizeof(File));
  file->debut = 0;
  file->fin=0;
  file->tab = (int*) malloc(sizeof(int)*size);
  return file;
}

void InsertValue(File * file, int value)
{
    file->tab[file->fin] = value;
    file->fin++;
    if(file->fin == TAILLE)
        file->fin=0;
}

int ExtractMax(File * file, int *res)
{
    if(file->debut == file->fin)
    {
        return 0;
    }
    *res = file->tab[file->debut];
    file->debut++;
    if(file->debut==TAILLE)
    {
        file->debut=0;
    }
    return 1;
}

void Destroy(File * file)
{
  free (file->tab);
  free (file);
}