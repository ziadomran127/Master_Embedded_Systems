#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n , rem  , reverse;
    scanf("%d" , &n) ;

    while (n!=0)
    {
        rem=n%10 ;
       reverse = reverse*10 + rem ;
        n=n/10 ;
    }
    printf("%d" , reverse);
    
}