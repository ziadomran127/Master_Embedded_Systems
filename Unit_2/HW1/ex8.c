#include<stdio.h>
#include<stdlib.h>


void swap_arithmetic(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main() {
    int a = 5, b = 10;
   
    swap_arithmetic(&a, &b);
    printf("After swapping using arithmetic operations: a = %d, b = %d\n", a, b);
    return 0;
}