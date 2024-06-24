#include<stdio.h>
#include<stdlib.h>

int CLR_BIT(int n , int bit) ;

int main()
{
    int n , bit ;
    scanf("%d" , &n ) ;
    scanf("%d" , &bit);
    printf("%d" , CLR_BIT(n , bit)) ;

}

int CLR_BIT(int n , int bit) 
{
    return n &= ~(1<<bit) ;
}
