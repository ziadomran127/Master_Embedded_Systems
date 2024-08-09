#include<stdio.h>
#include<stdlib.h>

struct S_Distance 
{
    int feet ; 
    float inches ;
} d1 , d2 , sum ;

int main()
{
    printf("Enter information for 1st Distance : \n") ;

    printf("Enter Feet : ") ;
    scanf("%d" , &d1.feet) ;
    printf("\n") ;
    
    printf("Enter inches : ") ;
    scanf("%f" , &d1.inches) ;
    printf("\n") ;


    printf("Enter information for 2nd Distance : \n") ;

    printf("Enter Feet : ") ;
    scanf("%d" , &d2.feet) ;
    printf("\n") ;
    
    printf("Enter inches : ") ;
    scanf("%f" , &d2.inches) ;
    printf("\n") ;

    sum.feet = d1.feet + d2.feet ;
    sum.inches = d1.inches + d2.inches ;

    if(sum.inches >12) {
        sum.inches-=12.0 ;
        sum.feet++ ;
    }

    printf("Sum of Distance = %d '-%0.1f'  " , sum.feet , sum.inches) ;


}