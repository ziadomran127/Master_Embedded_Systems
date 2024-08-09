#include<stdio.h>
#include<stdlib.h>
int main()
{
    int arr[50] ;
    int n ;
    scanf("%d" , &n) ;
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d" , &arr[i]) ;
    }

    int *ptr = arr+n-1 ;

    for(int i=0 ; i <n ; i++)
    {
        printf("%d  " , *ptr);
        ptr--;
    }






}