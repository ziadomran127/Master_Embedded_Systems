#include<stdlib.h>
#include<stdio.h>
int main()
{
    float a[100] ;
    int n ;
    float sum =0.0 ;
    int c = 0 ;
    printf("Enter the numbers of data : ") ;
    scanf("%d" , &n) ;
    printf("\n\r") ;
    for(int i=0 ; i<n ; i++ )
    {
        printf("%d. enter the number : " , i+1);
        scanf("%f" , &a[i] );

    }

    for(int i=0 ; i<n ; i++)
    {
        sum = sum +a[i] ;
        c++ ;
    }
    printf("%f" , sum/c) ;
}