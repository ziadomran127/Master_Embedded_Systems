#include<stdio.h>
#include<stdlib.h>
int main()
{
    int m = 29 ;
    int *ab = &m ;
    printf("address of m : %d \n" , ab) ;
    printf("value of m : %d \n" , *ab) ;
    printf("\n");

    printf("address of pointer ab : %d \n" , ab) ;
    printf("value of pointer ab : %d \n" ,  *ab) ;
    printf("\n");
    m = 34 ;


    printf("address of pointer ab : %d \n" , ab) ;
    printf("value of pointer ab : %d \n" ,  *ab) ;
     printf("\n");  
    *ab = 7 ;
     printf("address of m : %d \n" , ab) ;
    printf("value of m : %d \n" , *ab) ;


}