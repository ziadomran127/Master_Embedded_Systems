#include<stdio.h>
#include<stdlib.h>

struct S_Complex
{
   float real ; 
   float imaginary;
} n1 , n2 , sum ;


int main()
{
    printf("For 1st Complex Number : \n") ;
    printf("Enter real and imaginary respectively : ") ;
    scanf("%f %f" , &n1.real , &n1.imaginary) ;

    
    printf("For 2nd Complex Number : \n") ;
    printf("Enter real and imaginary respectively : ") ;
    scanf("%f %f" , &n2.real , &n2.imaginary) ;

    sum.real = n1.real + n2.real ;
    sum.imaginary = n1.imaginary + n2.imaginary ;

    printf("Sum = %0.2f + %0.2f i" , sum.real , sum.imaginary) ;
}