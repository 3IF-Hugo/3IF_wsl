#include <stdio.h>

// function to swap values of two variables
void swap(int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void bubble_sort(int a[], int size) {
  int i, j;
  for(i=0; i<size; i++) {
    for(j=0; j<size-i-1; j++) {
      if (a[j] > a[j+1]) {
        swap(&a[j], &a[j+1]);
      }
    }
  }
}

int main() {
  int a[] = {4, 8, 1, 3, 10, 9, 2, 11, 5, 6};
  bubble_sort(a, 10);

  //printing array
  int i;
  for(i=0; i<10; i++) {
    printf("%d ",a[i]);
  }
  printf("\n");
  return 0;
}