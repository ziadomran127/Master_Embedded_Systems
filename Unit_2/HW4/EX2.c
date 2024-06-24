#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int fact(int n) ;

int main()
{
int n ;
scanf("%d" , &n) ;
int num = fact(n);
printf("%d" , num) ; 
}

int fact(int n)
{
    if (n==1)
    {
        return 1 ;
    }
    else
    {
        return n * fact(n-1) ;
    }
}