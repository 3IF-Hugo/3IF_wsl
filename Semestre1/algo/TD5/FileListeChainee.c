#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 100

typedef struct Element {
  int valeur; 
  struct Element *next;
} Element;

typedef struct{
  Element *debut;
  Element *fin;
}File;

/* Init allocates the structure File
 and
 * also the membre array with the given size 
 * it also fill allocated (size) and intializes 
 * filled to 0 */
File * Init();

Element * InitBis();

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
void Destroy(File * file);

int main(void) 
{
  char lecture[100];
  int val;
  int res=0;
  File * file;
  file = Init();

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

File * Init()
{
  File * file = (File*) malloc(sizeof(File));
  file->debut = NULL;
  file->fin = NULL;
  return file;
}

void InsertValue(File * file, int value)
{
    Element * element = (Element*) malloc(sizeof(Element));
    element->valeur = value;
    element->next=NULL;
    if(file->debut == NULL)
    {
        file->debut= element;
        file->fin=element;
    }else{
        file->fin->next=element;
        file->fin = file->fin->next;
    }
}

int ExtractMax(File * file, int *res)
{
    if(file->fin == NULL)
    {
      return 0;
    }
    Element * elem = (Element*) malloc(sizeof(Element));
    elem = file->debut; 
    *res = elem->valeur;
    file->debut=file->debut->next;
    free(elem);
    return 1;
}

void Destroy(File * file)
{
  free (file);
}