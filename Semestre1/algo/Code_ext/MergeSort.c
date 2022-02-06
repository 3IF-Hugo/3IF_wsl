#include <stdio.h>

void merge(int a[], int start, int middle, int end) {
  int size_of_temp1, size_of_temp2, i, j, k;

  //temporary arrays to copy the elements of subarray
  size_of_temp1 = (middle-start)+1;
  size_of_temp2 = (end-middle);

  int temp1[size_of_temp1], temp2[size_of_temp1];

  for(i=0; i<size_of_temp1; i++) {
    temp1[i] = a[start+i];
  }

  for(i=0; i<size_of_temp2; i++) {
    temp2[i] = a[middle+1+i];
  }

  i=0;
  j=0;
  k=start;

  while (i < size_of_temp1 && j < size_of_temp2) {
    if (temp1[i] < temp2[j]) {
      // filling the main array with the smaller element
      a[k] = temp1[i];
      i++;
    }
    else {
      // filling the main array with the smaller element
      a[k] = temp2[j];
      j++;
    }
    k++;
  }

  // copying leftovers
  while (i<size_of_temp1) {
    a[k] = temp1[i];
    k++;
    i++;
  }

  while (j<size_of_temp2) {
    a[k] = temp2[j];
    k++;
    j++;
  }
}

void merge_sort(int a[], int start, int end) {
  if (start < end) {
    int middle = (start+end)/2;
    merge_sort(a, start, middle);
    merge_sort(a, middle+1, end);
    merge(a, start, middle, end);
  }
}

int main() {
  int a[] = {4, 8, 1, 3, 10, 9, 2, 11, 5, 6};
  merge_sort(a, 0, 9);

  //printing array
  int i;
  for(i=0; i<10; i++) {
    printf("%d ",a[i]);
  }
  printf("\n");
  return 0;
}