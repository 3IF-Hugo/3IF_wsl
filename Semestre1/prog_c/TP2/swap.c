#include <stdio.h>

void swap(int *a, int *b)
{
    // printf("Dans swap, a = %d\n", *a);
    // printf("b = %d\n", *b);
    int c = *a;
    *a = *b;
    *b = c;
    // printf("a = %d\n", *a);
    // printf("b = %d\n", *b);
}

int main(){
    int a = 10;
    int *ptr_a = &a;
    
    int b = 5;
    int *ptr_b = &b;
    printf("dans main, a = %d\n", *ptr_a);
    printf("b = %d\n", *ptr_b);
    // printf("Dans main, adresse de a = %p\n", &a);
    // printf("et de b = %p\n", &b);
    // printf("Dans main, adresse de ptr a = %p\n", ptr_a);
    // printf("et de ptr b = %p\n", ptr_b);
    swap(ptr_a, ptr_b);
    printf("Re dans main, a = %d\n", *ptr_a);
    printf("b = %d\n", *ptr_b);
    return 0;
}