#include<stdlib.h>
#include<stdio.h>
int main()
{
    int a[100] ;
    int b ;
    int n ;
    int l ;
    printf("Enter num of elements : ");
    scanf("%d" , &n) ;
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d " , &a[i]) ;
    }

    printf("enter the element to be inserted : ") ;
    scanf("%d " ,&b ) ;

    printf("enter the location : ") ;
    scanf("%d" , &l) ;

    a[l-1] =b ;

    for(int i=0 ; i<n ; i++)
    {
        printf("%d" , a[i]) ;
    }

}