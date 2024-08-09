#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n ;
    int result =0 ;
    
    scanf("%d" , &n) ;
    int a[100] ;

    for(int i=0 ; i<n ; i++)
    scanf("%d" , &a[i]) ;

    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            if( i!=j && a[i] ==a[j])
            break;
           
        }
    }

    printf("%d" , a[result]) ;




}