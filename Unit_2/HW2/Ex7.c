#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n , fact=1 ;
    scanf("%d" , &n) ;
    if ( n > 0 ) 
    {
        while ( n!=0 )
        {
            fact = fact*n ;
            n--;
        }
        printf("%d" , fact) ;
    }
    else
    printf(" there is no factorial of negative nums") ;
}