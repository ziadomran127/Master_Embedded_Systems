#include<stdio.h>
#include<stdlib.h>


#define PI 3.14

int main() 
{
    int r ; 
    printf("Enter radius : ") ;
    scanf("%d" , &r) ;
    printf("Area = %0.2f" , PI*r*r ) ;

}