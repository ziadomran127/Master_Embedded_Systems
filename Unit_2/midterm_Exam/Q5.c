#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n ; 
    scanf("%d" , &n) ;

    unsigned int count = 0 ;
    while (n!=0)
    {
        count += n & 1;
        n = n >> 1;
    }
    printf("%d" , count) ;
    
}