#include <stdio.h>

// function to swap values of two variables
void swap(int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int a[], int start, int end) {
  int pivot = a[end];
  int i = start-1;
  int j;

  for(j=start; j<=end-1; j++) {
    if(a[j]<=pivot) {
      i=i+1;
      swap(&a[i], &a[j]);
    }
  }
  swap(&a[i+1], &a[end]);
  return i+1;
}

void quicksort(int a[], int start, int end) {
  if(start < end) {
    int q = partition(a, start, end);
    quicksort(a, start, q-1);
    quicksort(a, q+1, end);
  }
}

int main() {
  int a[] = {4, 8, 1, 3, 10, 9, 2, 11, 5, 6};
  quicksort(a, 0, 9);

  //printing array
  int i;
  for(i=0; i<10; i++) {
    printf("%d ",a[i]);
  }
  printf("\n");
  return 0;
}