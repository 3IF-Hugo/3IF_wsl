#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int allocated; /* current allcoation of array */
  int filled;    /* number of items present in the binheap */
  int *array;    /* array of values */
} BinaryHeap;

/* Init allocates the structure BinaryHeap and
 * also the membre array with the given size 
 * it also fill allocated (size) and intializes 
 * filled to 0 */
BinaryHeap * Init(int size);

/* InsertValue insert value into the binary heap
 * the array is reallocated if necessary (allocated changed 
 * with respect to the new size )
 * filled is incremented by 1 */
void InsertValue(BinaryHeap * heap, int value);

/* ExtractMAx returns 0 if the binary heap is empty
 * otherwise it return 1 and fills *val with the maximum 
 * value present in the binary heap
 * filled is decremented by 1  and the max value is removed
 * from the binary heap */
int ExtractMax(BinaryHeap * heap, int * val);

/* Destroy frees the structure and the array */
void Destroy(BinaryHeap * heap);

void Print(BinaryHeap * heap);

int main(void) 
{
  char lecture[100];
  int val;
  BinaryHeap * heap;
  heap = Init(10);

  fscanf(stdin,"%99s",lecture);
  while (strcmp(lecture,"bye")!=0) {
    if (strcmp(lecture,"insert")==0) {
      fscanf(stdin,"%99s",lecture);
      val = strtol(lecture,NULL,10);
      InsertValue(heap,val);
    } else if (strcmp(lecture,"extract")==0) {
      if(ExtractMax(heap,&val))
      {
        printf("%d\r\n",val);
      }
    }
   //Print(heap);
    fscanf(stdin,"%99s",lecture);
  }
  Destroy(heap);
  return 0;
}

BinaryHeap * Init(int size)
{
  BinaryHeap * heap;
  heap = (BinaryHeap*) malloc(sizeof(BinaryHeap));
  heap->allocated = size;
  heap->filled = 0;
  heap->array = (int*) malloc(sizeof(int)*size);
  return heap;
}

void Swap(int *a, int *b) {
   int tmp;
   tmp = *a;
   *a = *b;
   *b = tmp;
}

#define swap(x,y) int _tmp;_tmp=(x);(x)=(y);(y)=_tmp

void InsertValue(BinaryHeap * heap, int value)
{
   if (heap->filled==heap->allocated) 
   {
      heap->allocated*=2;
      heap->array = (int*) realloc(heap->array,sizeof(int)*heap->allocated);
   }
   int * a = heap->array;
   int fils = heap->filled;
   int pere = (fils-1)/2;
   a[fils] = value;
   while (pere>=0 && a[fils]>a[pere]) {
      swap(a[pere], a[fils]);
      /*Swap(&(a[pere]), &(a[fils]));*/
      /*int tmp = a[fils];
      a[fils] = a[pere];
      a[pere] = tmp;*/
      fils = pere;
      pere = (fils-1)/2;
   }
   heap->filled++;
}

void Print(BinaryHeap * heap) {
   printf("Allocated : %d\n",heap->allocated);
   printf("Filled    : %d\n",heap->filled);
   int i;
   for (i=0;i<heap->filled;i++) {
      printf("  %d",heap->array[i]);
   }
   printf("\n");
}

int ExtractMax(BinaryHeap * heap, int *res)
{
   if (heap->filled==0)
      return 0;
   int * a = heap->array;
   *res = a[0];
   heap->filled--;
   a[0] = a[heap->filled];
   int pere = 0;
   int g = 1;
   int d = 2;
   while ((g<heap->filled && a[g]>a[pere]) || (d<heap->filled && a[d]>a[pere])) {
      int iswap = g;
      if (d<heap->filled && a[d]>a[g]) {
         iswap = d;
      }
      int tmp = a[iswap];
      a[iswap] = a[pere];
      a[pere] = tmp;
      pere = iswap;
      g = pere*2+1;
      d = pere*2+2;
   }
   return 1;
}

void Destroy(BinaryHeap * heap)
{
   free(heap->array);
   free(heap);
}
